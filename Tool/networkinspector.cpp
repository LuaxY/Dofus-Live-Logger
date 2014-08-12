#include "networkinspector.h"
#include "ui_networkinspector.h"
#include <QCryptographicHash>
#include <QDataStream>
#include <QDebug>

NetworkInspector::NetworkInspector(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::NetworkInspector)
{
    ui->setupUi(this);
    setFixedSize(width(), height());

    serverDofus = new QTcpServer(this);
    connect(serverDofus, SIGNAL(newConnection()), this, SLOT(onDofusConnected()));
    serverDofus->listen(QHostAddress::Any, 4444);

    serverWeb = new QWebSocketServer("logger", QWebSocketServer::NonSecureMode, this);
    connect(serverWeb, SIGNAL(newConnection()), this, SLOT(onWebConnected()));
    serverWeb->listen(QHostAddress::Any, 4242);
}

NetworkInspector::~NetworkInspector()
{
    delete serverDofus;
    delete serverWeb;
    delete ui;
}

void NetworkInspector::onDofusConnected()
{
    clientDofus = serverDofus->nextPendingConnection();
    connect(clientDofus, SIGNAL(readyRead()), this, SLOT(onReceiveFromDofus()));
    connect(clientDofus, SIGNAL(disconnected()), this, SLOT(onDofusDisconnected()));

    ui->dofus->setStyleSheet("background-image: url(:/images/dofus_on.png);");
}

void NetworkInspector::onDofusDisconnected()
{
    clientDofus->close();
    ui->dofus->setStyleSheet("background-image: url(:/images/dofus_off.png);");
}

void NetworkInspector::onWebConnected()
{
    clientWeb = serverWeb->nextPendingConnection();
    connect(clientWeb, SIGNAL(textMessageReceived(QString)), this, SLOT(onWebTextMessage(QString)));
    connect(clientWeb, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(onWebBinaryMessage(QByteArray)));
    connect(clientWeb, SIGNAL(disconnected()), this, SLOT(onWebDisconnected()));

    ui->logger->setStyleSheet("background-image: url(:/images/logger_on.png);");
}

void NetworkInspector::onWebDisconnected()
{
    clientWeb->close();
    ui->logger->setStyleSheet("background-image: url(:/images/logger_off.png);");
}

void NetworkInspector::onReceiveFromDofus()
{
    QByteArray message = clientDofus->readAll();

    if(message.indexOf("]]></showMessage>") == -1)
    {
        buffer.append(message);
        return;
    }

    message.replace("!SOS<showMessage key=\"trace\"><![CDATA[", "<li class=\"trace\">");
    message.replace("!SOS<showMessage key=\"debug\"><![CDATA[", "<li class=\"debug\">");
    message.replace("!SOS<showMessage key=\"info\"><![CDATA[", "<li class=\"info\">");
    message.replace("!SOS<showMessage key=\"warning\"><![CDATA[", "<li class=\"warning\">");
    message.replace("!SOS<showMessage key=\"error\"><![CDATA[", "<li class=\"error\">");
    message.replace("!SOS<showMessage key=\"fatal\"><![CDATA[", "<li class=\"fatal\">");
    message.replace("]]></showMessage>", "</li>");

    if(buffer.length() > 0)
    {
        buffer.append(message);
        clientWeb->sendTextMessage(buffer.data());
        buffer.clear();
    }
    else
        clientWeb->sendTextMessage(message.data());
}

void NetworkInspector::onWebTextMessage(QString message)
{
    clientWeb->sendTextMessage(message);
}

void NetworkInspector::onWebBinaryMessage(QByteArray data)
{
    clientWeb->sendBinaryMessage(data);
}

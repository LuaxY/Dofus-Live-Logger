#ifndef NETWORKINSPECTOR_H
#define NETWORKINSPECTOR_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QWebSocketServer>
#include <QWebSocket>

namespace Ui {
class NetworkInspector;
}

class NetworkInspector : public QWidget
{
    Q_OBJECT

public:
    explicit NetworkInspector(QWidget* parent = 0);
    ~NetworkInspector();

private:
    Ui::NetworkInspector* ui;
    QTcpServer* serverDofus;
    QWebSocketServer* serverWeb;
    QTcpSocket* clientDofus;
    QWebSocket* clientWeb;
    QByteArray buffer;

private slots:
    void onDofusConnected();
    void onDofusDisconnected();
    void onWebConnected();
    void onWebDisconnected();
    void onReceiveFromDofus();
    void onWebTextMessage(QString message);
    void onWebBinaryMessage(QByteArray data);
};

#endif // NETWORKINSPECTOR_H

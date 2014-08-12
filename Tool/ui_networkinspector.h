/********************************************************************************
** Form generated from reading UI file 'networkinspector.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKINSPECTOR_H
#define UI_NETWORKINSPECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkInspector
{
public:
    QWidget *dofus;
    QWidget *logger;

    void setupUi(QWidget *NetworkInspector)
    {
        if (NetworkInspector->objectName().isEmpty())
            NetworkInspector->setObjectName(QStringLiteral("NetworkInspector"));
        NetworkInspector->resize(391, 68);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        NetworkInspector->setWindowIcon(icon);
        dofus = new QWidget(NetworkInspector);
        dofus->setObjectName(QStringLiteral("dofus"));
        dofus->setGeometry(QRect(10, 10, 179, 47));
        dofus->setStyleSheet(QStringLiteral("background-image: url(:/images/dofus_off.png);"));
        logger = new QWidget(NetworkInspector);
        logger->setObjectName(QStringLiteral("logger"));
        logger->setGeometry(QRect(200, 10, 179, 47));
        logger->setStyleSheet(QStringLiteral("background-image: url(:/images/logger_off.png);"));

        retranslateUi(NetworkInspector);

        QMetaObject::connectSlotsByName(NetworkInspector);
    } // setupUi

    void retranslateUi(QWidget *NetworkInspector)
    {
        NetworkInspector->setWindowTitle(QApplication::translate("NetworkInspector", "Dofus Live Logger", 0));
    } // retranslateUi

};

namespace Ui {
    class NetworkInspector: public Ui_NetworkInspector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKINSPECTOR_H

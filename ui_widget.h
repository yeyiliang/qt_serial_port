/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *serialPortComboBox;
    QComboBox *baudRateComboBox;
    QComboBox *dataBitComboBox;
    QComboBox *stopBitComboBox;
    QComboBox *parityComboBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *freshSerialPortButton;
    QComboBox *flowControlComboBox;
    QLabel *label_6;
    QPushButton *openSerialPortButton;
    QGroupBox *groupBox_2;
    QTextBrowser *textBrowser;
    QPushButton *clearShowDataButton;
    QCheckBox *HEXcheckBox;
    QLCDNumber *lcdNumber;
    QLabel *label_7;
    QGroupBox *groupBox_3;
    QLineEdit *sendMessagelineEdit;
    QPushButton *clearSendMessageButton;
    QPushButton *SendMessageButton;
    QCheckBox *checkBox;
    QLCDNumber *sendMessagelcdNumber;
    QLabel *label_8;
    QGroupBox *groupBox_4;
    QPushButton *getDevicesButton;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(738, 605);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 571, 101));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 54, 12));
        serialPortComboBox = new QComboBox(groupBox);
        serialPortComboBox->setObjectName(QStringLiteral("serialPortComboBox"));
        serialPortComboBox->setGeometry(QRect(20, 40, 69, 22));
        baudRateComboBox = new QComboBox(groupBox);
        baudRateComboBox->setObjectName(QStringLiteral("baudRateComboBox"));
        baudRateComboBox->setGeometry(QRect(120, 40, 69, 22));
        dataBitComboBox = new QComboBox(groupBox);
        dataBitComboBox->setObjectName(QStringLiteral("dataBitComboBox"));
        dataBitComboBox->setGeometry(QRect(220, 40, 69, 22));
        stopBitComboBox = new QComboBox(groupBox);
        stopBitComboBox->setObjectName(QStringLiteral("stopBitComboBox"));
        stopBitComboBox->setGeometry(QRect(310, 40, 69, 22));
        parityComboBox = new QComboBox(groupBox);
        parityComboBox->setObjectName(QStringLiteral("parityComboBox"));
        parityComboBox->setGeometry(QRect(400, 40, 69, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 20, 54, 12));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 20, 54, 12));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(330, 20, 54, 12));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(410, 20, 54, 12));
        freshSerialPortButton = new QPushButton(groupBox);
        freshSerialPortButton->setObjectName(QStringLiteral("freshSerialPortButton"));
        freshSerialPortButton->setGeometry(QRect(20, 70, 75, 23));
        flowControlComboBox = new QComboBox(groupBox);
        flowControlComboBox->setObjectName(QStringLiteral("flowControlComboBox"));
        flowControlComboBox->setGeometry(QRect(490, 40, 69, 22));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(500, 20, 54, 12));
        openSerialPortButton = new QPushButton(groupBox);
        openSerialPortButton->setObjectName(QStringLiteral("openSerialPortButton"));
        openSerialPortButton->setGeometry(QRect(120, 70, 75, 23));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 360, 571, 121));
        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 20, 461, 101));
        clearShowDataButton = new QPushButton(groupBox_2);
        clearShowDataButton->setObjectName(QStringLiteral("clearShowDataButton"));
        clearShowDataButton->setGeometry(QRect(470, 40, 91, 23));
        HEXcheckBox = new QCheckBox(groupBox_2);
        HEXcheckBox->setObjectName(QStringLiteral("HEXcheckBox"));
        HEXcheckBox->setGeometry(QRect(470, 20, 71, 16));
        lcdNumber = new QLCDNumber(groupBox_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(470, 70, 64, 23));
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(470, 100, 81, 16));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 490, 571, 81));
        sendMessagelineEdit = new QLineEdit(groupBox_3);
        sendMessagelineEdit->setObjectName(QStringLiteral("sendMessagelineEdit"));
        sendMessagelineEdit->setGeometry(QRect(0, 20, 461, 21));
        clearSendMessageButton = new QPushButton(groupBox_3);
        clearSendMessageButton->setObjectName(QStringLiteral("clearSendMessageButton"));
        clearSendMessageButton->setGeometry(QRect(360, 50, 91, 23));
        SendMessageButton = new QPushButton(groupBox_3);
        SendMessageButton->setObjectName(QStringLiteral("SendMessageButton"));
        SendMessageButton->setGeometry(QRect(470, 50, 91, 23));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(470, 20, 71, 16));
        sendMessagelcdNumber = new QLCDNumber(groupBox_3);
        sendMessagelcdNumber->setObjectName(QStringLiteral("sendMessagelcdNumber"));
        sendMessagelcdNumber->setGeometry(QRect(280, 50, 64, 23));
        sendMessagelcdNumber->setFrameShadow(QFrame::Plain);
        sendMessagelcdNumber->setSegmentStyle(QLCDNumber::Flat);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(183, 50, 81, 21));
        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(590, 20, 131, 541));
        getDevicesButton = new QPushButton(groupBox_4);
        getDevicesButton->setObjectName(QStringLiteral("getDevicesButton"));
        getDevicesButton->setGeometry(QRect(20, 40, 91, 23));
        tableView = new QTableView(Widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 130, 571, 221));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\344\270\262\345\217\243\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("Widget", "\344\270\262\345\217\243", 0));
        label_2->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", 0));
        label_3->setText(QApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", 0));
        label_4->setText(QApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", 0));
        label_5->setText(QApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", 0));
        freshSerialPortButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260\344\270\262\345\217\243", 0));
        label_6->setText(QApplication::translate("Widget", "\346\265\201\346\216\247", 0));
        openSerialPortButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\346\225\260\346\215\256\346\216\245\346\224\266", 0));
        clearShowDataButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266\346\225\260\346\215\256", 0));
        HEXcheckBox->setText(QApplication::translate("Widget", "HEX", 0));
        label_7->setText(QApplication::translate("Widget", "\346\216\245\346\224\266\345\255\227\346\225\260\346\230\276\347\244\272", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\346\225\260\346\215\256\345\217\221\351\200\201", 0));
        clearSendMessageButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\345\217\221\351\200\201\346\225\260\346\215\256", 0));
        SendMessageButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
        checkBox->setText(QApplication::translate("Widget", "HEX", 0));
        label_8->setText(QApplication::translate("Widget", "\345\217\221\351\200\201\345\255\227\346\225\260\346\230\276\347\244\272", 0));
        groupBox_4->setTitle(QApplication::translate("Widget", "\350\256\276\345\244\207\346\223\215\344\275\234", 0));
        getDevicesButton->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\350\256\276\345\244\207\345\210\227\350\241\250", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

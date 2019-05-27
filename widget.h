#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QIntValidator>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include "fb_decode.h"
#include <queue>
#include "types.h"
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
        QSerialPort::DataBits dataBits;
        QString stringDataBits;
        QSerialPort::Parity parity;
        QString stringParity;
        QSerialPort::StopBits stopBits;
        QString stringStopBits;
        QSerialPort::FlowControl flowControl;
        QString stringFlowControl;
       // bool localEchoEnabled;
    };

    Settings getsettings() const;
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    const QString blankString = QObject::tr("N/A");
    QString description;
    QString manufacturer;
    QString serialNumber;
    Settings currentSettings;
    QSerialPort *serial;
    QIntValidator *intValidator;
    QSqlDatabase database;

    void fillPortsParameters();
    void updateSettings();
    //将16进制的字符串转换成字节序列
    QByteArray HexStringToByteArray(QString HexString);
    //将字节序列转换字符串
    QString ByteArrayToHexString(QByteArray data);
    FB_decode* fb_decode = NULL;
    std::queue< DeviceInfo_t > devices;

private slots:
    void SwitchSerialPort();
    void fillPortsInfo();
   // void writeData(const QByteArray &data);
    void readData();

    void on_clearShowDataButton_clicked();

    void on_SendMessageButton_clicked();

    void on_clearSendMessageButton_clicked();

    void on_sendMessagelineEdit_textEdited(const QString &arg1);

    void checkCustomBaudRatePolicy(int idx);
    void on_getDevicesButton_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // WIDGET_H

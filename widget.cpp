#include "widget.h"
#include "ui_widget.h"
#include <QtSerialPort/QtSerialPort>
#include <QDebug>
#include <QMessageBox>
#include "fb_encode.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
Widget::Settings Widget::getsettings() const
{
    return currentSettings;
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    serial = new QSerialPort(this);
    ui->baudRateComboBox->setInsertPolicy(QComboBox::NoInsert);
    intValidator = new QIntValidator(0, 4000000, this);
    fillPortsParameters();
    connect(ui->openSerialPortButton,  &QPushButton::clicked, this, &Widget::SwitchSerialPort);
    connect(ui->freshSerialPortButton, &QPushButton::clicked, this, &Widget::fillPortsInfo);
    connect(serial, &QSerialPort::readyRead, this, &Widget::readData);
    connect(ui->baudRateComboBox,  static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &Widget::checkCustomBaudRatePolicy);
    /*读取数据库*/
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
    }
    if(!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else{

    }
    QSqlQuery sql_query;
    QString select_all_sql = "select * from student";
    sql_query.prepare(select_all_sql);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString name = sql_query.value(1).toString();
            int age = sql_query.value(2).toInt();
            qDebug()<<QString("id:%1    name:%2    age:%3").arg(id).arg(name).arg(age);
        }
    }
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM STUDENT", database);	//从给定的数据库db执行sql操作, db需预先制定并打开

        int column = model->columnCount();	//获取列数
        int row = model->rowCount();		//获取行数
        qDebug() << column;
        qDebug() << row;
        model->setHeaderData(0, Qt::Horizontal, QStringLiteral("ID"));	//设置表头，如不设置则使用数据库中的默认表头
        model->setHeaderData(1, Qt::Horizontal, QStringLiteral("名字"));
        model->setHeaderData(2, Qt::Horizontal, QStringLiteral("年龄"));
        ui->tableView->setModel(model);
        //view->show();
        database.close();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::SwitchSerialPort()
{
    if (serial->isOpen())
    {
        ui->openSerialPortButton->setText(tr("打开串口"));
        qDebug() << "serial port close!" << endl;
        serial->close();
        return;
    }

    updateSettings();
    Widget::Settings p = Widget::getsettings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        qDebug()<<"open success" << endl;
        ui->openSerialPortButton->setText(tr("关闭串口"));
        //setText
    } else {
       QMessageBox::critical(this, tr("OPEN Error"), serial->errorString());
         qDebug()<<"open fail" << endl;
    }
}

void Widget::fillPortsParameters()
{
    ui->baudRateComboBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateComboBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateComboBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateComboBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRateComboBox->addItem(QStringLiteral("57600"), QSerialPort::Baud57600);
    ui->baudRateComboBox->addItem(tr("Custom"));

    ui->dataBitComboBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->dataBitComboBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->dataBitComboBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->dataBitComboBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->dataBitComboBox->setCurrentIndex(3);

    ui->parityComboBox->addItem(tr("None"), QSerialPort::NoParity);
    ui->parityComboBox->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->parityComboBox->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->parityComboBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->parityComboBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    ui->stopBitComboBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    ui->stopBitComboBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    ui->flowControlComboBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->flowControlComboBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->flowControlComboBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
}

void Widget::fillPortsInfo()
{
    ui->serialPortComboBox->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);
        ui->serialPortComboBox->addItem(list.first(), list);
        qDebug() << "list first" << list.first();
    }
    ui->serialPortComboBox->addItem(tr("Custom"));
}

void Widget::readData()
{
     serial->waitForReadyRead(30);
     QByteArray data = serial->readAll();
     if(!data.isEmpty())
     {
         ui->textBrowser->setTextColor(Qt::red);
         ui->textBrowser->append(tr("R:"));
         ui->textBrowser->setTextColor(Qt::red);
         if(ui->HEXcheckBox->isChecked()){
            QString string_temp = ByteArrayToHexString(data);
            ui->textBrowser->append(string_temp);
         }
         else{
            ui->textBrowser->append(data);
         }
     }
     ui->lcdNumber->display(ui->lcdNumber->value() + data.size());
}

void Widget::updateSettings()
{
    currentSettings.name = ui->serialPortComboBox->currentText();
    if (ui->baudRateComboBox->currentIndex() == 4) {
        currentSettings.baudRate = ui->baudRateComboBox->currentText().toInt();
    } else {
        currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                    ui->baudRateComboBox->itemData(ui->baudRateComboBox->currentIndex()).toInt());
    }
    currentSettings.stringBaudRate = QString::number(currentSettings.baudRate);
    currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                ui->dataBitComboBox->itemData(ui->dataBitComboBox->currentIndex()).toInt());
    currentSettings.stringDataBits = ui->dataBitComboBox->currentText();
    currentSettings.parity = static_cast<QSerialPort::Parity>(
                ui->parityComboBox->itemData(ui->parityComboBox->currentIndex()).toInt());
    currentSettings.stringParity = ui->parityComboBox->currentText();
    currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                ui->stopBitComboBox->itemData(ui->stopBitComboBox->currentIndex()).toInt());
    currentSettings.stringStopBits = ui->stopBitComboBox->currentText();

    currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                ui->flowControlComboBox->itemData(ui->flowControlComboBox->currentIndex()).toInt());
    currentSettings.stringFlowControl = ui->flowControlComboBox->currentText();
    //currentSettings.localEchoEnabled = ui->localEchoCheckBox->isChecked();
}


QByteArray Widget::HexStringToByteArray(QString HexString)
{
    bool ok;
    QByteArray ret;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();
    QStringList sl = HexString.split(" ");

    foreach (QString s, sl) {
        if(!s.isEmpty())
        {
            char c = s.toInt(&ok,16)&0xFF;
            if(ok){
                ret.append(c);
            }else{
                qDebug()<<"非法的16进制字符："<<s;
                QMessageBox::warning(0,tr("错误："),QString("非法的16进制字符: \"%1\"").arg(s));
            }
        }
    }
    qDebug()<<ret.toHex();
    return ret;
}

QString Widget::ByteArrayToHexString(QByteArray data)
{
    QString ret(data.toHex().toUpper());
    int len = ret.length()/2;
    qDebug()<<len;
    for(int i=1;i<len;i++)
    {
        qDebug()<<i;
        ret.insert(2*i+i-1," ");
    }
    return ret;
}

void Widget::on_clearShowDataButton_clicked()
{
    ui->textBrowser->clear();
    ui->lcdNumber->display(0);
}

void Widget::on_SendMessageButton_clicked()
{
    int count = -1;
    if(ui->sendMessagelineEdit->text().isEmpty()){
        QMessageBox::information(this, tr("提示消息"), tr("没有需要发送的数据"), QMessageBox::Ok);
        return;
    }
    QByteArray writeData(ui->sendMessagelineEdit->text().toUtf8());
    qDebug() << writeData;
    if(ui->checkBox->isChecked()){
        writeData = HexStringToByteArray(ui->sendMessagelineEdit->text());
        count = serial->write(writeData);
    }
    else{
        count = serial->write(writeData);
    }
    if(-1 == count)
    {
        QMessageBox::information(this, tr("提示消息"), tr("请确定串口打开"), QMessageBox::Ok);
        return;
    }
    else{
        ui->textBrowser->setTextColor(Qt::blue);
        ui->textBrowser->append(tr("S:"));
        ui->textBrowser->setTextColor(Qt::blue);
        if(ui->checkBox->isChecked()){
           QString string_temp = ByteArrayToHexString(writeData);
           ui->textBrowser->append(string_temp);
        }
        else{
            ui->textBrowser->append(writeData);
        }
    }
    ui->sendMessagelcdNumber->display(ui->sendMessagelcdNumber->value() + count);
}

void Widget::on_clearSendMessageButton_clicked()
{
    ui->sendMessagelineEdit->clear();
    ui->sendMessagelcdNumber->display(0);
}

void Widget::on_sendMessagelineEdit_textEdited(const QString &arg1)
{
    if(!arg1.size())
    {
        return;
    }
    if(!ui->checkBox->isChecked())
    {
        return;
    }
    if( ('0' <= arg1.data()[0]&& arg1.data()[0]<='9') ||
        ('A' <= arg1.data()[0]&& arg1.data()[0]<='F') ||
        ('a' <= arg1.data()[0]&& arg1.data()[0]<='f') ||
            arg1.data()[0] == ' ' )
    {


    }
    else{
        ui->sendMessagelineEdit->clear();
        QMessageBox::information(this, tr("提示消息"),
                                 tr("请输入HEX字符有效组合(\"0-9\",\"A-F\",\"a-f\",\" \")!"
                                    "每两个字符之间空一个空格"),
                                 QMessageBox::Ok);
        return;
    }
}

void Widget::checkCustomBaudRatePolicy(int idx)
{
    bool isCustomBaudRate = !ui->baudRateComboBox->itemData(idx).isValid();
    ui->baudRateComboBox->setEditable(isCustomBaudRate);
    if (isCustomBaudRate) {
        ui->baudRateComboBox->clearEditText();
        QLineEdit *edit = ui->baudRateComboBox->lineEdit();
        edit->setValidator(intValidator);
    }
}

void Widget::on_pushButton_clicked()
{
    FB_encode *encode_p = new FB_encode();
    uint8_t packet[9];
    int plen = 0;
    plen = encode_p->get_devices_packet(packet);
    QByteArray writedata;
    for(int i=0;i<plen;i++)
    {
         qDebug("%02x ",packet[i]);
         writedata[i] = packet[i];
    }
    int count = serial->write(writedata);
    if(-1 == count)
    {
        QMessageBox::information(this, tr("提示消息"), tr("请确定串口打开"), QMessageBox::Ok);
        return;
    }
    else{
        ui->textBrowser->setTextColor(Qt::blue);
        ui->textBrowser->append(tr("S:"));
        ui->textBrowser->setTextColor(Qt::blue);
        QString string_temp = ByteArrayToHexString(writedata);
        ui->textBrowser->append(string_temp);
    }
    ui->sendMessagelcdNumber->display(ui->sendMessagelcdNumber->value() + count);
    delete encode_p;
}

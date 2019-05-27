#ifndef TYPES_H
#define TYPES_H

typedef struct {
    uint8_t  devicename[32];
    uint8_t	devtype[5];
    uint8_t	zonetype[5];
    uint8_t	ieee[17];// 16修改为17
    uint8_t	endpoint;
    uint8_t	netAddr[5];
    uint8_t	snid[24];

    uint8_t	gatewaymac[24];
    char	datas[13];//版本号
    uint8_t  state;
    uint8_t	type;//区分zigbee 还是wifi设备
    int  data1;//亮度 温度 电量
    int  data2;//颜色 湿度 功率
    uint8_t  stateconnection;
} DeviceInfo_t;



#endif // TYPES_H

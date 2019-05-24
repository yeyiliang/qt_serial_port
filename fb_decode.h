#ifndef FB_DECODE_H
#define FB_DECODE_H
#include "stdint.h"
#include <cstring>
#include <cstdlib>
class FB_decode
{
public:
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
    DeviceInfo_t *device = NULL;
    explicit FB_decode();
    ~FB_decode();
    int parase_packet(uint8_t *data, int len);
    int decode_device_add ( uint8_t *data, int len, DeviceInfo_t *device );
    void ByteToHex ( const unsigned char * source, char * dest, int sourceLen );
private:
    //飞比网关上报数据类型
    enum {
        FB_REPORT_DEVICE = 0X01,
        FB_REPORT_CONTROL = 0X29,
        FB_REPORT_GATEWAY_UPDATE = 0X05,
        FB_REPORT_DEVICE_STATE = 0X07,//开关设备状态上报
        FB_REPORT_BRIGHTNESS = 0X08,
        FB_REPORT_COLOR = 0X09,
        FB_REPORT_SATUATION = 0X0A,
        FB_REPORT_GATEWAY_INFO = 0X15,
        FB_REPORT_STATE = 0X70,//传感器灯数据上报  控制透传模块的时候也会上报这个
        FB_REPORT_UNKNOWN = 0X75,//
    };
};

#endif // FB_DECODE_H

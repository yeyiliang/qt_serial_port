#ifndef FB_DECODE_H
#define FB_DECODE_H
#include "stdint.h"
#include <cstring>
#include <cstdlib>
#include "types.h"
class FB_decode
{
public:
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

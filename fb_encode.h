#ifndef FB_ENCODE_H
#define FB_ENCODE_H
//#include <QWidget>
#include "stdint.h"
class FB_encode
{
public:
    explicit FB_encode();
    ~FB_encode();
    int get_packet_head ( uint8_t controlType, int datalen,uint8_t *result );
    int get_xor_packet ( uint8_t *data,int len );
    int get_devices_packet ( uint8_t *packet_result );
};

#endif // FB_ENCODE_H

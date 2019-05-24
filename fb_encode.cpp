#include "fb_encode.h"
FB_encode::FB_encode()
{

}

FB_encode::~FB_encode()
{

}

int FB_encode::get_packet_head(uint8_t controlType, int datalen, uint8_t *result)
{
        result[0] = ( 8+datalen ) &0xff;
        result[1] = ( ( 8+datalen ) >>8 ) &0xff;
        result[2] = 0xff;
        result[3] = 0xff;
        result[4] = 0xff;
        result[5] = 0xff;
        result[6] = 0xfe;
        result[7] = controlType;
        return 8;
}

int FB_encode::get_xor_packet(uint8_t *data, int len)
{
        int i = 0;
        uint8_t xor1 = 0;
        data[0] = len+1;
        xor1 = data[1];
        for ( i=1; i<len; i++ ) {
            xor1^=data[i];
        }
        data[len] = xor1;
        return len+1;
}

int FB_encode::get_devices_packet(uint8_t *packet_result)
{
    int len = get_packet_head ( 0x81, 0, packet_result );
    return get_xor_packet ( packet_result, len );
}



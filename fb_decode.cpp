#include "fb_decode.h"
#include <QDebug>
FB_decode::FB_decode()
{
    device = (DeviceInfo_t *)malloc( sizeof( DeviceInfo_t ) );
    memset(device,'\0',sizeof(DeviceInfo_t));
}

FB_decode::~FB_decode()
{
    free(device);
}

int FB_decode::parase_packet(uint8_t *data, int len)
{
    switch ( data[0] ) {
        case FB_REPORT_DEVICE:
            qDebug ( "get a device  parasing len:%d",len );
            decode_device_add ( data, len, device ) ;
            break;

        case FB_REPORT_DEVICE_STATE:
//            qqDebug ( "get a device state:%d",data[5] > 2 ? 1: data[5] );
//            endpoint = data[4];
//            ByteToHex ( data + 2, (char *)netaddr, 2 );
//            netaddr[4] = '\0';
//            //device = get_deviceinfo_db ( gatewaymac,netaddr,endpoint );
//            memcpy( device->gatewaymac,gatewaymac,maclen );
//            memcpy( device->netAddr,netaddr,sizeof(netaddr) );
//            device->endpoint = endpoint;
//            qqDebug ( "get a device state:%d",device->state );

//            device->state = data[5] > 2 ? 1: data[5];
//            save_device_db ( *device,0 );
//            upload_devicecontrol_state ( device );
            break;
        case FB_REPORT_BRIGHTNESS:
//            qqDebug ( "get a device brightness :%d",data[5] );
//            endpoint = data[4];
//            ByteToHex ( data + 2, (char *)netaddr, 2 );

//            netaddr[4] = '\0';
//            tdev = get_deviceinfo_db ( gatewaymac,netaddr,endpoint );
//            qqDebug ( "get a device brightness:%d",tdev );
//            if ( tdev!=NULL ) {
//                tdev->data1 = data[5];
//                upload_device_brt ( tdev );
//                free(tdev);
//            }
            break;
        case FB_REPORT_COLOR:
//            qqDebug ( "get a device color:%d",data[5] );
//            endpoint = data[4];
//            ByteToHex ( data + 2, (char *)netaddr, 2 );
//            netaddr[4] = '\0';

//            tdev  = get_deviceinfo_db ( gatewaymac,netaddr,endpoint );
//            qqDebug ( "get a device color:%d",tdev );
//            if ( tdev!=NULL ) {
//                tdev->data2 = data[5];
//                upload_device_color ( tdev );
//                free(tdev);
//            }
            break;
        case FB_REPORT_STATE:
//            endpoint = data[4];
//            ByteToHex ( data + 2, (char *)netaddr, 2 );

//            netaddr[4] = '\0';
//            device = get_deviceinfo_db ( gatewaymac,netaddr,endpoint );

//            if ( device==NULL )
//                break;

//            if ( data[8] == 0x0A && data[9] == 0x40 ) {
//                operate_ir ( data,len-1 );
//            } else {
//                operate_report ( data,len );
//            }
            break;
        case FB_REPORT_CONTROL:
//            if ( ( data[2] == 0x04 ) && ( data[3] == FB_CMD_DELETE_DEVICE ) ) {
//                reply_del_device(gatewaymac,cur_device.netAddr,cur_device.endpoint);
//                return 0;
//            }
//            if( ( data[2] == 0x04 ) && ( data[3] == FB_CMD_GET_JOIN_NET) )
//            {
//                show_add_device_led();
//            }
//            if ( data[2] == 0x03 ) {
//                ByteToHex ( data + 3, (char *)netaddr, 2 );
//                netaddr[4] = '\0';
//                uint8_t *name = (uint8_t *)malloc(data[6]+1);
//                memcpy(name,data+7,data[6]);
//                name[data[6]] = '\0';
//                qqDebug("name:%s",name);
//                reply_rename_device(gatewaymac,netaddr,data[5],name);
//                free(name);
//            }
            break;
        default:
            break;
    }
}

int FB_decode::decode_device_add(uint8_t *data, int len, FB_decode::DeviceInfo_t *device)
{
    int pos = 0;
    char tmpstr[50];
    int snidlen = 0;
    qDebug ( "\n=====get device=====" );
    ByteToHex ( data+2,tmpstr, 2 );
    memcpy ( device->netAddr, tmpstr+2, 2 );
    memcpy ( device->netAddr+2, tmpstr, 2 );
    device->netAddr[4] = '\0';
    device->endpoint = data[4];
    pos = 12 + data[10]; //data[10] 设备名的长度
    device->stateconnection = data[data[10]+11];
    ByteToHex ( data+pos,tmpstr, 8 );
    memcpy ( device->ieee, tmpstr, 16 );
    device->ieee[16] = '\0';
    uint8_t tmp = data[7];//device id 也是devtype
    data[7] = data[8];
    data[8] = tmp;
    ByteToHex ( data+7,tmpstr, 2 );

    memcpy ( device->devtype, tmpstr, 4 );
    device->devtype[4] = '\0';
    pos += 8;
    snidlen = data[pos];
    if ( snidlen > 23 ) {
        snidlen = 23;
        device->snid[snidlen] = '\0';
    }
    memcpy ( device->snid, data+pos+1, snidlen );
    device->snid[snidlen] = '\0';

    pos += data[pos]+1;
    tmp = data[pos];
    data[pos] = data[pos+1];
    data[pos+1] = tmp;
    ByteToHex ( &data[pos],tmpstr, 2 );
    memcpy ( device->zonetype, tmpstr, 4 );
    device->zonetype[4] = '\0';
    snidlen = data[10];
    if ( snidlen>0 ) {
        memcpy ( device->devicename,data+11,snidlen>31?31:snidlen );
        device->devicename[snidlen>31?31:snidlen] = '\0';
    } else {
        device->devicename[0] = '\0';
    }
    device->datas[0]='\0';

    qDebug ("netaddr:%s",device->netAddr );
    qDebug ("snid:%s",device->snid);
    qDebug ("endpoint:%02x",device->endpoint);
    qDebug ("zonetype:%s",device->zonetype );
    qDebug ("devtype:%s",device->devtype );
    qDebug ("ieee:%s",device->ieee );
    qDebug ("=====get device=====\n");
    return 0;
}

void FB_decode::ByteToHex(const unsigned char *source, char *dest, int sourceLen)
{
    int i = 0, j = 0;
    unsigned char highByte, lowByte;

    for ( i = 0; i < sourceLen; i++ ) {
        highByte = source[i] >> 4;
        lowByte = source[i] &0x0f;

        highByte += 0x30;

        if ( highByte > 0x39 ) {
            dest[j] = highByte + 0x07;
        } else {
            dest[j] = highByte;
        }

        lowByte += 0x30;

        if ( lowByte > 0x39 ) {
            dest[j + 1] = lowByte + 0x07;
        } else {
            dest[j + 1] = lowByte;
        }

        j	+= 2;

    }
    dest[j + 1] = '\0';
}

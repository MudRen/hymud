// i2d.h

#define MUD                     0
#define STREAM                  1
#define DATAGRAM                2
#define STREAM_BINARY           3
#define DATAGRAM_BINARY         4
//-----------------------------------------------
#define I2D_MUD_SERVER          ({"59.37.59.254", 5004})
#define MUDLIST_UPDATE_INTERVAL 600
#define REFRESH_INCOMING_TIME   3*60*60
//----------------------λԪ������-------------------------
#define GB_CODE                 1       // gbվ��
#define ANTI_AD                 2       // ����������վ��
#define IGNORED                 4       // ����վ������Ϣվ��
#define SHUTDOWN                8       // �رյ�վ��
#define ONLINE                  16      // ������վ��
#define DISCONNECT              32      // ʧȥ��ϵ��վ��
#define ENCODE_CONFIRM          64      // ϵͳ�Զ��ж�gb/big5���վ��


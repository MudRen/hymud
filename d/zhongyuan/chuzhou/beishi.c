// ���ݱ��� /d/city/chuzhou/beishi.c
// by lala, 1997-12-03

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", GRN"����"NOR);
    set("long", @LONG
���ݵı��к��������������������ˣ�������ɽ���Ͷ������ģ�����������
���������Ǵ�������౱������Ʒ���ñ������󺰴�У������Ų�ʱ����������
����ʹ���г����Ե����ַǷ����г��������ǳ��ǵ��챦·��ԶԶ�Ŀ��Կ�����
ͨ���ļⶥ�����������������Ǽ�������Ǯׯ����ʵ����Ӻ�ͭǮ�ڽ���������
�����ۺ졣����������·ͨ����������ĵ��ۡ������幬��
LONG
    );
    set("outdoors", "yangzhou");
    set("no_kill",  "yangzhou");
    set("exits", ([
        "east"      : __DIR__"qianzhuang",
        "west"      : __DIR__"tianbao_lu",
        "northeast" : __DIR__"qingyun_lu",
        "southwest" : __DIR__"jiulou",
    ]));
    set("objects", ([
        __DIR__"npc/xunbu"  :   1,
        __DIR__"npc/north_seller" + random(4)  : 1,
        __DIR__"npc/north_seller" + random(4)  : 1,        
    ]));
    setup();
}
    

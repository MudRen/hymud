// �������� /d/city/chuzhou/xishi.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", GRN"����"NOR );
    set("long", @LONG
�����ǳ��ݳ�������Ҫ���г���������Ϊ������ˮ·��ͨҪ������ͷ������
������������Ҫ�������Ŀ��̺ͻ��ﶼ�Ǵ�ˮ·���ģ����а����������������ˡ�
�����е��Ƿ������޵��ز����е��Ƿ������ձ��ȹ��չ����Ļ��ð��Ư���
���ľ޴�Σ����׬ȡ��������Щ�������˾�ס���г�����ġ����޷���������Ҳ
�����������⡣�г��ı������������������С���������˺���ͷ�ˡ�
LONG
    );
    set("exits", ([
        "north"     : __DIR__"fuma_xiang",
        "west"      : __DIR__"matou", 
        "east"      : __DIR__"jiulou",
        "south"     : __DIR__"xinluo_fang",
        ]));
    set("objects", ([
        __DIR__"npc/xunbu"  :   1,
        __DIR__"npc/west_seller" + random(3)  : 1,
        __DIR__"npc/north_seller" + random(4) : 1,
        __DIR__"npc/south_seller" + random(5) : 1,
    ]));        
    set( "outdoors", "yangzhou" );       
    set( "no_kill",  "yangzhou" );
    setup();
}

// ���ݶ��� /d/city/chuzhou/dongshi.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", GRN"����"NOR);
    set("long", @LONG
���е����̶ֳȲ�������ͬ���кͱ�����ȣ����Ǳ���������Ҳ��ѷһ�
��Ҫ����Ϊ�������ǾͲ��ǽ�ͨҪ·���������ݸ�����̫���������ڶ��������
���ϡ�����Ҷ�����̫�����ݣ���Щ����Υ����Ʒ�����˾͸����ҵ��������ˡ�
������һ�ҿ͵꣬���С����͵ꡱ�������ÿͶ�ϲ��ס����������Ǽ�����
ͷ���Ե��ӻ��̡�������ͨ�����еĿ����š�
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "north"     : __DIR__"kedian",
        "west"      : __DIR__"kuaxiaqiao", 
        "east"      : __DIR__"yanxing_jie",
        "south"     : __DIR__"zahuopu",
        "northwest" : __DIR__"jiulou",
        ]));
    set("objects", ([
        __DIR__"npc/xunbu"  :   1,
        __DIR__"npc/east_seller0"  :  1,
    ]));        
    set( "outdoors", "chuzhou" );       
    setup();
}

#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "ɳѨ����");
        set("long", @LONG
������һ�������ܶ������ܺںڵģ���Լ���Կ�����Χ��ʯ�ܲ���������һ��
��������һ�����Ӵ�����������Լ��������ˮ����
LONG
        );
        set("exits", ([ 
//              "down" : __DIR__"sandriver1",
                "eastup" : __DIR__"dongd2",
        ])); 
        set("indoors", "quicksand"); 
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
} 

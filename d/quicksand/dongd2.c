#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "ɳѨ����");
        set("long", @LONG
������һ�������ܶ������ܺںڵģ���Լ���Կ�����Χ��ʯ�ܲ�������������
��ɳ�ӣ�·�ƺ�Խ��Խխ���ռ�ҲԽ��ԽС�����ƵĿ���û��һ˿���������˸о�
�����ѹ�֡�
LONG
        );
        set("exits", ([ 
                "westdown" : __DIR__"dongd1",
            "southup" : __DIR__"dongd3",
        ])); 
        set("indoors", "quicksand"); 
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
}      

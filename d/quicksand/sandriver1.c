#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "ɳ�ӵ�");
        set("long", @LONG
ԭ��������һ�����ӣ������ˮ������ȴ������ɳĮ����ΧһƬ�谵��������
�����ɵ�ɳˮ������Ըо���ˮ�е�ɳ�������Ħ���������գ���סһ��������
΢΢������������ȥ��͸��΢΢���Ķ��ڸ�������ˣ�����������Ϸ��� 
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"shaxue",
        ])); 
        set("indoors", "quicksand"); 
        set("coor/x",-1100);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
} 

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", WHT"����"NOR);
        set("long", @LONG
���Ұ�ɫ��������������ʮɫ��������Ŀ����Ȼ��ȥ���ַ·�
����һ���ء���ϸһ�����ŷ����⡰���ء���������������ɫ��ͬ����С
�����Сƿ�ӣ�ÿһ��ƿ�ӵ���ʽ������úܡ�
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
                __DIR__"npc/maskman_t" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  

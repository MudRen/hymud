 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "���¥��¥");
        set("long", @LONG
С¥���涼Χ�����ˣ������þ�����һ��СС��ͤ���������һ�񴰻�����
һ�ߣ������￴��ȥ��ǡ�ɿ��Կ��������м��һ��Բ�������ϰ��žƲˡ�������
���õþ��¶������ÿ��������ǡ�ɰ������������õ��ĵط���
LONG
        );
        set("exits", ([ 
        "down": __DIR__"xiangjulou",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",-1140);
        set("coor/y",190);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}    

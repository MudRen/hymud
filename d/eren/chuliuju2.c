 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ش����");
        set("long", @LONG
����һ���������������͵��˺󷿡�һ����齣�һ�������ıڶ�
����ܣ���Ҳ���������ġ�����϶����������ʮ��������ҩ����
ҩ�䡣 
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"chuliuju1",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    

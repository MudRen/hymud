 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
���������֡��ܴ�Ҷ���ر��̡��°�ص���Ƥ�������ϰ��
��ͬ���ϰ�ص���Ƥ�ֲڣ��°�ص���Ƥȴ�⻬�úܡ�  
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"groad6",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       

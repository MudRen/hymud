 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
����ï�ܣ�����µ�����ϸ��ǡ��û�㣬��������������������Ż�����
�㣬͸���ּ䣬��Լ�ɼ�����ũ�ҵĴ��̣�ԶԶ�ĺ�����ʮ��ֻ������ּ���Ծ��
Ϸ��һƬ̫ƽ���������ϱߣ���ϡ����С·��
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"groad4a",
        "southeast" : __DIR__"vroad5",
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

// /d/yuehou/center_n.c

inherit ROOM;

void create()
{
        set("short", "�㳡����");
        set("long", @LONG
������������Ĺ㳡�ı��࣬������һ����᫵���·��
LONG
        );

       set("exits", ([
                "south"             : __DIR__"tcenter",
                "north"             : __DIR__"tulu",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}


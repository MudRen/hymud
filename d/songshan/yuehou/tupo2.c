// /d/yuehou/tupo2.c

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
������һ��С���¡���������������һ������
LONG
        );

       set("exits", ([
                "south"             : __DIR__"tupo",
                "west"             : __DIR__"miao",
]) );

       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}


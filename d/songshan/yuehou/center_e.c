// /d/yuehou/center_e.c

inherit ROOM;

void create()
{
        set("short", "�㳡����");
        set("long", @LONG
������������Ĺ㳡�Ķ��࣬�����в���ס�ң�������һ��
��ջ��
LONG
        );

       set("exits", ([
                "south"             : __DIR__"kezhan",
                "north"             : __DIR__"jiulou",	
                "west"             : __DIR__"tcenter",
]) );
        set("objects", ([
                "/clone/npc/man" : 2,
        ]));
       set("outdoors","yuehou");

       setup();
       replace_program(ROOM);
}


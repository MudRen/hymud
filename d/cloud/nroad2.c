
// Room: /u/cloud/nroad2.c

inherit ROOM;

void create()
{
        set("coor",({2100,3850,0}));
	set("short", "���г�");
        set("long",
"���������������г����������ӻ��̣��򶫿ɿ�������Ժ�Ķ�¥��\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zaihuoy",
  "north" : __DIR__"nroad1",
  "south" : __DIR__"cross",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}



// Room: /u/cloud/eroad3.c

inherit ROOM;

void create()
{
        set("coor",({2250,3850,0}));
	set("short", "�����ֵ�");
        set("long",
"�����������ͷ���������żң����Ϸ����ǲ賡��\n"
);
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"rich",
  "southwest" : __DIR__"eroad2",
  "southeast" : __DIR__"eroad4",

]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}


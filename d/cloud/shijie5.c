
// Room: /u/cloud/shijie5.c


inherit ROOM;

void create()
{
        set("coor",({4100,-900,0}));
	set("short", "ʯ��");
        set("long",
"�����ߵ�����ʯ��·�ľ�ͷ��,��\n"
);
        set("outdoors", "cloud");
        set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"shillfoot",
  "south" : __DIR__"shijie4",
]));
        setup();
//        replace_program(ROOM);
}


// Room: /u/cloud/sroad1.c


inherit ROOM;

void create()
{
        set("coor",({2100,3750,0}));
	set("short", "�����ֵ�");
        set("long",
"������������ϣ�ͨ�������Ķɿڡ�\n"
);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cross",
  "south" : __DIR__"dukou",
]));
        set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}



// Room: /u/cloud/eroad4.c

inherit ROOM;

void create()
{
        set("coor",({2300,3780,0}));
	set("short", "�賡");
        set("long",
"�����������Ĳ賡�����ʢ����Ҷ����������в��ٲ蹤��æ�Ųɲ衣\n"
);
        set("exits", ([ /* sizeof() == 1 */
//  "northwest" : __DIR__"eroad3",
  "north" : __DIR__"eroad4.c",
"south" : __DIR__"eroad5.c",
]));

        set("objects", ([
                __DIR__"npc/worker" : 2,
        ]) );
        set("clean_up", 1);
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}



// Room: /u/cloud/shijie4.c

inherit ROOM;

void create()
{
        set("coor",({4100,-950,0}));
	set("short", "ʯ��");
        set("long",
"���˴����,���ڿ�����������ʯ��·�ľ�ͷ!������Щ�߰�?!\n"
"�ɻ���һ��·��!\n"
);
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"shijie5",
  "south" : __DIR__"shijie3",
]));
        set("outdoors", "cloud");
        setup();
        replace_program(ROOM);
}


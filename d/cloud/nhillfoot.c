
// Room: /u/cloud/dragonhill/nhillfoot.c


inherit ROOM;

void create()
{
        set("coor",({1000,4500,10}));
	set("short", "�����ڱ���");
        set("long",
"��������������·ͨ��ѩͤ�����������������ڡ�\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"nroad",
  "southup" : __DIR__"hummock",
]));
        set("outdoors", "cloud");

        setup();
//        replace_program(ROOM);
}

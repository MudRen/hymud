
// Room: /u/cloud/wroad1.c

inherit ROOM;

void create()
{
        set("coor",({2000,3800,0}));
	set("short", "�����ֵ�");
        set("long",
"�������ʯ�̵�·����������ʯС���������ϡ�����·�����ׯԺ���ƿ�������������ȴ\n"
"�ֱַ治��;�����Ǽ�˽�ӡ�\n"
);
        set("exits", ([ /* sizeof() == 4 */
//  "west" : __DIR__"latemoon/entrance",
  //"north" : __DIR__"marry_room",
  "south" : __DIR__"bookstore",
  "east" : __DIR__"wroad2",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}



// Room: /d/snow/crossroad.c

inherit ROOM;

void create()
{
        set("coor",({0,4900,10}));
	set("short", "�ּ�С·");
        set("long",
"�������Ͼ���ͨ����Զ�ǵĹٵ��ˣ�һ��ٸ����ĸ�ʾ������·�ԣ�����д�š���Զ�ǵؽ�\n"
"����������һƬï�ܵ����֣���Լ���������м�����Ӱ��\n"
);
        set("exits", ([ /* sizeof() == 3 */
 "north" : __DIR__"happyinn1",
// "northwest" : "/d/xiyu/yroad1",
  "south" : __DIR__"nroad2",
]));
        set("no_clean_up", 0);
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}

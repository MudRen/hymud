
// Room: /d/snow/nyard.c

inherit ROOM;

void create()
{
	set("coor",({-20,-45,0}));
	set("short", "�鷿");
	set("long",
"������һ��������൱Ǭ�����鷿����ľ����������������Ե�ʮ�ֿ��������������һ\n"
"����ܣ��������һ���ŵĹ��飬�����߳����ſ��Կ����쾮��\n"
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"inneryard",
]));

	set("objects", ([
		__DIR__"npc/girl":1 ]) );

	setup();
	replace_program(ROOM);
}

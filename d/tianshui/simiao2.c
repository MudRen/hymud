// Room: /u/xiaozhen/simiao2.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������Ǭʥ�µĲ�һλ��ɮ���������ϴ�����һ��С��
���������������������Ǭʥ�µ����Ƹ��㡣
LONG
);

	
	set("NO_NPC", 1);
	set("exits", ([
  "north" : __DIR__"simiao",
]));
	set("objects",([
	__DIR__"npc/monk" : 1,
	__DIR__"npc/monk1" : 1,
]));

	setup();
	replace_program(ROOM);
}

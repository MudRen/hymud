
// Room: /d/snow/wroad1.c

inherit ROOM;

void create()
{
	set("short", "����·��");
	set("long",
"����ȥ�������£��򶫱�����С·ͨ�����֣���������С·��·���Ӳݴ��������ܲ���һ��\n"
"��������������������Χ��\n"
);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"wroad2",
  "northeast" : __DIR__"wroad0",
  "west" : __DIR__"wroad3",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/crazy_dog":1,]));
	setup();
	replace_program(ROOM);
}

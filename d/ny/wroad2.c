
// Room: /d/snow/wroad2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long",
"������һ������·������ӿ����ݣ�һ���������꣬·��ʪ�����С�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"wroad1",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/farmer":1,]));
	setup();
	replace_program(ROOM);
}

// Room: /d/lumaji/zahuo.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ������ͨͨ��С�ӻ��꣬����һЩ�ճ���ƷʲôҲû
�С��������������Ǵ���������ĺ��ˣ�˭���������������һ
�ѡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"lu4",
]));

	set("objects",([
		__DIR__"npc/sanniang" : 1,
]));

	setup();
	replace_program(ROOM);
}
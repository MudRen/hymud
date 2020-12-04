// Room: /d/lumaji/caifeng.c

inherit ROOM;

void create()
{
	set("short", "�÷���");
	set("long", @LONG
���Ǵ���Ĳ÷��̣����ڴ���ĸ�Ů���һ��ķ�첹��
Ҳ���������ˣ������������ⲻ��̫�á�ֻ�й�����ڵģ�����
��������÷��������·������������˶�������÷�������ǲ�
��ġ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lu14",
]));

	set("objects",([
	__DIR__"npc/caifeng_boss" : 1,
]));

	setup();
	replace_program(ROOM);
}

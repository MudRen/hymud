// Room: /d/zuojiacun/ju2.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ͨͨ��סլ��û��̫��ĳ��衣�ݵ������һ
���������Ļ������ţ��Ա߼���һ�Ѹɲ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu13",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/lumaji/caodi2.c

inherit ROOM;

void create()
{
	set("short", "��ݵ�");
	set("long", @LONG
����һƬ���̵Ĳݵأ�һֻ���������������ȥ��������ȥ
��һƬï�ܵ�ɭ�֡�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"caodi1",
]));
	set("outdoors", "lumaji");

	set("objects",([
	__DIR__"npc/sheep" : 2,
	__DIR__"npc/sheep_girl" : 1,
]));

	setup();
	replace_program(ROOM);
}

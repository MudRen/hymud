// Room: /d/fengtian/minju.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣ԭ�ȵ������ӻ�ȥ�ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiang1",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/lumaji/nongju2.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
����һ����ש���ɵ��񷿣��������һ�����Ӻ�һЩũ��ʲ
ôҲû�С�����ũ����������ɻ���û�����ڼҡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu11",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/taiwan/house3.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���ز����װ�Ƥ�ļ�Ժ,�ſڵ���ľ���ų�����,�߸ߵ��ſ�������
�����ŵĴ�,���ߵ�ʯʨ�Ӻ�������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road2",
  "enter" : __DIR__"dayuan",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}

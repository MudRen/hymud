// Room: /d/taiwan/room2.c

inherit ROOM;

void create()
{
	set("short", "����¥��¥");
	set("long", @LONG
����������¥�Ķ�¥,һ��յ���������,��֪����,���������һ��
����,��������Ѫ��ζ��.��һ��ǽ���ƺ���д��Щ��.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "ǽ" : "�Ѿ��������ɫ��Ѫ��,��Լ�ܿ���'ħ��....�۾�.....��....'
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tingtang",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/taiwan/tree3.c

inherit ROOM;

void create()
{
	set("short", "���ֱ�");
	set("long", @LONG
�����ǰ��һƬŨ�ܵ�����.��ϡ�ܿ�����һ��С·ͨ�������.
��ǰ��һ������Ϲ���һ��ľ��(pai),��������������һ������.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "pai" : "        һ��粨��,������ãã.
            Ȱ����ͷ�ǰ�.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tree2",
  "southwest" : __DIR__"tree4",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}

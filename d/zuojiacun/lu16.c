// Room: /d/zuojiacun/lu16.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㡣
·�Ķ����Ǳ����ľ���ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu17",
  "east" : __DIR__"mujiang",
  "north" : __DIR__"lu14",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

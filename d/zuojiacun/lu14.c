// Room: /d/zuojiacun/lu14.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�����������򶫲�
Զ�ͳ��˴��ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu16",
  "west" : __DIR__"midian",
  "east" : __DIR__"lu15",
  "north" : __DIR__"lu13",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

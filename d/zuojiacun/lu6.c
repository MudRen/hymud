// Room: /d/zuojiacun/lu6.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㡣
·�����洫����Ц�����䣬����ʮ�����֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dufang",
  "south" : __DIR__"lu5",
  "north" : __DIR__"lu7",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

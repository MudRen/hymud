// Room: /d/zuojiacun/lu7.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㣬
�㿴Ҳ������һֱ��ǰ��ȥ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lu6",
  "north" : __DIR__"lu8",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

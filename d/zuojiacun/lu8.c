// Room: /d/zuojiacun/lu8.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㣬
�㲻������˵�������ߣ������ˣ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu9",
  "south" : __DIR__"lu7",
  "east" : __DIR__"lu10",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

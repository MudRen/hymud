// Room: /d/zuojiacun/lu15.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㣬
�㲻���е�����һ���ȡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu14",
  "east" : __DIR__"e_kou",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

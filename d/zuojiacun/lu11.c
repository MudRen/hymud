// Room: /d/zuojiacun/lu11.c

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
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu10",
  "east" : __DIR__"lu12",
  "north" : __DIR__"jing",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

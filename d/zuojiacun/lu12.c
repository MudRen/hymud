// Room: /d/zuojiacun/lu12.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㣬
�����粻���ӿ��˽Ų���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"lu13",
  "west" : __DIR__"lu11",
  "east" : __DIR__"liyuan",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}

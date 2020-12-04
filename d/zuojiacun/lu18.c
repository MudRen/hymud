// Room: /d/zuojiacun/lu18.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㣬
�㲻���е�����һ���ȡ�·����ʱ�����������������졣
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu19",
  "west" : __DIR__"lu5",
  "east" : __DIR__"lu17",
  "north" : __DIR__"tie",
]));
	set("outdoors", "zuojiacun");

	set("objects",([
	__DIR__"npc/yu_fanzi" : 1,
	__DIR__"npc/yuwen" : 3,	
]));

	setup();
	replace_program(ROOM);
}

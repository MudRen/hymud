// Room: /open/dt/huayanlu4.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������Ĵ�֣�·���ɨ�øɸɾ����������ֵ��Ǵ�
ͬ������ÿ���Ľֵ�֮һ����Ȼ����û��ʲô��ĵ��̣�������
Ϊ�Ϸ��������˴��㼯���������ϣ����Ժܶ��̷����ڻ���·
�����˺ܶ��̯������һ�����̣���������һ��ľ���̡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lukou",
  "east" : __DIR__"huayanlu5",
  "south" : __DIR__"mujiangpu",
  "north" : __DIR__"roupu",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}

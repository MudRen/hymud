// Room: /open/dt/huayanlu3.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������Ĵ�֣�·���ɨ�øɸɾ����������ֵ��Ǵ�
ͬ������ÿ���Ľֵ�֮һ����Ȼ����û��ʲô��ĵ��̣�������
Ϊ�Ϸ��������˴��㼯���������ϣ����Ժܶ��̷����ڻ���·
�����˺ܶ��̯������һ�����ã������ǹ���Ƽ���������ջ��
������Զ��������·�ڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huayanlu2",
  "east" : __DIR__"lukou",
  "south" : __DIR__"sulaikezhan",
  "north" : __DIR__"shutang",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}

// Room: /open/dt/huayanlu1.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������Ĵ�֣�·���ɨ�øɸɾ����������ֵ��Ǵ�
ͬ������ÿ���Ľֵ�֮һ����Ȼ����û��ʲô��ĵ��̣�������
Ϊ�Ϸ��������˴��㼯���������ϣ����Ժܶ��̷����ڻ���·
�����˺ܶ��̯�����治Զ���ǽ����֣�������һ��С�ƹݣ���
�洫��һ�󶣶�����������������ϸһ����ԭ����һ������̡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jinyangjie6",
  "east" : __DIR__"huayanlu2",
  "south" : __DIR__"bingqipu",
  "north" : __DIR__"xiaojiuguan",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}

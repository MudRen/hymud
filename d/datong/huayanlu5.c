// Room: /open/dt/huayanlu5.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
����һ�������Ĵ�֣�·���ɨ�øɸɾ����������ֵ��Ǵ�
ͬ������ÿ���Ľֵ�֮һ����Ȼ����û��ʲô��ĵ��̣�������
Ϊ�Ϸ��������˴��㼯���������ϣ����Ժܶ��̷����ڻ���·
�����˺ܶ��̯��������һ���ƾɵĴ�Ժ���������Ի���ϲ����
�ҡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"huayanlu4",
  "east" : __DIR__"sizhai2",
  "south" : __DIR__"zhouxierjia",
  "north" : __DIR__"pojiudayuan",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}

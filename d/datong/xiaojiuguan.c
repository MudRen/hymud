// Room: /open/dt/xiaojiuguan.c

inherit ROOM;

void create()
{
	set("short", "С�ƹ�");
	set("long", @LONG
����һ�Һ�С�ľƹݣ�����ֻ�����������ӣ������˽�����
ͷ����ס�����������������������ƣ�Ҳ��ӦһЩ����С�ˣ�
�۸�ǳ����ˣ��������ϵ�̯�������ʱ�򶼵���������������
�������⻹����������ͷȴ����û�д��������������һ�㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu1",
]));

	setup();
	replace_program(ROOM);
}

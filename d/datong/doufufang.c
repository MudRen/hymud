// Room: /open/dt/doufufang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ͬ�������ǲ��Զ����ģ�ֻ��Ϊ�������˵ص�����˺ܶ࣬
��������Ϳ���һ�Ҷ����꣬����������ɩ�Ķ����������ۣ�����
�ܶ౾����Ҳ����ϲ���𶹸���������ļ��Ҿ�¥�;����Ƕ�����
����������������ɩ������Ҳ�����ĺ���������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huaandao3",
]));

	setup();
	replace_program(ROOM);
}

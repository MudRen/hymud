// Room: /open/dt/sulaikezhan.c

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
λ�����Ż�����������ջ��ס����Ҫ���������Ĺ��ڸ��̡�
����ķ����ر�󣬵�Ȼ����Ҳ��һ���ģ��������߳�ȥ���ˣ�
����������µ���ߵĹ��ȫ������ո�µġ��������Ŀ�ջ��
����һ�����Ҳ����ڶ����������Ե���ͬ��������ĸ�����û��
�˲���������ŵġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu3",
]));

	setup();
	replace_program(ROOM);
}

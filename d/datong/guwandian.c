// Room: /open/dt/guwandian.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���߽����������ϰ�������һֻ����ʱ�ڵ�Сͭ����ϸ���ԣ�
������������������������һ�۾��ְ�ע�����ŵ�С����ȥ�ˡ�
����Ŀ�Ĺˣ������ľ���ϰڷ��Ÿ��ָ�����С���⣬��ͭ��
���塢�����ȵȣ�����֮�⣬��Ȼ����һ��ľͷ��̵�С����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tanhuanglu3",
]));

	setup();
	replace_program(ROOM);
}

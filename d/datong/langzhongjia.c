// Room: /open/dt/langzhongjia.c

inherit ROOM;

void create()
{
	set("short", "���м�");
	set("long", @LONG
һ������������ŵ�һ�ɲ�ҩ��ζ���߽����ݣ����ŵ�����
�Ϲ���һ����ũ���ٲ�ͼ��������ũ��������һ����֪����С��
����������ϸƷ���������ڷֱ��ҩ��ҩ�ԣ����ֱֳ���ֽ�ϼ�
¼��ʲô��һ���������˵Ĳ����黳ԾȻֽ�ϡ����䲼�õúܼ�
����ֻ���ݽ�һ������ҩ����Ϊ����עĿ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luzhuxiang2",
]));


	set("objects",([
	__DIR__"npc/doctor" : 1,
]));

	setup();
	replace_program(ROOM);
}

// Room: /u/xiaozhen/yaopu.c

inherit ROOM;

void create()
{
	set("short", "����ҩ��");
	set("long", @LONG
������ˮ���ҩ�̣�һ�߽���һ��Ũ�ص���ҩ���˱Ƕ�����
ҩ�̵��ƹ�����������һ������ҽ��������ľ����и���������
������˵�������ϴ�����һ��ҩ�䣬������������ҩ��ҩ��������
����ǳ��ã����˻��ӹ��ڲ�Զǧ����������ɹ�ҩƷ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eroad3",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/jishi" : 1,
	__DIR__"npc/ywaiter" : 1,
]));
	setup();
	replace_program(ROOM);
}

// Room: /open/dt/sizhai.c

inherit ROOM;

void create()
{
	set("short", "˽լ");
	set("long", @LONG
������һ�������ûʵ�סլ����ڵĴ������ս����ţ�͸��
һ������֮����������һ����Χס�ŵ��˼ң������Ƕ���֪����
��λ��ٹ���ס�ڴ˴�����������ƬլԺ�����ƣ�����ס������
�Ĳ��ǲƴ����ֵ����˱��������кպ����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu2",
]));

	set("objects",([
	__DIR__"npc/zhangty" : 1,
]));
	setup();
	replace_program(ROOM);
}

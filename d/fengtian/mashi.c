// Room: /d/fengtian/mashi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ʢ���������У�����ֵ��ɶ��������������
�������ѡ���Ǹ������⣬�������ȥ�������Ե�ʢ���Ĵ���
�ţ��򶫿�����ʢ����ʮ��·�ڡ�
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wy2",
]));

	set("objects",([
	__DIR__"npc/ride_s" : 1,
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/fengtian/rou.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������һ�����ص�Ѫ��ζ���ⰸ�Ϻ������˵İڷ���
���������ţ�⣬��Ӭ���˵�����������ţ������ϰ���������
�����Ľ�����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"kd5",
]));

	setup();
	replace_program(ROOM);
}

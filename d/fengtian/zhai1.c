// Room: /d/fengtian/zhai1.c

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
һ����ͨ����լ��������һ�ŷ������ݽǻ���һ�Ŵ���סլ
�Ĳɹⲻ̫�ã���������ܻ谵������Ƭ��������������լ�洦
�ɼ�������������������������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kd7",
]));

	setup();
	replace_program(ROOM);
}

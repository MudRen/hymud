// Room: /d/fengtian/zhai4.c

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
  "north" : __DIR__"lu2",
]));

	setup();
	replace_program(ROOM);
}

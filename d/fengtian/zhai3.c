// Room: /d/fengtian/zhai3.c

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
  "south" : __DIR__"lu1",
]));

	setup();
	replace_program(ROOM);
}

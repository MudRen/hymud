// Room: /d/jinghai/moonlu2.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
����һ��С��·��·�������Ӳݺ�ʯ�ӣ�·�������ǰ�С��
�����ԣ����������������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"moonlu3",
  "southup" : __DIR__"moonlu1",
]));

	set("outdoors", "jinghai");
	setup();
	replace_program(ROOM);
}

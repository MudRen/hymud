// Room: /d/jinghai/moonlu3.c

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
  "northdown" : __DIR__"moonlu4",
  "southup" : __DIR__"moonlu2",
]));

	set("outdoors", "jinghai");
	setup();
	replace_program(ROOM);
}

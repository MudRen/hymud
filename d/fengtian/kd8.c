// Room: /d/fengtian/kd8.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����·�ľ�ͷ��С���Ǹ�������������бб��С���խ����
�����ˣ���������ס�����в��ٺ�������·����ˣ������ʱ��С
�������լ��Ͳ��Ʈ���˴��̡�
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"zhai2",
  "northwest" : __DIR__"kd9",
  "southeast" : __DIR__"kd7",
]));

	setup();
	replace_program(ROOM);
}

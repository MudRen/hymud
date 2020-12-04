// Room: /d/fengtian/kd7.c

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
  "west" : __DIR__"zhai1",
  "northwest" : __DIR__"kd8",
  "southeast" : __DIR__"kd6",
]));

	set("objects",([
"/clone/npc/man" : 1,
]));

	setup();
	replace_program(ROOM);
}

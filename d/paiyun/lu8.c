// Room: /d/paiyun/lu8.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ��С·����������ɽ�ֵ�����죬·���������д�����
��פ��·��������ŵ���������ɫ��ζ����wen����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lu9",
  "south" : __DIR__"lu7",
  "east" : __DIR__"mingzhai2",
]));
        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));

	set("outdoors", "paiyun");
	setup();
	replace_program(ROOM);
}

// Room: /d/heifeng/xiaolu3.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long", @LONG
�����Ǻڷ�կ�����һ��С·�����ܾ����ĵ��ƺ��������
��������·��������Ұ�ݡ�ż��������һ����կ����Ҳ�ǴҴ�æ
æ��·����
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xiaolu2",
  "east" : __DIR__"lin3",
  "north" : __DIR__"xiaolu4",
]));

	set("objects",([
	__DIR__"npc/toumu" : 2,
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}

// Room: /d/heifeng/xiaolu2.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
�����Ǻڷ�կ�����һ��С·�����ܾ����ĵ��ƺ��������
��������·��������Ұ�ݡ�ż��������һ����կ����Ҳ�ǴҴ�æ
æ��·����
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"first",
  "west" : __DIR__"xiaolu1",
  "east" : __DIR__"xiaolu3",
]));

	set("outdoors","heifeng");

	setup();
	replace_program(ROOM);
}

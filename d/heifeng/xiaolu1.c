// Room: /d/heifeng/xiaolu1.c

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
  "south" : __DIR__"two",
  "west" : __DIR__"shanquan",
  "east" : __DIR__"xiaolu2",
]));
        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));

	set("outdoors","heifeng");

	setup();
	replace_program(ROOM);
}

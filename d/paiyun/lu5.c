// Room: /d/paiyun/lu5.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ��С·����������ɽ�ֵ�����죬·���������д�����
��פ��·��������ŵ���������ɫ��ζ����wen����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lu6",
  "west" : __DIR__"lu4",
  "east" : __DIR__"ta3",
  "north" : __DIR__"lu7",
]));
        set("objects", ([
                __DIR__"npc/qiwushi2" : 1,
        ]));

	set("outdoors", "paiyun");
	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("han zhanglao", environment(me))) && 
		dir == "south")
		return notify_fail("��������ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}
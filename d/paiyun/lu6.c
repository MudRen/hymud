// Room: /d/paiyun/lu6.c

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
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ting",
  "north" : __DIR__"lu5",
]));

        set("objects", ([
                __DIR__"npc/qiwushi" : 1,
        ]));
	set("outdoors", "paiyun");
	setup();
	//replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("qz dizi", environment(me))) && 
		dir == "east")
		return notify_fail("��־����ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}



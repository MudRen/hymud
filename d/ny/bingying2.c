
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "�����Ӫ");
	set("long",
"����վ��һ����Ӫ����ڣ����ӱ��������ڴ��ŵ����࣬һ����ߺ���뵶����ײ��\n"
"�����Ӹ���������ͨ�������������������������������ڲ�����\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"droad0",
  "north" : __DIR__"bingying3",

]));

        set("objects", ([
               "/kungfu/class/hu/bing" : 6,
        ]));

	set("outdoors", "ny");
	setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("qing bing", environment(me))) && 
		dir == "north")
		return notify_fail("һ�������ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}                                                                                                                                                                             
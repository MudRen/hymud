
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "��ɲ��Ӫ");
	set("long",
"�˴�Ϊ��ɲ����פ������ڣ�����Ϊ������ʳ�ĵط������ſڵ���������λС������ֵ�ڡ�\n"
"�ϡ�������ΪС����Ӫ�ʡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"by3",
  "east" : __DIR__"shanlu5",

]));

        set("objects", ([
               "/kungfu/class/hu/wgb" : 5,
        ]));

	set("outdoors", "xq");
	setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("luosha gui", environment(me))) && 
		dir == "west")
		return notify_fail("һ����ɲ����ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}                                                                                                                                                                             
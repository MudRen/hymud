
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "����Ժ");
	set("long",
"���Ļʹ�������ʡ������Ժ����˾������������������ڹ����ڡ������ʹ���\n"
"Ԫ껹�����һƬ����ڻԻ͵Ĺ����Ⱥ��ƽ���ס�ĵͰ������γ������Աȡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hg2",
 "north" : __DIR__"hg4",

]));

        set("objects", ([
               "/kungfu/class/hu/en3" : 1,
               "/kungfu/class/hu/en4" : 1,
        ]));

	set("outdoors", "xq");
	setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("liao king", environment(me))) && 
		dir == "north")
		return notify_fail("Ү�ɺ����ס�����ȥ·��\n");
	if ( objectp(present("liao wang", environment(me))) && 
		dir == "north")
		return notify_fail("Ү�ɴ�ʯ��ס�����ȥ·��\n");

	return ::valid_leave(me, dir);
}              
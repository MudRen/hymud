
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "����ʡ");
	set("long",
"���Ļʹ�������ʡ������Ժ����˾������������������ڹ����ڡ������ʹ���\n"
"Ԫ껹�����һƬ����ڻԻ͵Ĺ����Ⱥ��ƽ���ס�ĵͰ������γ������Աȡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hg3",
  "south" : __DIR__"huanggong",

]));

        set("objects", ([
               "/kungfu/class/hu/bing2" : 6,
        ]));

	set("outdoors", "xq");
	setup();
//        replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if ( objectp(present("liao bing", environment(me))) && 
		dir == "north")
		return notify_fail("һ���Ʊ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}                                                                                                                                                                             
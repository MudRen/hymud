
// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "Ԫ껹�");
	set("long",
"���Ļʹ�������ʡ������Ժ����˾������������������ڹ����ڡ������ʹ���\n"
"Ԫ껹�����һƬ����ڻԻ͵Ĺ����Ⱥ��ƽ���ס�ĵͰ������γ������Աȡ�\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hg3",


]));

        set("objects", ([
               "/kungfu/class/hu/xiaofeng" : 1,
               //"/kungfu/class/hu/en2" : 1,
        ]));

	set("outdoors", "xq");
	setup();
//        replace_program(ROOM);
}
              

// Room: /d/snow/droad0.c


inherit ROOM;

void create()
{
        set("coor",({0,5000,10}));
	set("short", "Ԫʦ����");
	set("long",
"����վ��һ����Ӫ����ڣ����ӱ��������ڴ��ŵ����࣬һ����ߺ���뵶����ײ��\n"
"�����Ӹ���������ͨ�������������������������������ڲ�����\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bingying2",

]));

        set("objects", ([
               "/kungfu/class/hu/en1" : 1,
               "/kungfu/class/hu/en2" : 1,
        ]));

	set("outdoors", "ny");
	setup();
//        replace_program(ROOM);
}


// Room: /d/snow/nroad1.c

inherit ROOM;

void create()
{
    set("coor",({0,4800,10}));
	set("short", "Ҫ��ǰ�Ŀյ�");
	set("long",
"������һ��Ҫ�����ɶ�Ҫ�����ؽ��������һ���������Ķ�ԣ�������һ��ʯ��·��\n"
"���������������ǳ����֡�\n"
);
	set("outdoors", "ny");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad2",
  "south" : __DIR__"square",
//  "west" : __DIR__"nroad3",
//  "east" : __DIR__"nroad7",
]));
	set("no_clean_up", 0);

	set("objects", ([
	  __DIR__"npc/wujiang" : 1,
  __DIR__"npc/bing" : 5,  
	__DIR__"npc/playboy":1,]));
	setup();
//    replace_program(ROOM)
//    replace_program(ROOM);
}
//int valid_leave(object me, string dir)
//        if( dir=="south" && !wizardp(me) )
//                return notify_fail("����ʩ���У���ĵ���\n");
//        return ::valid_leave(me, dir);
//}

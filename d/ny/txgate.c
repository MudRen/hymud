
// Room: /d/snow/school1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("coor",({-200,4770,10}));
	set("short", "�ɶ���Ӫ");
	set("long",
"����վ��һ����Ӫ����ڣ���ֻ�޴��ʯʨ�����ڴ��ŵ����࣬һ����ߺ���뵶����ײ��\n"
"������Ժ���д�����ͨ�������������������������������ڲ�����\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"txyard",
  "northeast" : __DIR__"nroad7",
]));
	set("outdoors", "ny");
	set("objects", ([
  __DIR__"npc/wujiang" : 1,
  __DIR__"npc/bing" : 5,  	
		__DIR__"npc/txtrainer": 1]) ); 

	setup();
	replace_program(ROOM);
}

// Room: /d/snow/school1.c

#include <room.h>

inherit ROOM;

void create()
{
	set("coor",({-5,-50,0}));
	set("short", "������ݴ���");
	set("long",
"��������վ��һ���լԺ����ڣ���ֻ�޴��ʯʨ�����ڴ��ŵ����࣬һ����ߺ���뵶����\n"
"ײ��������Ժ���д�����ͨ��������������������������µĺ������ڲ�����\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"school2",
]));
	set("outdoors", "ny");
          set_temp("light",1);
	set("objects", ([
		__DIR__"npc/guard": 1 ]) );



	setup();
	replace_program(ROOM);
}

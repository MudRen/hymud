
//#include <room.h>

inherit ROOM;
void create()
{
	set("short", "�ƺ��±�");
	set("long", @long	
ɽ�������ǻƺӡ��ƺ����ʵ�����Ѿ���ɳ�����ˡ���ɫ�ĺ�ˮ
�ںӴ��﷭���ţ������ţ�����һ�����޴�����ѣ����ǡ�������ǧ
���ˣ�����ӭ�����ɺ졹��
long );
	set("exits", ([
  
  "westup" : __DIR__"road1",
  "eastup" : __DIR__"huanghe2",
  
	]));
	set("objects", ([
		//__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	        set("outdoors", "shanxi");
        set("coor/x",-480);
        set("coor/y",-400);
        set("coor/z",100);
	setup();
	//replace_program(ROOM);
}


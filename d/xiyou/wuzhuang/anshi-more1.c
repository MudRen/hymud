//Cracked by Roath
//anshi-more1.c
#include <room.h>
inherit ROOM;

// mon 6/20/99 
// since this room don't refresh, so need set limit.


void create ()
{
	set ("short", "ͤ������");
	set ("long", @LONG

����ĵ��ͤ���µ�һ�����ң�ʮ����С������ׯ������������Ҫ��
Ʒ�ĵط������ҵ�ǽ�������ż��������ı�ʯ��������������Ȼ��
̫������ȴҲ�㹻���˿������ҵĲ����ˡ� 
LONG);

	set("exits", 
	([ //sizeof() == 4
		//"southwest" : __DIR__"juyuan",
		//"north" : __DIR__"southpool",
		"out" : __DIR__"anshi",
		//"west" : __DIR__"westway6",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"obj/huangtong-key" : 1,
	]));

	//set("outdoors", "xy9");


	setup();
}


void init()
{
	//add_action("do_mo", "mo");

	if( query("started") != 1 )
	{
		set("started", 1);
		call_out("generate_book", 18010);//5 hours 10 seconds.
	}
}


int clean_up()
{
	return 0;
}



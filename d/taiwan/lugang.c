// Room: /d/taiwan/lugang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "¹��");
	set("long", @LONG
¹�۵ر��������緫���ɡ����̱ϼ����Ǻ�Ͽ����ó�׵��в�Ҫ�ۡ�
̨���в����Ż��������ƣ�һ����¹�����ۣ���ָ¹��Ϊǫ̈̄������̨
�帮�ĵڶ���ǡ�
    ����������(zhou)�����������������ȥ�д�ֱ��Ȫ�ݡ�
LONG );
	set("exits", ([
		"east"       : __DIR__"banxianshe",
		"west"       : "/d/quanzhou/haigang",
	]));
	set("objects", ([
		__DIR__"npc/shangren": 3,
	]));
	set("item_desc", ([
		"zhou" : "һ�����ۣ���������Ľ�ͨ������\n",
	]));

	set("outdoors", "taiwan");
	set("coor/x", 2500);
	set("coor/y", -7000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object obj;
	object ob = this_player () ;
	string dir;
	if( !arg || arg !="zhou" ) 
	{
		tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
		return 1 ;
	}
	message_vision("ˮ��һ�������ϴ���æ����һ��������ඣ�\n", ob);
	message_vision("ˮ�����𷫣��������������С�\n", ob);
		obj=present(ob->query("id")+" "+"wulin renwu", environment(ob));
        if (obj) obj->move (__DIR__"dahai");
	ob ->move(__DIR__"dahai") ;
	tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
	call_out("tpenghu", 10 , ob,obj );
	return 1 ;
}
void tpenghu(object ob,object obj )
{
	tell_object(ob , "�������ڵִ��˺�Ͽ��һ���󵺡������´�����\n" ) ;
	ob->move (__DIR__"penghu") ;
if (obj) obj->move(__DIR__"penghu");  
}

// Room: /d/mingjiao/mishi.c
// Date: Java 97/04/9

inherit ROOM;
#include <room.h>;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���ʯ�Ҽ��󣬶��ϴ������飬������Ȼ��ʯ�������˼�����ͻ
�����µ����������á����������·���δ�þ����ŵó���һ��һŮ��
�߽��������ã�ֻ����Ů������ץ��һ������������ذ�ף���������
���ؿڡ�
LONG );
	set("exits", ([
		"south" : __DIR__"midao0",
		"up"    : __DIR__"neishi",
	]));
	set("objects", ([
		__DIR__"obj/yangdt" : 1,
		__DIR__"obj/yangfr" : 1,
		"/kungfu/class/mingjiao/cheng" : 1,	
	]));
	set("no_clean_up", 0);
	set("xin_count", 1);
	setup();
        //create_door("south", "ʯ��", "north", !DOOR_CLOSED);
}
void init()
{
	this_player()->set_temp("ketou_times", 50);
	add_action("do_ketou", "ketou");
}

int do_ketou()
{
	int i;
	object me, ob,who;

	me = this_player();

	if ( objectp(present("cheng kun", environment(me))) )
		return notify_fail("������ס����Ķ�����\n");


	if ( me->query_temp("ketou_times") == 0 )
	{
		message_vision("$N��ͷ�ĵ����˹�ȥ��\n", me);
		me->set_temp("ketou_times", random(50));
		me->unconcious();
		return 1;
	}
	me->add_temp("ketou_times", -1);	

	message_vision("$N�ϵع����������������Ź�ǰ���������ؿ�ͷ��\n", me);

	if ( random(20) == 3 && query("xin_count") > 0 )
	{
		add("xin_count", -1);
		ob=new("/d/mingjiao/obj/yixin");
		ob->move(this_object());
		if (me->query_temp("book1241")) me->set_temp("book1242",1);
		
		tell_object(me, "ͻȻ��̧�ۿ����Ź����棬�м���ֽƬ��\n");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("ketou_times") >= 0 ) me->delete_temp("ketou_times");
	return ::valid_leave();
}


// zhulin2.c
//by dicky

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ܶ������ܵ����֣�һ̤�������������·�������˼�������
Ω����̤��ƺ֮����ż����΢�������Ҷ�������������������˳�
��Ϊ֮һ�ӣ����Ǿ��ѵ��������ڡ��������������(zhuzi)������
��Ľ�ʵ��׳������ż��Ҳ���������￳��(chop)�����������ߡ�
LONG);

        set("outdoors", "houjizhen");

	set("exits", ([
		"south" :  __DIR__"zhulin1",
		"north" :  __DIR__"zhulin3",
	]));

	set("item_desc",([
		"zhuzi" : "����һƬïʢ�����֣����ӳ��÷ǳ���׳��\n", 
	]));

	setup();
//	replace_program(ROOM);
}

int init()
{
	add_action("do_kan","fa");
	add_action("do_kan","chop");
	add_action("do_make","make");
}

int do_kan(string arg)
	{
	object me;
	me = this_player();
	if ( !living(this_player()) || arg != "zhuzi" )
	return 0;

        if (!present("pozhu fu", me))
	return notify_fail("�㻹����ȥŪ��������˵�ɣ�\n");

	if ((int)me->query_skill("unarmed", 1) < 200)
	return notify_fail("������Ļ�����ô���ţ��������ƻ��������Ȼ����ô��\n");

	if ((int)me->query_temp("taxue/zhuzi") >=4 )
	return notify_fail("�����Ѿ������ˣ��㻹�ǻ�ȥ�ɣ�\n");

        if ( (int)me->query("qi") < 200) 
	{
		me->receive_damage("qi", 10 ,"tire");
		write("��̫���ˣ�������Ϣһ���ٿ��ɣ�\n");              
        return 1;
	}

	if (!(int)me->query_temp("taxue/zhuzi"))
	{
		me->receive_damage("qi", 100,"tire");
		message_vision("$N�Ӷ��������������ӿ�ȥ��һ��Ϳ���һ�ô�׳�����ӣ����Ǹɾ����䡣\n", me); 
		me->set_temp("taxue/zhuzi",1); 
	return 1;
	}		

	me->receive_damage("qi", 100,"tire");
	message_vision("$N�Ӷ��������������ӿ�ȥ��һ��Ϳ���һ�ô�׳�����ӣ����Ǹɾ����䡣\n", me);  
	me->add_temp("taxue/zhuzi",1);       
	return 1;
} 

int do_make(string arg)
	{
	object me,ob,ob1;
	me = this_player();
	if ( !living(this_player()) || arg != "fengzheng" )
	return 0;

	if (!(int)me->query_temp("taxue/zhuzi"))
	return notify_fail("��û�����ӣ���ô�����ݣ�\n");

	if ((int)me->query_temp("taxue/zhuzi") < 4 )
	return notify_fail("��ô�����ӣ���ʲô���ݣ��㻹���ٿ���ɣ�\n");

        if (!present("bu pi", me) && !present("sheng zi", me))
	return notify_fail("�����ݣ�����ȱ�ٵ�ʲô�ɣ�\n");

        if ( !me->query_temp("taxue/ask_master"))
		return notify_fail("�ٺ٣��������ݸ�ʲô�أ�����һ�������ȣ�\n");

        message_vision(HIC"$N�Ӷ����񸫣�������������Ȼ�������Ӱ���Ƭ�Ͳ�ƥ������������һ���������һ������ݡ�\n"NOR, me); 
	ob1 = present("sheng zi", me);
	destruct(ob1);
	ob1 = present("bu pi", me);
	destruct(ob1);
	ob=new(__DIR__"obj/fengzheng");
	ob->move(me);
	me->delete_temp("taxue/master_ask");
	me->delete_temp("taxue/zhuzi");   
	return 1;
} 
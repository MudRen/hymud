#include <room.h>
#include <ansi.h>
string look_gaoshi();
inherit ROOM;
int jian=12,dao=5,fu=5,tongjia=5,gangjia=5;
void create ()
{
  set ("short", "������");
  set ("long", @LONG
�������ǹŴ�ı����ң������Ǽ��������ܣ���������˸��ָ�
���ı�����������ָ�� look jia�� ���Կ�����ʲô��������Ҫ�Ļ�
�����ã�����ָ�� qu ����ID����
LONG);
  set("exits", ([ /* sizeof() == 2 */

"south" : __DIR__"lw",


]));
  set("objects", ([ /* sizeof() == 1 */
  //__DIR__"jing" : 1,
 
]));

	set("item_desc", ([
		"jia" : (: look_gaoshi :),
	]));

set("roomif","$botten#�鿴|ȡ:look jia|qu <����>$#");	
  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  //replace_program(ROOM);
}

void init()
{
	add_action("do_list","look");
	add_action("do_naqu","qu");
}


string look_gaoshi()
{
string msg;
	object me;
	me=this_player();
	if(! living(me))	return 0;
	//if(arg!=" jia" )	return 0;
	msg="Ŀǰ�ⷿ����������Ʒ������ȡ(qu)\n";
	msg +="----------------------------------\n";
	if( jian)
	msg +="  ����(jian)             "+chinese_number(jian)+"��\n";
	if( dao)
	msg +="  ����(dao)              "+chinese_number(dao)+"��\n";
	if(fu)
	msg +="  �師(fu)               "+chinese_number(fu)+"��\n";
	if(tongjia)
	msg +="  ͭ��(tongjia)          "+chinese_number(tongjia)+"��\n";
	if(gangjia)
	msg +="  �ּ�(gangjia)          "+chinese_number(gangjia)+"��\n";
	msg +="----------------------------------\n";
	//write(msg);
	return msg;
	
}



int do_naqu(string arg)
{
	object me,sth;
	mapping data;
	me=this_player();
	if(! living(me))	return 0;
	if(! arg)	return notify_fail("��Ҫ��ȡʲô��\n");
	if(me->query("combat_exp",1) > 100000 && !wizardp(me))
		return notify_fail("��ľ���̫���ˣ�û��Ҫ������ѵ������ɡ�\n");
	if( me->query_temp("have_naqu"))
		return notify_fail("���Ѿ��ù���ѽ,��һ�������ɡ�\n");
	if(arg=="jian" && jian)	{
		sth=new("/clone/weapon/changjian");
		if( me->query_encumbrance() + sth->query_weight()
			> me->query_max_encumbrance())
		return notify_fail("��ѽ��������̫���ˡ�\n");
		jian --;
		sth->move(me);
		message_vision("$N�Ӽ��������˰ѳ�����\n",me);
	}	else if(arg=="dao" && dao)	{
		sth=new("/clone/weapon/blade");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("��ѵ��������̫���ˡ�\n");
                dao --;
		sth->move(me);
		message_vision("$N�Ӽ��������˰ѵ�����\n",me);
	}	else if(arg=="fu" && fu)	{
		sth=new("/clone/weapon/axe");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("��Ѹ��������̫���ˡ�\n");
                fu --;
		sth->move(me);
		message_vision("$N�Ӽ��������˰Ѱ師��\n",me);
	}	else if(arg=="tongjia" && tongjia) {
sth=new("/clone/armor/tongjia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("���ͭ�׶������̫���ˡ�\n");
                tongjia --;
		sth->move(me);
		message_vision("$N�Ӽ��������˼�ͭ�ס�\n",me);
	}	else if(arg=="gangjia" && gangjia) {
sth=new("/clone/armor/tiejia");
                if( me->query_encumbrance() + sth->query_weight()
                        > me->query_max_encumbrance())
		return notify_fail("����ּ׶������̫���ˡ�\n");
                gangjia--;
		sth->move(me);
		message_vision("$N�Ӽ��������˼��ּס�\n",me);
	}	else	return notify_fail("���û������������\n");
	sth->set("no_sell",1);
	me->set_temp("have_naqu",1);
	return 1;
}

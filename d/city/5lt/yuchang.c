// Room: /d/5lt/yuchang.c
#include <ansi.h>
inherit ROOM;
#define MAX_EXP 80000
#define MIN_EXP 10
int do_jump(string arg);
int do_go(string);
void create()
{
	set("short", "����ԡ��");
	set("long", @LONG
����һ���ǳ��ɾ��ĺ���ԡ����ÿ���ļ�����ͱ��ȫ�������ֵĵ�
��������������Ǳˮ���������㡢���˺���Ӿ�����ߵ���ͷ(pier)
�����Կ���һ�Һ�����ͧ������Ա���ӣ���С���ڽ������й����ڰ���
(ganhuo)�������й�Ա�ֳֳ����ڼ๤��
LONG);
	set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);
	set("outdoors", "5lt");set("no_fight",1);set("chatroom",1);set("pingan",1);set("sleep_room", 1);
	set("exits", ([
		"east"  : __DIR__"haitan",
	]));
	set("objects",  ([
		__DIR__"npc/sunray": 1,
			"/d/city/npc/jiangong": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -205);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}


void init()
{
	add_action("do_work", ({"work", "ganhuo"}) );
}

int do_work()
{
	object me = this_player();
//	if ( query("worktimes") < 0)
//		return notify_fail("��ͷ�����ڲ���Ҫ�˸ɻ�´ΰɣ�\n");

	if (me->query("gender") == "Ů��") 
	return notify_fail("��ͷ�����ڲ���ҪŮ���ӼҸɻ\n");
//	if ( me->query_temp("working") )
//		return notify_fail("���Ѿ��ڸɻ��ˣ���\n");
	if ( !objectp( present ("jian gong", environment(me) ) ) )
		return notify_fail("��ͷ�����ڲ���Ҫ�˸ɻ�´ΰɣ�\n");
	if (me->query("combat_exp")<MIN_EXP)
	{
		tell_object(me,"���ﶼ���ػ�����ڻ��ɲ��ˡ�\n");
		return 1;
	}
	

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if ( (int)me->query("jing") < 10 || (int)me->query("qi") < 10 )
	{
		message_vision(
"�๤����$N����һ���ӣ�$N���϶�ʱ����һ��Ѫ�ۣ�$N�������Ķ㵽һ\n"
"��ȥ�ˡ�����ģ���С���⸱ή�Ҳ�������ӻ���ɻ�������๤��\n"
"��������������\n", me);
		me->receive_damage("qi", 11);
		me->receive_wound("qi", 11);
		return 1;
	}
if (me->query_temp("working") >=1)
{
	write(""+me->query("name")+"����һ������������Ӳֿ�ᵽ����ͷ��\n");
}
else
{
	write("�๤�ñ���ָ��ָ��˵������ȥ���������ɡ���\n");
	write(""+me->query("name")+"����һ���������ʼ�ɻ\n");
}
	add("worktimes", -1);
	me->start_busy(5);
	me->add_temp("working",1);
//	remove_call_out("work_end");
if (me->query_temp("working") >=6)
	call_out("work_end", 1, me);

	return 1;
}

int work_end(object me)
{
	object ob1;
	int add_exp,add_pot,add_score;
	me->delete_temp("working");
	write("��������๤�ˣ�����һ���������۸�������\n"
"�๤����������"+me->query("name")+"�ļ��˵������С�ӣ������ģ�������Ĺ�Ǯ����\n");
	me->receive_damage("jing",me->query("jing")/8);
	me->receive_damage("qi",me->query("qi")/8);
	me->receive_damage("jing",10);
	me->receive_damage("qi",10);
		add_exp=3+random(5);
		add_pot=2+random(2);
		//add_score=1+random(1);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		//me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(1);
		ob1->move(me);	
		tell_object(me,HIW"��õ���:"
			+ chinese_number(add_exp) + "��ʵս���飬"
			+ chinese_number(add_pot) + "��Ǳ�ܡ�\n"NOR);				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}


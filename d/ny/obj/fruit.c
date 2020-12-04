
// ffruit.c
// sill email
// zhulp@app.zju.edu.cn
//

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

int ffruit_do_e();

void create()
{
	set_name(GRN "���Բ��ȹ�" NOR, ({"fruit"}) );
	set_weight(10);
	set("no_get",1);
	set("no_drop","��ô�õĶ�����ô�ܶ��أ�С���������ġ�\n\n");
	set("long",
		"����С����͸����һ������Ĺ�ʵ, ����(eatfruit)�ɣ�\n");
	if( clonep() )
			set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("material", "unknow");
	}
}

void init()
{
	add_action( "ffruit_do_e", "eatfruit" );
}

int ffruit_do_e()
{
	object	ob, me;
	int		fw;
    int maxkee, maxsen, maxgin;
	
	ob = this_object();
	me = this_player();
    maxkee = me->query("max_kee");
    maxsen = me->query("max_sen");
    maxgin = me->query("max_gin");

	if( !me->query_condition("f_condi") )
	{
		write("�˹�ֻӦ�����У�����Ϊ�����˼䣡�ۣ����� ̫�úó���, ����...����...\n");
		tell_object(me, "Ou��������˸����á�����Ou...Ou...\n" );

		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);

		write("����Ҳ���óԷ���ˮ�ˣ�\n\n");
		me->apply_condition("f_condi", 5);
		ob->set("eated", "xixi");
	}
	else
	{

		tell_object( me, "���Ѿ��Թ��ˡ������ٳ�һ�ΰ�\n\n");
		tell_object(me, "Ou��������˸����á�����Ou...Ou...\n" );

		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);
	}
    me->set("eff_kee",maxkee);
    me->set("kee",maxkee);
    me->set("eff_sen",maxsen);
    me->set("sen",maxsen);
    me->set("eff_gin",maxgin);
    me->set("gin",maxgin);

	return 1;
}

int query_autoload()
{
	return 1;
}


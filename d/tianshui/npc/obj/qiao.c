// qiao.c

#include <ansi.h>


inherit ITEM;

private int have_sword;

void create()
{
	set_name(RED "���轣��" NOR, ({ "jian qiao" }) );
	set_weight(10000);
	set_max_encumbrance(15000);
	set("valid_number",1);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ�ѿ����صĽ��ʣ�ͨ�巺����
�⣬����������������С�֣���ϸ��
���������ġ�\n");

		set("value", 200);
		set("material", "blacksteel");
        }

        setup();
}

int is_container() { return 1; }

void init()
{
	add_action("do_ba","ba");
	add_action("do_shou","sh");
	add_action("do_put","put");
	add_action("do_get","get");
}

int do_ba(string arg)
{
	object weapon,me = this_player();

	if(!arg || arg == "" )
		return notify_fail("��Ҫ��ʲô��\n");

	if(!arg || arg == "")
		return notify_fail("��Ҫ��ʲô��");

	if(!have_sword)
		return notify_fail("������û�н���\n");

	weapon = present(arg, this_object());
	if(!weapon)
		return notify_fail("��Ҫ��ʲô��\n");

	weapon->move(me);

	have_sword = 0;
	message_vision("$N�ӽ�����γ���"+weapon->name()+"\n",me);

	if(me->is_fighting())
		me->start_busy(1);
	return 1;
}

int do_shou(string arg)
{
	object me,target,weapon;

	me = this_player();

	if(me->is_busy())
		return notify_fail("������æ");

	if(!arg || arg == "")
		return notify_fail("��Ҫ��˭�����õı�����\n");

	if(have_sword)
		return notify_fail("�������Ѿ��б����ˡ�\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("��Ҫ��˭�����õı�����\n");

	if(!target->is_character() || target->is_corpse())
		return notify_fail("��Ҫ��˭�����õı�����\n");

	if( target == me )
		return notify_fail("�㲻�����Լ��ı�����\n");

	weapon = target->query_temp("weapon");
	if(!weapon || (string)weapon->query("skill_type") != "sword")
		return notify_fail("�Է�����û���ñ�����\n");
/*
	if((int)me->query("str") < (int)target->query("str"))
		return notify_fail("��ı���������\n");
*/
	message_vision(sprintf(HIY"\n$N������������$nһ�Σ�\n$nֻ������һ�ɣ�%s���ֶ�������$N�������ꡱһ��������������ʡ�\n\n" NOR,
		weapon->name()),me,target);

	weapon->move(this_object());
	have_sword = 1;
	me->start_busy(2);
	target->kill_ob(me);
	me->fight_ob(target);
	return 1;
}

int do_get(string arg)
{
	string what;

	if(!arg)
		return 0;

	if(sscanf(arg, "%s from %s", arg, what)==2)
	{
		if(id(what))
		{
			write("�ǲ���������\n");
			return 1;
		}
		return 0;
	}
	return 0;
}

int do_put(string arg)
{
	string what;

	if(!arg) return 0;

	if(sscanf(arg, "%s in %s", arg, what)==2)
	{
		if(id(what))
		{
			write("�ǲ���������\n");
			return 1;
		}
		return 0;
	}
	return 0;
}

// bonze_drug.c
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	int huifusl;
	if (duration < 1) return 0;

        huifusl=(int)me->query_temp("huifusl",1);
        if (!huifusl) huifusl=100;
	me->apply_condition("jinghuifu", duration - 1);
message_vision(HIY"ֻ��$N˫�ۼ���������\n"NOR, me);

if (!me->query_condition("jinghuifu"))
{
message_vision(HIG"ֻ��$N������ָ���������\n"NOR, me);
message_vision(HIG"ֻ��$N������ָ�������,���ɾ��������Ѿ�������\n"NOR, me);
me->delete_temp("huifusl");
return 1;
}

		
	call_out("check_fight", 5, me, huifusl);

	return 1;
}

string query_type(object me)
{
	return "job";
}


void spec_recover(object me, int sl)
{
	int i,huifusl;
        huifusl=(int)me->query_temp("huifusl",1);
        if (!huifusl) huifusl=100;
        if (!sl) sl=huifusl;
		if (me->query("max_jing") > me->query("eff_jing") || me->query("eff_jing") > me->query("jing")
		&& random(2)==0) {
			message_vision(HIY"ֻ��$N�����ɾ���������˫�ۿ���֮�������֣������ʱ����\n"NOR, me);
			me->add("eff_jing", 100 + sl);
			if (me->query("eff_jing") > me->query("max_jing"))
				me->set("eff_jing", me->query("max_jing"));
			me->add("jing", 100 + sl);
			if (me->query("jing") > me->query("eff_jing"))
				me->set("jing", me->query("eff_jing"));
		}

	return;
}

void check_fight(object me,int sl)
{

	if (!me) return;

	
if (!me->query_condition("jinghuifu"))
{
return;
}


if (me->query_condition("jinghuifu"))
{
spec_recover(me, sl);
call_out("check_fight", 5, me,sl);
}
}

void remove_effect(object me)
{
message_vision(HIG"ֻ��$N������ָ�������,���ɾ��������Ѿ�������\n"NOR, me);
        return;
}
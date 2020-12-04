// bonze_drug.c
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	int huifusl;
	if (duration < 1) return 0;

        huifusl=(int)me->query_temp("huifusl",1);
        if (!huifusl) huifusl=100;
	me->apply_condition("nlhuifu", duration - 1);
message_vision(HIY"只见$N的全身气息流动！\n"NOR, me);

if (!me->query_condition("nlhuifu"))
{
message_vision(HIG"只见$N的气息恢复了正常！\n"NOR, me);
message_vision(HIG"只见$N的气息恢复了正常,妙欲决的作用已经结束！\n"NOR, me);
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
		if (me->query("max_neili") > me->query("neili")
		&& random(2)==0) {
			message_vision(HIY"只见$N的伤口在妙欲决的作用下全身气息一变，内劲已经开始恢复了。\n"NOR, me);
			me->add("neili", 100 + sl);
			if (me->query("neili") > me->query("max_neili"))
				me->set("neili", me->query("max_neili"));
		}

	return;
}

void check_fight(object me,int sl)
{

	if (!me) return;

	
if (!me->query_condition("nlhuifu"))
{
return;
}


if (me->query_condition("nlhuifu"))
{
spec_recover(me, sl);
call_out("check_fight", 5, me,sl);
}
}

void remove_effect(object me)
{
message_vision(HIG"只见$N的的气息恢复了正常,妙欲决的作用已经结束！\n"NOR, me);
        return;
}
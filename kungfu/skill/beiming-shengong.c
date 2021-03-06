// beimin-shengong.c 北冥神功
// By Hop
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("beiming-shengong", 1);

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的北冥神功。\n");

	if (
//	me->query_skill("bahuang-gong",1)
	 me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("你不先散了别派内功，怎能学北冥神功？！\n");

	return 1;
}

int practice_skill(object me)
{
    return notify_fail("北冥神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
    return __DIR__"beiming-shengong/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl,nlevel;
        int flvl;
        lvl  = me->query_skill("beiming-shengong", 1);
if (lvl==0)
        lvl  = me->query_skill("bahuang-gong", 1);

if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
 if (random(8)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-800);
if (me->query("neili") < me->query("max_neili"))
me->add("neili",(random(lvl)+50));

return HIC "$n" HIC "全身功力如流水般源源不绝地流入$N的身体！\n" NOR;
        }
}

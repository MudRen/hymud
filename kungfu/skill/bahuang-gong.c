// bahuang-gong.c �˻�����Ψ�Ҷ���
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	int i = (int)me->query_skill("bahuang-gong", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t *= 2;

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if (
//		me->query_skill("beiming-shengong",1)
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
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) )
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�˻�����Ψ�Ҷ��𹦣���\n");
        return 1;
}

int practice_skill(object me)
{
	return notify_fail("�˻�����Ψ�Ҷ���ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"bahuang-gong/" + func;
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

return HIC "$n" HIC "ȫ��������ˮ��ԴԴ����������$N�����壡\n" NOR;
        }
}
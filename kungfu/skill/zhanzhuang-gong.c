// zhanzhuang-gong.c ������ ��ƽ����վ׮��
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i, nb, nf, nh, ns, ts;

	nb = (int)me->query_skill("buddhism", 1);
	nf = (int)me->query_skill("force", 1);
	nh = (int)me->query_skill("zhanzhuang-gong", 1);
	ns = (int)me->query("guilty");

	if ( me->query("couple/have_couple") )
		return notify_fail("�㳾Եδ�ˣ��޷�ѧϰ��ƽ����վ׮����\n");
	if ( me->query("sex/number") )
		return notify_fail("���Ѿ�����ɫ�䣬�޷���ѧϰ��ƽ����վ׮����\n");
	if ( nb < 100 && nb <= nh )
		return notify_fail("��������ķ���Ϊ�������޷������������ƽ����վ׮����\n");
	if ( nf < 10)
		return notify_fail("��Ļ����ڹ���򻹲������޷������ƽ����վ׮����\n");
	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷������������ƽ����վ׮����\n");

if (
	me->query_skill("bahuang-gong",1)
         || me->query_skill("bingxue-xinfa",1)
         || me->query_skill("wudu-shengong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ��ƽ����վ׮������\n");
	return 1;

}

int practice_skill(object me)
{
	return notify_fail("��ƽ����վ׮��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"zhanzhuang-gong/" + func;
}
int help(object me)
{
	write(HIC"\nվ׮����"NOR"\n");
	write(@HELP

    վ׮��ȫ����ƽ����վ׮����Ϊ�������ɱ����ڹ���
    ��������ע�ظ�����Ҫ�������վ�ȣ����ն�����ϰ����ƽָ����
����׮ʱ��ͷƽ����ƽ����ƽ��ϥƽ����ϰʱ��������ˮ������Щ��λ��
��ϰ�����У�������ˮ�����

	ѧϰҪ��
		�����ڹ�10��
		�����ķ���Ϊ��������ƽ����վ׮��
		������������
HELP
	);
	return 1;
}


// honghua-shengong.c �컨��
// Last Modified by winder on Sep. 12 2001

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
	mapping skl = me->query_skills();
	string *sk;
	string skl_name = explode(__FILE__, "/")[<1][0..<3];
	int i = (int)me->query_skill("honghua-shengong", 1);
	int t = 1, j;

	if(i <= 100) for (j = 1; j < i / 10; j++) t *= 2;

if (
	me->query_skill("bahuang-gong",1)
|| me->query_skill("xuantian-wuji",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
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
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("taiji-shengong",1)||
me->query_skill("guiyuan-tunafa",1)||
me->query_skill("kongdong-xinfa",1)||
me->query_skill("taixuan-gong",1)||
me->query_skill("bitao-shengong",1)||
me->query_skill("jinghai-force",1)||
me->query_skill("wuzheng-xinfa",1)||
me->query_skill("lengyue-shengong",1)||
me->query_skill("huiyan-xinfa",1)||
me->query_skill("baiyun-xinfa",1)||
me->query_skill("songshan-qigong",1)||
me->query_skill("hanbing-zhenqi",1)||
me->query_skill("panshi-shengong",1)||
me->query_skill("bluesea-force",1)||
me->query_skill("qingming-xuangong",1)

 )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ����\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");
	if(i <= 100)
	{
		if (i > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("�����������̫���ˣ��޷���������ĺ컨�񹦡�\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("�����������̫���ˣ��޷���������ĺ컨�񹦡�\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("�컨��ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
	return __DIR__"honghua-shengong/" + func;
}
int help(object me)
{
	write(HIM"\n�컨�񹦣�"NOR"\n");
	write(@HELP

    �컨������ڹ��������ơ����Ƽ��˹�֮�á�

	ѧϰҪ��
		�����ڹ�10��
		��Ӧ������
HELP
	);
	return 1;
}

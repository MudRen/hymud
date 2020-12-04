// baiyun-xinfa.c �����ķ�
// Last Modify by sir 5/17/2001

#include <ansi.h>

inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_learn(object me)
{
	int i,nb,ny,ns;
	
	nb = (int)me->query_skill("buddhism", 1);
	ny = (int)me->query_skill("baiyun-xinfa", 1);
	ns = (int)me->query("guilty");
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
me->query_skill("songshan-qigong",1)||
me->query_skill("hanbing-zhenqi",1)||
me->query_skill("panshi-shengong",1)||
me->query_skill("qingming-xuangong",1)||
me->query_skill("bluesea-force",1)||
me->query_skill("honghua-shengong",1)
 )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ����\n");
	if ( me->query("couple/have_couple") )
		return notify_fail("�㳾Եδ�ˣ��޷���ѧϰ�����ķ���\n");	
	if ( me->query("gender") != "Ů��" )
		return notify_fail("�����ķ�ֻ�ʺ�Ů��������\n");
	if ( me->query("sex/number") )
		return notify_fail("��Ǵ�Ů֮���޷���ϰ�����ķ���\n");	
	if (((string)me->query("class") != "bonze") && i > 29)
		return notify_fail("�㲻����ã�ѧ���˸���İ����ķ���\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("��Ļ����ڹ���򻹲�����\n");

	if ( nb < 100 && nb <= ny )
		return notify_fail("��������ķ���Ϊ�������޷���������İ����ķ���\n");
	if ( ns > 0 ) 
		return notify_fail("���ŷ�ɮ�����䣬�޷���������İ����ķ���\n");
	return 1;
	
}

int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
	return __DIR__"baiyun-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n�����ķ���"NOR"\n");
	write(@HELP

  ��ɽ���ڹ�

	ѧϰҪ��
		�����ڹ�10��
		��Ů����֮��		
HELP
	);
        return 1;
}


inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }



int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("nei-bagua", 1);
        return lvl * lvl * 15 * 8 / 100 / 200;
}

int valid_learn(object me)
{
        if (me->query("gender") == "����" &&
            (int)me->query_skill("nei-bagua", 1) > 49)
                return notify_fail("���޸����ԣ������ѵ����޷�ѧϰ��������ڰ��ԡ�\n");

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
me->query_skill("jinghai-force",1)||
me->query_skill("wuzheng-xinfa",1)||
me->query_skill("lengyue-shengong",1)||
me->query_skill("huiyan-xinfa",1)||
me->query_skill("baiyun-xinfa",1)||
me->query_skill("songshan-qigong",1)||
me->query_skill("hanbing-zhenqi",1)||
me->query_skill("panshi-shengong",1)||
me->query_skill("bitao-shengong",1)||
me->query_skill("qingming-xuangong",1)||
me->query_skill("honghua-shengong",1)
 )
		return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ����\n");

	if( (string)me->query("family/family_name")!="�㵴��")
return notify_fail("�����书Ҫ���㵴�ɵ��������˲���ѧ��\n");

        if ((int)me->query_skill("force", 1) < 80)
                return notify_fail("��Ļ����ڹ���򻹲�����\n");

        if ((int)me->query_skill("wai-bagua", 1) < 100)
                return notify_fail("�������Թ����򻹲�����\n");

        return ::valid_learn(me);
}

int practice_skill(object me)
{
        return notify_fail("�ڰ���ֻ����ѧ(learn)�������������ȡ�\n");
}

string exert_function_file(string func)
{
        return __DIR__"nei-bagua/" + func;
}

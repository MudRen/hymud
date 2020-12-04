// necromancy.c

inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}

int valid_learn(object me)
{
	   if( userp(me))
     return notify_fail("BOSS�书�������š�\n");
	if( (int)me->query_skill("spells",1) < (int)me->query_skill("boss-ai",1))
		return notify_fail("��Ļ���ħ����Ϊ�������޷�����������ħ����\n");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"boss-ai/" + action;
}

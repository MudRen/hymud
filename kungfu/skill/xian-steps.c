// xian-steps.c from mool

inherit SKILL;

string *dodge_msg = ({
    "$nһ�������ϸ��衹������$N�Ĺ���Ʈ�𣬴��ݶ����һ�С�\n",
    "$nʹ��һ�С���ҹ�����ѡ�����Ȼ�������࣬���$N���˸��ա�\n",
    "$n����һҡ���ó�������Ӱ��һ�С���Ӱ��б���������$N�Ĺ��ơ�\n",
    "$nһ�С�����Ӱ�ɡ�����Ծ��ٿ��������$N���\n",
    "$n��һҡ����һ�Σ�һ�С����֪����������������\n",
    "$n˫��һ�㣬бб����ʹ���������ɡ�������$N��ࡣ\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int effective_level() { return 12;}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
            return notify_fail("�������̫���ˣ����������ɲ�����\n");

        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xian-steps/" + action;
}

//���������� dragonstep.c
// cglaem...12/19/96.

inherit SKILL;

string *dodge_msg = ({
	"����$n����һ�Σ���$N������Ử����\n",
            "ֻ��$n����һ�ˣ�����һ�Ű����У�$N��һ�ж�ʱû��Ŀ�ꡣ\n",
            "$nһת��һ�Ű���ð�𣬸�����$N�Ĺ��ơ�\n",
            "$n��������ڵ���һ�㣬�������ϰ�գ��ܿ���$N�Ĺ��ơ�\n",
            "$n��������ת����ǰ�׹�һ����$n�ѳ�����$N���\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{

	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 3 )
		return notify_fail("�������������������������������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -3);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"qiongya-bufa/" + action;
}

int power_point()	{	return 1.5;	}
int hard_point()	{	return 2;	}


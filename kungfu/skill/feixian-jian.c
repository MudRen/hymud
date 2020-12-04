inherit SKILL;
mapping *action = ({
    ([
      "action":
"$N����һ����$w���⻯Ϊ����׹⣬�ֱ���$n���ʺ����Ҽ硢�����ҽ��󼲴�",
	"damage":	150,
      "damage_type":	"����",
      ]),
    ([
      "action":
"$N���²�������������$w����ǰһ��,һƬ���ΰ׹���$n��ȥ��\n"
"$nʶ�����С�����С�ȡ�����������æ��ܲ���",
	"damage":	280,
      "damage_type":	"����",
      ]),
    ([
      "action":
"$N����Ծ������$w����������⣬��$n�����ŵ�ȥ��\n"
"���С��������ޡ���Ȼ��$n�Ƶ���æ����",
	"damage":	210,
      "damage_type":	"����",
      ]),
	
    ([
      "action":
"$N���类�������,ȹ��ƮƮ������$w��$n������£�\n"
"���С��������ˡ�����ǳ�����������,$n��ֱ������",
	"damage":	340,
      "damage_type":	"����",
      ]),
    ([
      "action":
"$N����Ʈ��,���μ�ת,ת�ۼ�ͳ���һƬ����һ������Ӱ����л���$n!\n"
"���С��������衹�ȱ���,���˵�,�����ڲ���֮��",
	"damage":	270,
      "damage_type":	"����",
      ]),
    ([
      "action":
"$N���潣�ߣ�Ѹ�����׵���$n��Χ����һ��������\n"
"$nֻ����Χ������Ӱ����ʱ���п�����һ��$w�����벻����\n"
"λ�ô�����ʵ����Σ������",
	"damage":	300,
      "damage_type":	"����",
      ]),
});

int valid_learn(object me)
{
    object ob;

    if (!(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
	return notify_fail("���������һ�ѽ�������������\n");
    
    return 1;
}

int valid_enable(string usage)
{
    return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{

    if ((int)me->query("qi") < 30)
	return notify_fail("�����̫�ͣ�������ȥ����Σ�յģ�\n");
    if ((int)me->query("neili") < 5)
	return notify_fail("�������������û�а취���÷��ɽ�����\n");
    me->receive_damage("qi", 30);
	me->add("neili", -5);
    //write("�㰴����ѧ����һ����ɽ�����\n");
    return 1;
}

int power_point()	{	return 1.75;	}
int hard_point()	{	return 2.5;	}

string perform_action_file(string func)
{
	return __DIR__"feixian-jian/"+func;
}

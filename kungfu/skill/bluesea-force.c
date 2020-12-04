// bluesea-force.c �Ϻ�����

#include <ansi.h>
inherit FORCE;

string *dodge_msg = ({
        "$n����������$N�Ľ������������ǽ�ϣ�û�а��Ч����\n",
        "$n���һ����һ������ֱ�������Ӳ����������$N��\n",
        "$n����һת��һ�����罫$N������ȫ�����⡣\n",
        "$n��Ȼ��Ц��΢΢�ƶ�����������ʹ$N�Ľ�����֮���塣\n",
});



mapping *actionf = ({
([      "action":"$N���һ����һָ��������$n��$l�������˷�Բ����ķ�Χ",
        "lvl" : 0,
        "attack": 15,        
        "force" : 200,
        "dodge" : 90,
        "parry" : 88,
        "damage": 170,
        "damage_type":  "����"
]),
([      "action":"$Nһ����ȣ��漴һ����������;ȴ��Ȼһָ����$n��$l",
        "lvl" : 10,
        "force" : 210,
        "attack": 15,
        "dodge" : 110,
        "parry" : 90,
        "damage": 160,
        "damage_type":  "����"
]),
([      "action":"$N��������������������$n�ļ�ͷ������ʳȴ����$n��$l��",
        "lvl" : 30,
        "force" : 215,
        "attack": 15,
        "dodge" : 85,
        "parry" : 85,
        "damage": 175,
        "damage_type":  "����"
]),
([      "action":"$N����һ�������������ƣ�˫����������$n��$l",
        "lvl" : 50,
        "force" : 220,
        "attack": 14,
        "dodge" : 80,
        "parry" : 90,
        "damage": 180,
        "damage_type":  "����"
]),
([      "action":"$N����ԭ�ز�����˫��ƽ�ƣ�һ��������ձ�$n��ȥ",
        "lvl" : 100,
        "force" : 235,
        "attack": 13,
        "dodge" : 80,
        "parry" : 95,
        "damage": 170,
        "damage_type":  "����"
]),
([      "action":"$N���°��Ͱ��ԣ��������Ī�⣬��������������������$n",
        "lvl" : 200,
        "force" : 200,
        "attack": 15,
        "dodge" : 85,
        "parry" : 115,
        "damage": 165,
        "damage_type":  "����"
]),
});

mapping *actionw = ({
([      "action":"$N���һ��������$w��������$n�������˷�Բ����ķ�Χ",
        "lvl" : 0,
        "force" : 250,
        "attack": 17,
        "dodge" : 10,
        "parry" : 110,
        "damage": 200,
        "damage_type":  "����"
]),
([      "action":"$Nһ����ȣ����е�$w�漴��ɨ$n����;ȴ��Ȼ����$n��$l",
        "lvl" : 30,
        "force" : 260,
        "attack": 16,
        "dodge" : 80,
        "parry" : 110,
        "damage": 220,
        "damage_type":  "����"
]),
([      "action":"$N��������������������$n�ļ�ͷ�����ֵ�$wȴ����$n��$l��",
        "lvl" : 80,
        "force" : 220,
        "attack": 17,
        "dodge" : 85,
        "parry" : 100,
        "damage": 210,
        "damage_type":  "����"
]),
([      "action":"$N����һ�������������ƣ����е�$w��������$n��$l",
        "lvl" : 150,
        "force" : 225,
        "dodge" : 75,
        "parry" : 120,
        "damage": 205,
        "damage_type":  "����"
]),
([      "action":"$N����ԭ�ز��������е�$wһ����һ��������ձ�$n��ȥ",
        "lvl" : 200,
        "force" : 220,
        "attack": 17,
        "dodge" : 80,
        "parry" : 125,
        "damage": 210,
        "damage_type":  "����"
]),
([      "action":"$N���°��ϰ��ԣ��������Ī�⣬���е�$w����������â������$n",
        "lvl" : 250,
        "force" : 220,
        "attack": 15,
        "dodge" : 60,
        "parry" : 110,
        "damage": 220,
        "damage_type":  "����"
]),
});

string *usage_skills = ({ "finger", "strike", "staff", "dodge", "dagger" ,
                          "parry", "force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_combine(string combo) { return combo=="wai-bagua" ; }


mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int level;
        int i;

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


      if (me->query_skill("three-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ��������Ž�������!\n");
      
      if (me->query_skill("blood-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ�����Ѫ�½�������!\n");

      if (me->query_skill("doomsword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ��������촵Ѫ��������!\n");

      if (me->query_skill("fy-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ�����������ƽ�����!\n");

      if (me->query_skill("siqi-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ��������潣������!\n");

      if (me->query_skill("qingpingsword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ�������ƽ��������!\n");

      if (me->query_skill("sharen-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ�����ɱ�˽�������!\n");

      if (me->query_skill("feixian-sword",1)< 300)
return notify_fail("�����书��Ҫ��ͨ���ֽ��������ɽ�������!\n");
      
      








	
	return 1; 


}

int practice_skill(object me)
{
        return notify_fail("�Ϻ�����������޷��򵥵�ͨ����ϰ������\n");
}


int ob_hit(object ob, object me, int damage)
{
        string result;
        int ap, dp, mp;

        if ((int)me->query_skill("bluesea-force", 1) < 200
        ||  ! living(me) || (int)me->query("neili") < 500 
        ||  me->query_skill_mapped("parry") != "bluesea-force"
        || random(2)==0)
                return damage;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("bluesea-force", 1);



        if (ap / 2 + random(ap) < dp && random(2)==0)
        {
                //me->add("neili", -300);
        damage=damage/8;
        if (damage < 10) damage=10;
if (userp(ob) && !ob->is_busy()) ob->start_busy(2);
 if (userp(me) && userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12> 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}
else {
             ob->add("qi",-500);
             ob->add("eff_qi",-500);
}
                switch (random(3))
                {
                case 0:
                        result = HIB "$N" HIB "Ĭ���Ϻ�������������סȫ��$n" HIB
                                            "һ�л���$N" HIB "��ֻ�����ִ�����ʯ���󺣣�"
                                            "��о��ȣ���æ�˻ء� \n" NOR;
                        break;
                case 1:
                        result = HIB "$n" HIB "һ�й�����$N" HIB "ŭ��һ��������"
                                            "���������ΰ����ǽ����$n" HIB "���бƻء�\n" NOR;
                        break;
                default:
                        result = HIB "$N" HIB "ȫ������������һ�������סȫ���ѽ�$n" HIB "��"
                                            "�н�����ʽ�������֮�⡣\n" NOR;
                        break;
                }
         message_vision(result, me, ob);        
        } 

return damage;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor) 
{
        int level   = (int) me->query_skill("bluesea-force",1)/10;
        
        if (me->is_busy()
           || ! living(victim)
           || damage_bonus < 80
           || me->query("neili") < 200
           || me->query_skill("bluesea-force", 1) < 250)
        	return 0;


        if (damage_bonus / 2 > victim->query_con() && random(3)==0)
        {
                me->add("neili", -30);
                if (victim->query("qi",1)> 500)
                victim->receive_wound("qi", ((damage_bonus - 88) / 2+1+level));
                if (victim->query("neili",1)> 500)
                victim->add("neili", -((damage_bonus - random(80)) / 2+1+level));

                return random(2) ? HIR "$N" HIR "��עȫ�������Ϻ����ΰ�Ϯ��$n" HIR "�����Ѩ��$n" HIR "�����޷��ֵ����������ˣ���Ѫ���£�\n" NOR:
                                   HIR "$n" HIR "Ӳ��$N" HIR "һ�У�����Է������纣�˰�Ϯ����$n" HIR "�͵��³�һ����Ѫ�������������ˣ�\n" NOR;
        }        
}



string perform_action_file(string action)
{
        return __DIR__"bluesea-force/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"bluesea-force/exert/" + action;
}


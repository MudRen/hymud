//sumi-jian.c.���޽���
//date:1997.9.6
//by dan,ysg
#include <ansi.h>     

inherit SKILL;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

int yunwu(object me, object victim, object weapon, int damage);
int ruhe(object me, object victim, object weapon, int damage);

mapping * action=({
    ([  "action":
"$Nһ�С��Կ��Ϻ�ӧ��������$w������Ȼ��һ�ɿ�����׳֮�����Ž���ǰָ����ɢ������
Ѹ���ޱȵĴ���$nü��",
        "lian"  :
"$N���羣������������$wбб�ӳ�����˵���޻��ڣ���������򲻵�֮�ƣ�����һ�С��Կ��Ϻ�ӧ����",
        "sen"   :8,
        "jibie" :10,
        "dodge" :30,
        "parry" :10,
        "force" :20,
        "wound" :10,
        	"damage" :230,
        "zhaoshi" : "���Կ��Ϻ�ӧ��",
        "damage_type":"����"   ]),
    ([  "action":
"����$n���У�$N��������һ�С�ʮ��ɱһ�ˡ�������$w���ѻ�֮������Ӱ���εĳ�$n���ϴ���",
        "lian"  :
"$Nչ������ʹ��һ�С�ʮ��ɱһ�ˡ�������$w��â������������������Ϊ��ָ�ᡣ",
        "sen"   :9,
        "jibie" :20,
        "dodge" :35,
        "force" :30,
        "parry" :15,
        "wound" :20,
        	"damage" :230,
        "zhaoshi" : "��ʮ��ɱһ�ˡ�",
        "damage_type":"����"    ]),
    ([  "action":
"ֻ������һ����$Nʹ��һ�С��ѽ�ϥǰ�᡹��������ֻ��һ�������Ľ���������ת��֮
��$nֻ����ǰ������������������",
        "lian"  :
"$N����$wһ����ʹ��һ�С��ѽ�ϥǰ�᡹��ֻ��������ɽ��������˺�����������졣",
        "sen"   :10,
        "jibie" :40,
        "dodge" :20,
        "parry" :0,
        "force" :30,
        "wound" :20,
        	"damage" :230,
        "zhaoshi" : "���ѽ�ϥǰ�᡹",
        "damage_type":"����" ]),
    ([  "action":
"$Nʹ��һ�С��������𾪡������潣�ߣ��ڿ�������һת������$w������������������
��$n�ĸ���Ѩ��",
        "lian"  :
"$N����һ����һ�С��������𾪡�������$w���������⡣",
        "sen"   :11,
        "jibie" :30,
        "dodge" :0,
        "parry" :30,
        "wound" :20,
        	"damage" :230,
        "zhaoshi" : "���������𾪡�",
        "damage_type":"����"    ]),
    ([  "action": 
"$N����һ�ӣ�һ�С���������Ӣ��������бָ������$w��һ�����벻���ķ���ֱ��$n���ʺ�",
        "lian"  : 
"$N����һ�࣬��������ɳ�����������������벻����һ����ʹ��������һ�С���������Ӣ����",
        "sen"   :12,
        "jibie" :100,
        "dodge" :20,
        "parry" :20,
        "force" :30,
        "wound" :40,
        	"damage" :330,
        "zhaoshi" : "����������Ӣ��",
        "damage_type" : "����"  ]),    
});

string *parry_msg = ({
"$n����һ��ƽ�ƣ�ʹ��һ�С��Կ��Ϻ�ӧ�������е�$v����һ�콣�꣬��$N�Ĺ������������С�\n",
"$n����һ�࣬ʹ��һ�С��ѽ�ϥǰ�᡹�����е�$v����ܲ�͸�ֻ꣬����һ��Ѹ���ı���
�Ӵ�֮�����Ŀ���$N��$w��\n",
"$n�����е�$vһ����һ�С��������𾪡������������⣬$N�پ��޴����֣�����ֻ�������Ա���\n",
"$n����һ�С���������Ӣ��������бָ������һ�����磬����$vһ�¾͵�����$N��$w��\n",
});

string *unarmed_parry_msg = ({
    "$n˫������ܲ�͸�磬ʹ������ʵ���项����ס��$N�Ĺ��ơ�\n",
    "$n����һ�С������ͼ򡹣��ܿ���$N����һ�С�\n",
    "$nʹ��һ�С�����ʵӦ������ס��$N�Ĺ��ơ�\n",
    "����$nһ�С����ܹ��ݡ����ȵ�$N�������ˡ�\n",
});

string query_parry_msg(object weapon)
{   
    if ( objectp( weapon ) )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
mapping query_action(object me, object weapon)
{
		int d_e1 = 15;
	int d_e2 = 30;
	int p_e1 = 25;
	int p_e2 = 15;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 310;
	int m_e2 = 410;
	int i, lvl,level, seq, ttl = sizeof(action);

        string *msg1,*msg2;
        
  msg1 = ({
		HIW"$N����$w"+HIW"�������裬��������������ʵʵ�����˶�Ŀ���仯�Ź�֮����$n�������º�Ȼ��"NOR,
		HIW"$N����$w"+HIW"ԽʹԽ�죬һ�ס��ٱ�ǧ�ú�ɽ����ʮ��ʽ�������ƾ���ӿ��$n���ɵ�ĿΪ֮ѣ��"NOR,
		HIW"����$N����$w"+HIW"���б�ã�������ȣ��廨���ţ�������$n������ǰ����һƬ���������ȥ��"NOR,
        });
        msg2 = ({
		HIR"����һ�����Ѫ��$w"+HIR"�½��˳�����$n��Ų��Ծ�������мܣ�ʼ���Ѳ���$N�Ľ������֣���Ѫ���������ܽ�����һ����Ȧ��$N���Ѵ̳�һ����"NOR,
		HIY"$Nһ����ռ�Ȼ����������������һ��$w"+HIY"�������ߣ�������������$n�Ĺ����д�����ȥ��ֻ�Ƶ�$n�������ˣ�"NOR,
		HIY"$n����һ������֮�£��������ˣ�$N����$w"+HIY"������������������������������䣬�仯�켫��"NOR,

        });        
        level   = (int) me->query_skill("sumi-jian",1);
        if ((int)me->query_skill("literate", 1)> 5 && userp(me) )	
return action[random(sizeof(action))];

	if(me->query_temp("ruhe_count") > 15 || me->query_temp("ruhe_hit")){
        me->add("jing", -30);	
        me->add("neili", -100);	
	me->set_temp("ruhe_finish");	
	me->delete_temp("ruhe_count");	
	me->delete_temp("ruhe_hit");	
        return ([
	"action":HIY"$N���ּ����ѱϣ�$w"+HIY"���У�����̩ɽ�ɽ����������ľ��ա������Ρ�����һ����׼��$n��һ��Ӧ�����ţ�ʵ��������ٱ��������"NOR,
        "force" : 450+random(20),
        "dodge" : 70,
        "parry" : 70,
        "damage": 520,
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }
	else if((int)me->query_skill("sword",1)> random(300)+100
 	&& me->query("neili") > 200 
	&& me->query_temp("ruhe") && random(2)==0){
        me->add("neili", -20);
        return ([
	"action":YEL"$N$w"+YEL"ٿ����$n�̳�������������ÿһ���Ľ��нԲ�Ȼ�й��⣬�������ӣ��ڲ���䣬���ǡ����򽣡�"NOR,
        "force" : 400+random(55),
        "dodge" : 10,
        "parry" : 15,
        "damage": 500+random(55),
        "skill_name" : "����",
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }

        else if((int)me->query_skill("sword",1) > random(280)+80
	&& me->query("neili") > 100
	&& me->query_temp("ruhe") && random(2)==0){
        me->add("neili", -10);
        return ([
	"action":HIC"$N��Ȼ��$n����������$w"+HIC"ʹ������������ˮ�����������߼��ᳵ������·֮�⣬��������������з��ӵ����쾡��"NOR,
        "force" : 333 + random(33),
        "dodge" : 10,
        "parry" : 15,
        "damage": 500+random(33),
        "skill_name" : "�����",
	"post_action": (: ruhe :),	
        "damage_type":  "����"]);
        }
else
if(me->query_temp("hengshan") 
	&& random(level) > 160 && random(2)==0){
        me->add("neili", -20);
        return ([
        "action":HIG"$N�ζ�$w��̤���ţ���ƫ�棬������˼����������ޱȣ�����ʵ�ң��ѵ���$n$l"NOR,
        "force" : 700,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 700,
        "damage_type":"����"]);
        }
        else if (me->query_temp("hengshan") 
        && random(level) > 100  && random(2)==0){
        me->add("neili", -20);
        return ([
        "action" : HIW"$N��������������б������â�Ӱ����ֱк��������$n��$lն��"NOR,
        "force" : 680,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 750,
        "damage_type":"����"]);
        }
else if(me->query_temp("yunwu") && me->query_temp("yunwu_hit")  && random(2)==0){
        me->add("neili", -20);
	me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 500,
        "damage_type":"����"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 550,
	"post_action": (: yunwu :),	
        "damage_type":"����"]);
        }


    return action[random(sizeof(action))];
}

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("��������޽������֮����һʱ��������ᡣ\n");

        if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("���̫���񹦻��̫ǳ��\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("�������Ǭ����Ϊ�������޷�������\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("�������ȭ��Ϊ�������޷�������\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("���������Ϊ�������޷�������\n");

		if (me->query_skill("sumi-jian", 1) > 251)
{
			if(me->query_skill("huanhe-dao", 1)+100 < me->query_skill("sumi-jian", 1))
		return notify_fail("����Ӻյ���Ϊ�������޷�������\n");
}	
			if(me->query_skill("huanhe-dao", 1) < 100)
		return notify_fail("����Ӻյ���Ϊ�������޷�������\n");
        return 1;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("������������޷���ϰ��\n");
	       if ((int)me->query_skill("taixuan-gong", 1) < 100)
                return notify_fail("���̫���񹦻��̫ǳ��\n");
 	if(me->query_skill("xiuli-qiankun", 1) < 250)
		return notify_fail("�������Ǭ����Ϊ�������޷�������\n");

	if(me->query_skill("wuyu-quan", 1) < 250)
		return notify_fail("�������ȭ��Ϊ�������޷�������\n");

	if(me->query_skill("sata-shenfa", 1) < 250)
		return notify_fail("���������Ϊ�������޷�������\n");

        if ((int)me->query_skill("literate", 1)> 5 )
                return notify_fail("�����̫�������֮����һʱ��������ᡣ\n");
			if(me->query_skill("huanhe-dao", 1) < 100)
		return notify_fail("����Ӻյ���Ϊ�������޷�������\n");

if (me->query_skill("sumi-jian", 1) > 251)
{
			if(me->query_skill("huanhe-dao", 1)+100 < me->query_skill("sumi-jian", 1))
		return notify_fail("����Ӻյ���Ϊ�������޷�������\n");
}		

	
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string func)
{
	return __DIR__"sumi-jian/"+func;
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int level, jiali, time,level2;
int i, ap, dpp, dpd, dpf,lvl;
	object weapon,weapon2;
	string type, msg;
	weapon = me->query_temp("weapon");
lvl = me->query_skill("taixuan-gong", 1);
        if (random(me->query_skill("taixuan-gong",1)) < 60 ||		             me->query_skill("force",1) < 100 )
        return 0;


if (me->query_skill_mapped("force") != "taixuan-gong")
return 0;
if (me->query("neili") < 500)
return 0;
if (me->query_skill_mapped("unarmed") != "taixuan-gong")
return 0;

        if ((int)me->query_skill("literate", 1)> 5 )	
return 0;
	jiali = me->query("jiali");

if (!jiali) jiali=90;
	if( damage_bonus > 20 && random(me->query_skill("taixuan-gong",1))>120 
	) {
	victim->receive_wound("qi", (random(jiali)+80));
return random(2) ? HIW "$N" HIW "һ�й�����������ǧ�����ˣ�̫���ھ�"
                                   "��ʱԴԴ����ӿ��$n" HIW "���ڣ�\n" NOR:
                                   HIW "$N" HIW "̫���ھ��ŷ���$n" HIW "ֻ��ȫ��һ"
                                   "�𣬵�ʱ�������������������߹ǣ�\n" NOR;
}
}



int ruhe(object me, object victim, object weapon, int damage)
{
        string *msg;
        msg = ({
		CYN"����$N������ָ���㣬����׼��$n����Ų��λ���ּ�ͦ�����У�\n"NOR,
		CYN"����$n���书��·�ѱ�$N�������������ۼ��ѱܿ�$N��������"+weapon->name()+CYN"����ֱ�ƶ�����\n"NOR,
        });
if (!victim) return 0;
if (!me) return 0;
if (!weapon) return 0;
if (!damage) return 0;
        if(damage==RESULT_DODGE && (int)me->query_skill("sword",1) 
> random(150)+100 && me->query_temp("ruhe")) {
                message_vision(msg[random(sizeof(msg))], me,victim);
if (!victim) return 0;
if (!me) return 0;
victim->start_busy(2);
//if (victim=me) return 0;
if (victim && me
&& !me->query_temp("dsauto")
&& !me->is_busy())
{
victim->start_busy(2);
me->set_temp("dsauto",1);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
me->delete_temp("dsauto");
}
                return 1;
	   }
}

int yunwu(object me, object victim, object weapon, int damage)
{

if (!victim) return 0;
if (!me) return 0;

        if(damage==RESULT_DODGE || damage==RESULT_PARRY) return 1;

	   else if ( !living(victim) && victim->query_skill("force") > 100 ) {
                message_vision(HIR"\n����$n�˿���һ��Ѫ����ӿȪ�����������ԭ��$p�н�������δ��������Ѫ�Ƶô��˿��м���������ȹ��죬�ֿɲ���\n" NOR, me,victim);
		me->delete_temp("yunwu");
                return 1;
	   }
	else{
if (!victim) return 0;
if (!me) return 0;
if (me->is_busy() ) return 0;
//if (victim=me) return 0;
	me->add("neili", -30);
        victim->start_busy(2);
        victim->receive_damage("qi", random(30)+30);
	me->set_temp("yunwu_hit", 1);
	if(victim && me)
        {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
}
	}
}

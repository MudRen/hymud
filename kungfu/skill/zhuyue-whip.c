//���±޷� by cigar 2002.01
inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string* skill_head =({
        "$N�������ˣ�ʹ��һ�� ����",
        "$N�������ܣ�һʽ ����",
        "$N����һ�ϣ�ʹ�� ����",
        "$N��ȻһЦ��һʽ �绨ѩ��",
        "$N����Ծ��ʹ�� Բ��",
});
string* skill_tail =({
        "������$w��Ϊһ�������¹����$n��$l��",
        "������$w��������Ӱ����$n��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��ɣ���������¹⡣",
        "��$w���Ҽ缱˦����������΢�����$n$l��",
});

mapping *action = ({
   ([   "action":
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪��һ��"+BLINK""+HIM"�����޺ۡ�"NOR"����Ȼ����$n�ĺ���",
     "dodge":     15,
                "parry":                10,
     "damage":     340,
     "damage_type":   "����"
   ]),
   ([   "action":
"����Ծ��$ņ��һ�����¹�ʧɫ��������$N����$w��������Ӱ��"+BLINK""+HIC"[����]"NOR"�ѽ�$n����",
     "dodge":     15,
                "parry":                25,
     "damage":     340,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����$w����һ��������$w������һ��,һʽ"+BLINK""+HIB"[����]"NOR"���ε�Ʈ��$n������",
     "dodge":     10,
                "parry":                15,
     "damage":     335,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w����һ����˿������û����������¹⻯��ƬƬѩ������$n����Ʈ������������һ��"+BLINK""+HIW"[�绨ѩ��]"NOR"",
     "dodge":     10,
                "parry":                15,
     "damage":     350,
     "damage_type":   "����"
   ]),
   ([   "action":
"ͻȻ֮���¹�ʧɫ��$N�����ϳ�һ�����̹⣬ʹ��һ��"+BLINK""+HIG"�����¡�"NOR"��$w���Ͽռ�˦��󣬶��ػ���$n$l�����������¹⣬�޴�����",
     "dodge":     20,
                "parry":                10,
     "damage":     455,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_neili") < 50 )
     return notify_fail("�������������û�а취�����±޷���\n");

        if ((int)me->query_skill("bitao-shengong", 1) < 220)
                return notify_fail("��ġ������ķ������̫ǳ��\n");

        if ((int)me->query_skill("yubi-jian", 1) < 220)
                return notify_fail("��ġ�����»������������̫ǳ��\n");


   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("���������һ�ѱ��Ӳ������޷���\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}


mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("zhuyue-whip",1);
         lvl = (int)me->query_skill("zhuyue-whip", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
   if( (int)me->query("qi") < 30
   ||   (int)me->query("neili") < 3 )
     return notify_fail("�����������������û�а취��ϰ���±޷���\n");
   me->receive_damage("qi", 25);
   me->add("neili", -3);
   //write("�㰴����ѧ����һ�����±޷���\n");
   return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhuyue-whip/" + action;
}




mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("bitao-shengong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("zhuyue-whip",1))+50;
if (damage > 1600) damage=1600;
if (me->is_busy()) return;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "bitao-shengong" )
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
		return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;

}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("zhuyue-whip",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

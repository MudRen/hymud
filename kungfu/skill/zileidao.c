// zileidao.c �����׵�����

#include <ansi.h>

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string* skill_head =({
        "$N�������ˣ�ʹ��һ�� ���ױ�����",
        "$N���쳤Ц����Ҳ������һ�� ���׵���",
        "$N����һԾ��ʹ�˸� ���ױ���",
        "$N��̬���У�һ�� ��������",
        "$N����ת����ͣ��ͻȻһ�� ���������",
        "$N����̤�˸���������һ�� ��������",
});

string* skill_tail =({
        "������$w����������$n����һն",
        "������$w��׼$n��$l���һն",
        "�����ֽ�$w��׼$n$lһ����ȥ",
        "������$w����ػ���$n��$l",
        "�����ֶ�׼$n$lһ����ȥ",
        "����$nת��֮�ʣ��ӳ�һ��",
});


mapping *action = ({
        ([      "action":		"$N�ḧ���е�$w��ͻȻ��ֻ������һ������������һ����\nʹ��һ��"YEL"�����ױ�����"NOR"�������̹ǵĺ�����ȻϮ����$n��$l",
     		"dodge":     15,
     		"parry":     5,
     		"damage":    325,
     		"damage_type":     "����"
        ]),
        ([      "action":		"ֻ��$N����$w�����μ��壬������$n����֮�ʣ�һ��"HIR"�����׵�����"NOR"ͻȻ����һ����$n����б������",
     		"dodge":     15,
     		"parry":     5,
                "damage":    330,
                "damage_type":     "����"
        ]),
        ([      "action":		"$Nб����𣬴���һƬƥ��Ҳ�Ƶĵ������$n��$l����һ��"HIG"��������ת��"NOR"��",
                "dodge":     15,
     		"parry":     5,
                "damage":    335,
                "damage_type":     "����"
        ]),
        ([      "action":		"$NͻȻһ���߳���ʹ��"HIY"������������"NOR"�����е�$w����һ�������Բ����\n�����ĵ����ס��$n��ͷ�����ж���$n�ĺ���",
                "dodge":     15,
     		"parry":     5,
                "damage":    330,
                "damage_type":     "����"
        ]),
        ([      "action":		"ֻ��$N��ɫһ����һ��"HIB"�������������"NOR"ʹ������ü�ݵ��Ÿ���\n$n�����ѪҺ���Ʊ����޾��ĵ��ƶ�ס��������Ҳ�·�Ҫ�����ȥ",
                "dodge":     15,
     		"parry":     5,
                "damage":    340,
                "damage_type":     "����"
        ]),   
        ([      "action":		""HIM"�����ױ�������"NOR"ʹ����$N���ƽ�������$w�ϴ����ĺ���ȴԽ��ԽŨ��\n������ʱ��$n����ͷһ����һ������⻹Ҫ�����ĺ����Ѵ�����$n$l",
                "dodge":     15,
     		"parry":     5,
                "damage":    350,
                "damage_type":     "����"
        ]),   
        ([      "action":		"$NҲ�������߶�ʮһ���߾�$w�����ؾ���һ����$nӭ��ն�£�\n��Ȼֻ��һ�������µĵ���ȴ����Ų����ĺ���������$n��һ����·��\n����"HIC"��ŭ��˺���ѵء�"NOR"�ú���",
                "dodge":     15,
     		"parry":     5,
                "damage":    560,
                "damage_type":     "����"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취�����׵���������Щ���������ɡ�\n");


  if( (string)me->query_skill_mapped("force")!= "lengyue-shengong")
     return notify_fail("���������񹦲���ѧ��\n");

if ((int)me->query_skill("baisheng-daofa", 1) < 200)
		 return notify_fail("��İ�ʤ���� ��򲻹����޷�ѧ��\n");

if ((int)me->query_skill("daojian-guizhen", 1) < 100)
		 return notify_fail("��ĵ��������򲻹����޷�ѧ�֡�\n");


if( (int)me->query_skill("martial-cognize",1) < 200 )
		return notify_fail("�����ѧ����������\n");

	if( (int)me->query_skill("sixiang-bufa",1) < 200 )
		return notify_fail("������󲽷�������\n");


   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "blade" )
     return notify_fail("���������һ�ѵ�������������\n");

        return 1;
}

int valid_enable(string usage)
{
  return usage =="blade" || usage=="parry";
}



int practice_skill(object me)
{
        if( (int)me->query("qi") < 60 || (int)me->query("neili") < 50 || (int)me->query("jing") < 60 )
                return notify_fail("�����������������û�а취��ϰ���׵�����\n");

       if( (int)me->query("max_neili") < 600 )
                return notify_fail("�������������û�а취�����׵���������Щ���������ɡ�\n");


  if( (string)me->query_skill_mapped("force")!= "lengyue-shengong")
     return notify_fail("���������񹦲���ѧ��\n");

if ((int)me->query_skill("baisheng-daofa", 1) < 200)
		 return notify_fail("��İ�ʤ���� ��򲻹����޷�ѧ��\n");

if ((int)me->query_skill("daojian-guizhen", 1) < 100)
		 return notify_fail("��ĵ��������򲻹����޷�ѧ�֡�\n");


if( (int)me->query_skill("martial-cognize",1) < 200 )
		return notify_fail("�����ѧ����������\n");

	if( (int)me->query_skill("sixiang-bufa",1) < 200 )
		return notify_fail("������󲽷�������\n");


        me->receive_damage("qi", 30);
        me->receive_damage("jing", 30);
//        write("�㰴����ѧ����һ�����׵�����\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("zileidao",1);
         lvl = (int)me->query_skill("zileidao", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
        string msg;
        int ap,dp;
	
	weapon = me->query_temp("weapon");	
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("lengyue-shengong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("zileidao",1))+50;
if (damage > 1600) damage=1600;

if (random(12)==0 && level2>=300 && me->query_skill_mapped("force") == "lengyue-shengong")
{
        ap = me->query_skill("blade");
        ap += 20+(me->query_str())*2;
        dp =  victim->query_skill("parry");
        
        weapon = victim->query_temp("weapon");	

   if(objectp(weapon) && me->query_skill("blade")>300){ 
        if( random(ap+dp) > dp && random(2)>0){
        if(me->query("neili") > random(victim->query("neili"))){
                         if(random(2)==0){  
                               weapon->unequip();       
                               victim->start_busy(3);
                               victim->receive_damage("qi", ap);  
                               victim->receive_wound("qi", ap);      
         msg = MAG"ֻ����������һ����$n���е�$w�ѱ������ɡ�$nҲ�����ħ�����ˡ�\n"NOR ;
                                msg = replace_string(msg, "$w", weapon->name());    
                               }
                        else{
                               victim->start_busy(3);
msg = HIM"ֻ�����ˡ���һ�����죬$n���е�$w�����ΰ����ĳ���²�ס������\n"NOR ;
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{
  msg = MAG"$N����ԣ�����������������ֻ����ž����һ���죬$n����$w�ѱ���������Ρ�\n"NOR ;
                                msg = replace_string(msg, "$w", weapon->name());

                                weapon->unequip();
                                //weapon->move(environment(victim));
                                weapon->set("name", "�ϵ���"+weapon->query("name"));
                                weapon->set("value", 0);
                                weapon->delete("long");
                                weapon->set("weapon_prop", 0);
}                                
                                }
                                }
                   else {       
         msg = HIM"ֻ�����ˡ���һ�����죬$n���е�$w�����ΰ����ĳ���²�ס��������Щ���֣�\n"NOR ;
                            msg = replace_string(msg, "$w", weapon->name()); 
                                                           }
                }

                return msg; 
    }
	
}		

if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "lengyue-shengong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("zileidao",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}



}


string perform_action_file(string action)
{
	return __DIR__"zileidao/" + action;
}



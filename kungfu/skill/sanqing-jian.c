
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

// sanqing-jian.c�����彣����
//for ��ʿ NPCs, if going to be used by players, need refine. 

/*
���彣��    dodge  -5    parry  15    damage  20
���ҹ�������Ʈ�ݣ���մ����֮������Ψ��̫������
����̫ʵ�á�
*/

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string* skill_head =({
        "$N�������ˣ�",
        "$N���쳤Ц����Ҳ������",
        "$N����һԾ��",
        "$N��̬���У�",
        "$N����ת����ͣ��ͻȻ ",
        "$N����̤�˸����ǲ���",
        "$N����̤�˸����Բ���",        
        "$N����̤�˸����ǲ���",                
        "$N����̤�˸����򲽣�",                        
});

string* skill_tail =({
        " ����$w����������$n����һն��",
        " ����$w��׼$n��$l���һն��",
        " ���ֽ�$w��׼$n$lһ����ȥ��",
        " ����$w����ػ���$n��$l��",
        " ���ֶ�׼$n$lһ����ȥ��",
        " ��$nת��֮�ʣ��ӳ�һ����",
        " ����$w��Ϊһ�������¹����$n��$l��",
        " ����$w������콣Ӱ����$n��",
        " ����$w��ƫһ�ᣬֱ��$n��$l��",
        " ����$w��ɣ���������¹⡣",
        " $w���Ҽ缱˦����������΢�����$n$l��",
});



mapping *action = ({
   ([   "action":     "$Nʹ��һ��"+BLINK""+HIR"���Ǻ�Ӱ����"NOR+"��������˸�������������޵ش���$n$l",
     "dodge":     0,
     "parry":     15,
     "damage":     335,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����ת����ͣ��ͻȻһ��"+BLINK""+HIY"��һ����Ϭ��"NOR+"ʹ��������$w����һ������������$n$l",
     "dodge":     10,
     "parry":     15,
     "damage":     345,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����̤�˸����ǲ���һ��"+BLINK""+HIM"���ŵ����硹"NOR+"����$w����������$n����һն",
     "dodge":     15,
     "parry":     15,
     "damage":     340,
     "damage_type":   "����"
   ]),
   ([   "action":     "����$N���˼�������Ȼ������Ծ������$wһʽ"+BLINK""+HIW"���׺�������"NOR+"��׼$n��$l���һն",
     "dodge":     15,
     "parry":     5,
     "damage":     350,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����һԾ��ʹ�˸�"+BLINK""+HIB"���˷��ȥ��"NOR+"��ȴ��ת��֮�ʶ�׼$n$lбб�ӳ�һ��",
     "dodge":    35,
     "parry":     25,
     "damage":     335,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N��̬���У�����$wƾ��һָ��һ��"+BLINK""+HIC"������ǧ�ء�"NOR+"����ػ���$n��$l",
     "dodge":     10,
     "parry":     10,
     "damage":     440,
     "damage_type":   "����"
   ]),
   ([   "action":     "$N����$w����һ�֣�ʹһ��"+BLINK""+HIG"������ͨ�ġ�"NOR+"���ֶ�׼$n$lһ����ȥ",
     "dodge":     30,
     "parry":     20,
     "damage":     435,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_neili") < 50 )
     return notify_fail("�������������û�а취�����彣����\n");

     if( (string)me->query_skill_mapped("force")!= "kongdong-xinfa")
     return notify_fail("��������ķ�����ѧ��\n");

if ((int)me->query_skill("kongling-jian", 1) < 200)
		 return notify_fail("��Ŀ��齣��򲻹����޷�ѧ��\n");

if ((int)me->query_skill("qishang-cuff", 1) < 200)
		 return notify_fail("�������ħȭ��򲻹����޷�ѧ�֡�\n");


if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("���ʮ��ս������\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("��������ʽ������\n");

	if( (int)me->query_skill("kongling-jian",1) < 200 )
		return notify_fail("��Ŀ��齣��������\n");


   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ�ѽ�������������\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("sanqing-jian",1);
         lvl = (int)me->query_skill("sanqing-jian", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("kongdong-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("sanqing-jian",1))+50;
if (damage > 1600) damage=1600;
if (me->is_busy()) return;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "kongdong-xinfa")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("sanqing-jian",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

int practice_skill(object me)
{
   if( (int)me->query("qi") < 100
   ||   (int)me->query("neili") < 30 )
     return notify_fail("�����������������û�а취��ϰ���彣����\n");

    if( (string)me->query_skill_mapped("force")!= "kongdong-xinfa")
     return notify_fail("��������ķ�����ѧ��\n");

if ((int)me->query_skill("kongling-jian", 1) < 200)
		 return notify_fail("��Ŀ��齣��򲻹����޷�ѧ��\n");

if ((int)me->query_skill("qishang-cuff", 1) < 200)
		 return notify_fail("�������ħȭ��򲻹����޷�ѧ�֡�\n");


if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("���ʮ��ս������\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("��������ʽ������\n");

	if( (int)me->query_skill("kongling-jian",1) < 200 )
		return notify_fail("��Ŀ��齣��������\n");
		
   me->receive_damage("qi", 32);
   me->add("neili", -6);
//   write("�㰴����ѧ����һ�����彣����\n");
   return 1;
}
string perform_action_file(string action)
{
	return __DIR__"sanqing-jian/" + action;
}



 

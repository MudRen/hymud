// �����硤���μǡ��汾��������
/* by cigar 2002.01 */
 
//�����ջ��촸��??

inherit SKILL;
#include <ansi.h>
#include <combat.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";
string* skill_head =({
        "$N���ȽŲ���һ�� ���ܻ���",
        "$N˫��һ�𣬷���һ�� ����",
        "$Nһ������ʹ��һ�� ����",
        "$Nһ����Х��ʹ�� ������",
        "$N���һ��ʹ�� ����",
        "$N��$n����֮�ʣ�һ�� ����һ��",
        "$Nһ�� �̹ſ���",
        "$N˫��һ�𣬷���һ�� Ů�в���",
        "$Nһ������ʹ��һ�� ������о",
        "$Nһ��������Х��ʹ�� ����һ��",
        "$Nʹ�� �������",

        "$N��$n����֮�ʣ�һ�� �������",
});

string* skill_tail =({
        "������$w�д������հ���ȶȣ���ͷ�����ؾ���$n����������",
        "����$n��ͷ����������������",
        "������$wбб���������׹�����$n��$l",
        "������$wһ���ɨ�������յ�����ֱ��$n",
        "��ֱ���$n�ڽں��ˡ�",
        "������$wƮ�첻�����������⣬$n��ʱ��æ���ң�",
        "������$w�д������װ����������ͷ�����ؾ���$n����������",
        "����$n��ͷ����������������",
        "������$wбб������$n��$l",
        "������$wһ���ɨ��ֱ��$n",
        "��ֱ���$n�ڽں��ˡ�",
        "������$wƮ�첻����$n��ʱ��æ���ң�",
});
mapping *action = ({
  ([   "action":   "$N����$wһת������һ��ǿ����"+BLINK""+HIR"[��������]"NOR"֮������$n��$l��
��һ�������������ң��ƴ����ݣ��ۼ��͵���$n��ǰ",
     "dodge":   10,
     "parry":   10,
     "damage":   350,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N˫��һ��������$w�д���"+BLINK""+HIR"[����]"NOR"�����������ͷ�����ؾ���$n���˹�ȥ",
     "dodge":   15,
     "parry":   15,
     "damage":   40,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N��$w�߾ٹ��磬�����������׼$n��$l����"+BLINK""+HIY"[����֮��]"NOR"",
     "dodge":   20,
     "parry":   20,
     "damage":   335,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N�������飬����$w���Ϻ��£�˦��"+BLINK""+HIY"[���ܻ���]"NOR"����׽������ȥ·��
����$nһ��㱼䣬��ৡ�������$n��$l",
     "dodge":   10,
     "parry":   10,
     "damage":   325,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N����$n����֮ʱ����ת$w����������$n��
��һ����"+BLINK""+HIR"[�һ�]"NOR"��������Ϣ��������$n��$l",
     "dodge":   10,
     "parry":   10,
     "damage":  325,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N�ֳ�$w����"+BLINK""+HIR"[����]"NOR"����һ�����δ�Ȧ�������Χɳ�����
��$n���ܱ���֮ʱ������$wбб�ط���$n��$l",
     "dodge":   20,
     "parry":   25,
     "damage":  340,
     "damage_type":   "����",
   ]),
(["action" : "$Nһ����Х����ֱ��$n�����п��Ƽ򵥡�������������������������
�ഫԴ���̹ſ���ʱ���õ�"+BLINK""+HIW"[������]"NOR"�޼�������",
    "dodge" : 20,
    "damage" : 400,
    "lvl" : 120,
    "skill_name" : "���ձ���",
    "damage_type" : "����"
]),
  ([   "action":   "$N����$wһת������һ��ǿ���ķ�������$n��$l��
��һ���ּ����ͣ��ƴ����ݣ��ۼ��͵���$n��ǰ",
     "dodge":   10,
     "parry":   10,
     "damage":   330,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N˫��һ������$w�д������װ����������ͷ�����ؾ���$n���˹�ȥ",
     "dodge":   15,
     "parry":   15,
     "damage":   430,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N��$w�߾ٹ��磬�����������׼$n��$l��������һ��",
     "dodge":   20,
     "parry":   20,
     "damage":   435,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N�������飬����$w���Ϻ��£�����׽������ȥ·��
����$nһ��㱼䣬��ৡ�������$n��$l",
     "dodge":   10,
     "parry":   10,
     "damage":   425,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N����$n����֮������ת$w�����Ѵ�����$n��
��һ���������о��������Ϣ�ĵ�����$n��$l",
     "dodge":   10,
     "parry":   10,
     "damage":   420,
     "damage_type":   "����",
   ]),
   ([   "action":   "$N����$w�ͻ��˸���Բ�����������ɳ�����
��$n���ܱ���֮�ǣ�����$wбб������$n��$l",
     "dodge":   20,
     "parry":   25,
     "damage":   430,
     "damage_type":   "����",
   ]),
(["action" : "$Nһ��������Х,��ֱ��$n�Ҽ磬���к��޻���,��ʤ�������ۻ룬
�ഫԴ���̹ſ���ʱ���õĻ���һ�ơ�",
    "dodge" : 20,
    "damage" : 500,
    "lvl" : 120,
    "skill_name" : "����һ��",
    "damage_type" : "����"
]),
});

int valid_learn(object me)
{
        object ob;

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("qingming-xuangong", 1) < 200)
                return notify_fail("�����ڤ�������̫ǳ��\n");

        if ((int)me->query_skill("songfeng-jian", 1) < 200)
                return notify_fail("����ɷ罣�����̫ǳ��\n");

        if ((int)me->query_skill("chuanhua", 1) < 200)
                return notify_fail("��Ĵ����������̫ǳ��\n");

        if ((int)me->query_skill("wuying-leg", 1) < 200)
                return notify_fail("�����Ӱ�Ȼ��̫ǳ��\n");

        if ((int)me->query_skill("cuixin-strike", 1) < 200)
                return notify_fail("��Ĵ����ƻ��̫ǳ��\n");           

        if ((int)me->query_skill("taoism", 1) < 200)
         return notify_fail("��ĵ������̫ǳ��\n");


        if ((int)me->query_skill("chengzi18po", 1) < 200)
                return notify_fail("��ĳ���ʮ����̫ǳ��\n");
                
        if ((int)me->query_skill("qingzi9da", 1) < 200)
                return notify_fail("������־Ŵ�̫ǳ��\n");             
                

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("���������һ�������������ջ��촸��\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="hammer" || usage=="parry";
}


int practice_skill(object me)
{
    object ob;
        if( (int)me->query("qi") < 50
        ||      (int)me->query("neili") < 50 )
                return
notify_fail("�����������������û�а취��ϰ���ջ��촸��\n");
 
 
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("qingming-xuangong", 1) < 200)
                return notify_fail("�����ڤ�������̫ǳ��\n");

        if ((int)me->query_skill("songfeng-jian", 1) < 200)
                return notify_fail("����ɷ罣�����̫ǳ��\n");

        if ((int)me->query_skill("chuanhua", 1) < 200)
                return notify_fail("��Ĵ����������̫ǳ��\n");

        if ((int)me->query_skill("wuying-leg", 1) < 200)
                return notify_fail("�����Ӱ�Ȼ��̫ǳ��\n");

        if ((int)me->query_skill("cuixin-strike", 1) < 200)
                return notify_fail("��Ĵ����ƻ��̫ǳ��\n");           

        if ((int)me->query_skill("taoism", 1) < 200)
                return notify_fail("��ĵ������̫ǳ��\n");


        if ((int)me->query_skill("chengzi18po", 1) < 200)
                return notify_fail("��ĳ���ʮ����̫ǳ��\n");
                
        if ((int)me->query_skill("qingzi9da", 1) < 200)
                return notify_fail("������־Ŵ�̫ǳ��\n");             
                

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "hammer" )
                return notify_fail("���������һ�������������ջ��촸��\n"); 
 
        me->receive_damage("qi", 30);
        me->add("neili", -35);
        //write("�㰴����ѧ����һ����ջ��촸��\n");
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"frht-hammer/" + action;

}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
        return action[random(sizeof(action))]["parry_msg"];
}




mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        int i;
        object target;

        level   = (int) me->query_skill("frht-hammer",1);       
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("qingming-xuangong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("frht-hammer",1))+50;


if ( me->query_skill_mapped("force") == "qingming-xuangong")
{
        if( random(8)==1 && random(level) > 200)
        {
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) ); 
        return HIY "�����ľ�!!��$N�͵�һ������һ����ת��$n���������$n����ӡ����ȥ��\n" NOR;
        }
 if (damage_bonus < 60) damage_bonus=60;
        if( random(8)==1 && random(level) > 180)
        {

        victim->receive_wound("qi", damage_bonus+50 );  
        return RED "���ľ�!! $n����һ��ֻ���ú�ͷһ��һ��Ѫ˿����ǹ���������\n" NOR;
  }
}
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "qingming-xuangong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("frht-hammer",1)) > 50 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("frht-hammer", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
             if ( random(3) == 0 && random(level) > 150){
         msg = RED"$N�����㷴�߶���ֱ��$n������������$n�˿�վ�ȣ������������ߣ���$n�ߵ�һʱ�޷����֣�\n"NOR;
         msg += RED"��������!!����$N��Ӱ���ε��߳����ţ�$n�³�һ����Ѫ!!��\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

if (userp(ob) && !ob->is_busy()) ob->start_busy(2);
        if (userp(me) && userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}

msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}



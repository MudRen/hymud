//�����Ȫ���� BY Cigar 2002.04.19
#include <ansi.h>
inherit SKILL;
#include <combat.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";
int yunwu(object me, object victim, object weapon, int damage);
string* skill_head =({
        "$N�������ˣ�ʹ��һ�� ���ף��",
        "$N�������ܣ�һʽ Ȫ��ܽ��",
        "$N����һ�ϣ�ʹ�� �����ϸ� ",
        "$N��ȻһЦ��һʽ ��ɽ����",
        "$N����Ծ��ʹ�� ʯ������",
});
string* skill_tail =({
        "������$w��Ϊһ�������¹����$n��$l��",
        "������$w������콣Ӱ����$n��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��ɣ���������¹⡣",
        "��$w���Ҽ缱˦����������΢�����$n$l��",
});

mapping *action = ({
        ([      "name":                 "��",
                "action":
"$Nһ�����е�$w�����г�ŵ������ѣ����������졣˲��̳�������$n��ʱ��æ���ң��ֲ�����ʵ",
                "dodge":                10,
                "parry":                20,
                "damage":               335,
                "damage_type":          "����"
        ]),
        
        ([      "name":                 "��",
                "action":
"$Nһ������$n��$n��æ���Ա�һ����\n"
"����$Nһ�˾������������������������ǧ�꣬�����غ�ͨ���̡����е�$wͻȻ���˹�����ת������$n��$l",
                "dodge":                20,
                "parry":                10,
                "damage":               310,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"$N����$w�������������⻷��һ����������$n��ǰ̤��һ���������������������ȥ��������������$N���ֽ�ָ�Ѵ���$n��$l",
                "dodge":                20,
                "parry":                20,
                "damage":               315,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"$Nһת������$n����ͷ��������ͷ�����£���ͷ˼���硣����$w��Ҹ�·��ִ���$n��$l",
                "dodge":                10,
                "parry":                10,
                "damage":               310,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"$N�������е�$w����Х���裺����ֱ����ǧ�ߣ�������������졣���϶��£�����$n��$l",
                "dodge":                10,
                "parry":                10,
                "damage":               325,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"$N����һ�࣬���е�$wƽ�Żӳ�������������������ñ���谮�����ˡ�����$n��$l",
                "dodge":                15,
                "parry":                15,
                "damage":               315, 
                "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"$N��ǰ̤���벽������$w�й�ֱ�����������������������ᣬ���������ơ�����$n��ǰ��",
                "dodge":                10,
                "parry":                10,
                "damage":               320,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"$N˫��һ�٣���������������ߣ�����֮���á������ߣ��ٴ�֮���͡�������գ�ͷ�½��ϣ�����$w����$n��ͷ��",
                "dodge":                15,
                "parry":                15,
                "damage":               320,
                "damage_type":          "����"
        ]),
   ([   "action":
"$nֻ����ǰһ�����ƺ�����$N����һ�ϣ����漴�ּ�$N�ص�ԭ�أ�ȴ�ƴ�δ�뿪��һ��"+BLINK""+HIM"�������޺���������"NOR"����Ȼ����$n�ĺ���",
     "dodge":     15,
                "parry":                110,
     "damage":     340,
     "damage_type":   "����"
   ]),
   ([   "action":
"����Ծ��$ņ��һ�����¹�ʧɫ��������$N����$w������콣Ӱ��"+BLINK""+HIC"[��Ȫ���»�����]"NOR"�ѽ�$n����",
     "dodge":    15,
                "parry":                25,
     "damage":     340,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N����$w����һ�̣�����$w������һ��,һʽ"+BLINK""+HIB"[����覴�����Ӱ]"NOR"���εĵ���$n������",
     "dodge":     10,
                "parry":                -5,
     "damage":     335,
     "damage_type":   "����"
   ]),
   ([   "action":
"$N���е�$w����һ����˿������û�������������ƬƬѩ������$n����Ʈ������������һ��"+BLINK""+HIW"[�绨ѩ�º�����]"NOR"",
     "dodge":     10,
                "parry":                5,
    "damage":     350,
     "damage_type":   "����"
   ]),
   ([   "action":
"ͻȻ֮�����ʧɫ��$N�����ϳ�һ�������⣬ʹ��һ��"+BLINK""+HIG"������"NOR"��$w���Ͽռ�˦��󣬻���$n$l�������㽣Ӱ�޴�����",
     "dodge":     20,
                "parry":                10,
     "damage":     355,
     "damage_type":   "����"
   ]),
});

int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("�������������û�а취����ɽ������\n");
        if( (string)me->query_skill_mapped("force")!= "huiyan-xinfa")
                return notify_fail("��ɽ����������ϻ����ķ���������\n");

        if ((int)me->query_skill("hengshan-sword", 1) < 220)
                return notify_fail("��ĺ�ɽ�������̫ǳ��\n");         

   if ((int)me->query_skill("huiyan-xinfa", 1) < 220)
                return notify_fail("��Ļ����ķ����̫ǳ��\n");

        if ((int)me->query_skill("luoyan-hand", 1) < 220)
                return notify_fail("��Ĵ������ֻ��̫ǳ��\n");

        if ((int)me->query_skill("qiuyan-nanhui", 1) < 220)
                return notify_fail("��������ϻػ��̫ǳ��\n");

        if ((int)me->query_skill("biluo-zhang", 1) < 220)
                return notify_fail("��ı����ƻ��̫ǳ��\n");           

        if( !(ob = me->query_temp("weapon"))
                || (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ�������������\n");

        return 1;
}

int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if( (int)me->query("qi") < 40 || (int)me->query("neili") < 30 )
                return notify_fail("�����������������û�а취��ϰ�����Ȫ������\n");

        if( (string)me->query_skill_mapped("force")!= "huiyan-xinfa")
                return notify_fail("��ɽ����������ϻ����ķ���������\n");

        if ((int)me->query_skill("hengshan-sword", 1) < 220)
                return notify_fail("��ĺ�ɽ�������̫ǳ��\n");         

        if ((int)me->query_skill("huiyan-xinfa", 1) < 220)
                return notify_fail("��Ļ����ķ����̫ǳ��\n");
                
        me->receive_damage("qi", 35);
        me->add("neili", -20);
        return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        int i;
        object target;

        level   = (int) me->query_skill("jiutian-sword",1);     
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("huiyan-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("jiutian-sword",1))+50;

if (damage > 1600) damage=1600;
if ( me->query_skill_mapped("force") == "huiyan-xinfa")
{
        if( random(6)==1 && random(level) > 180)
        {
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) ); 
        return HIY "������ʮ��ʽ!!�����ⶸ����$N�͵ط�������$n��\n" NOR;
        }
 if (damage_bonus < 60) damage_bonus=60;
        if( random(5)==1 && random(level) > 120)
        {

        victim->receive_wound("qi", damage_bonus );     
        return RED "$N���еĽ�ԽʹԽ�죬�������! һ����Ѫ��$n�����ϴ̳� ��\n" NOR;
  }
}
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "huiyan-xinfa")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("jiutian-sword",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}




string perform_action_file(string func)
{
return __DIR__"jiutian-sword/" + func;
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

mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
        int d_e1 = 5;
        int d_e2 = 30;
        int p_e1 = 20;
        int p_e2 = 5;
        int f_e1 = 100;
        int f_e2 = 250;
        int m_e1 = 210;
        int m_e2 = 390;
        int i, lvl, seq, ttl = sizeof(action);
        int level;
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
        if(me->query_temp("yunwu") && me->query_temp("yunwu_hit") ){
        me->add("neili", -20);
        me->delete_temp("yunwu_hit");
        return ([
        "action":msg2[random(sizeof(msg2))] ,
        "force" : 500,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 900,
        "damage_type":"����"]);
        }
        else if (me->query_temp("yunwu") ){
        me->add("neili", -20);
        return ([
        "action":msg1[random(sizeof(msg1))] ,
        "force" : 580,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 950,
        "post_action": (: yunwu :),     
        "damage_type":"����"]);
        }



        lvl = (int) me->query_skill("jiutian-sword", 1);
        for(i = ttl; i > 0; i--)
                if(lvl > action[i-1]["lvl"])
                {
                        seq = i; /* �������������� */
                        break;
                }
        seq = random(seq);       /* ѡ������������ */
        return ([
                "action"      : action[seq]["action"],
                "dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
                "parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
                "force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
                "damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
                "damage_type" : random(2) ? "����" : "����",
        ]);
}

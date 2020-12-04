//modified by vikee
//2000.10
inherit SKILL;
#include <ansi.h>;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string type() { return "martial"; }
string martialtype() { return "skill"; }
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int ruhe(object me, object victim, object weapon, int damage);
string* skill_head =({
        "$N�������ˣ�ʹ��һ�� ���������硹",
        "$N�����������У�ʹ��һ�� ��������硹",
        "$N�Ĵ����ߣ�һ�� [��������]",
        "$N��̬���У�һ�� �������пա�",
        "$N�й�ֱ����ͻȻһ�� ��������Ӱ��",
        "$N˫��һ�٣���ֱԾ��һ�� ���������ڡ�",
});

string* skill_tail =({
        "������$w��ͣ�ز�����",
        "������$w��׼$n��$l���һն",
        "�����ֽ�$w��׼$n$lһ����ȥ",
        "������$w����ػ���$n��$l",
        "������$wȥ��Ʈ��������ֻ����$n�ۻ�����",
        "������$w�����㺮�⣬ָ��$nǰ��Ѩ��",
});

mapping *action = ({
                ([      "name":                 "��������",
                "action":
"$N˫��һ�٣���ֱԾ������$w��ͣ�ز����ţ�\n"
"����ס$nȫ������"+BLINK""+HIC"���������硹"NOR"��Ȼ���޿ײ���",
                "dodge":                5,
                "parry":                10,
                "damage":                350,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�������",
                "action":
"$N����$w�����㺮�⣬ָ��$nǰ��Ѩ����$n��ר����־�ضԸ��Ž��У�\n"
"����$N������������$n��$l������"+BLINK""+HIM"��������硹"NOR"������ã�ʵ���ѷ�",
                "dodge":                15,
                "parry":                15,
                "damage":               340,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��������",
                "action":
"$N��$n�������ߣ�һ��"+BLINK""+HIY"[��������]"NOR",����$wȥ��Ʈ��������ֻ����$n�ۻ����ҡ�\n"
"�ô�������$N������������һ��$w����$n��$l����",
                "dodge":                15,
                "parry":                10,
                "damage":               335,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�����п�",
                "action":
"$N��������$w��������㺮�⣬��ס$n���ظ���ֻ��$n��������\n"
"����"+BLINK""+HIR"�������пա�"NOR"ֱ��ϸ�����ܣ�$nʵ�ڲ�֪$w��Ҫָ���Լ����Ϻδ�",
                "dodge":                25,
                "parry":                10,
                "damage":               335,
                "damage_type":          "����"
        ]),
        ([      "name":                 "������Ӱ",
                "action":
"$N����$w�й�ֱ�������ٴ���$n��ǰ�ġ�\n"
"����"+BLINK""+HIB"��������Ӱ��"NOR"���˶�Ŀһ�¡�$nֻ������һ����$w�Ѵ̵���$l",
                "dodge":                15,
                "parry":                15,
                "damage":               335,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��������",
                "action":
"$N����$w��$n�����ּ��̣�������$nҪ�м�ʱ��\n"
"$wȴͻȻת����$n�����㣡����"+BLINK""+HIG"���������ڡ�"NOR"ȷʵ���Ī��",
                "dodge":                10,
                "parry":                15,
                "damage":               345,
                "damage_type":          "����"
        ]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_neili") < 2500 )
                return notify_fail("���������Ϊ�����������ѧ��Ҳû�á�\n");

        if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
                return notify_fail("̩ɽ�������������ʯ�񹦲�������\n");
        if( me->query_skill("panshi-shengong", 1) < 200)
                return notify_fail("�����ʯ����Ϊ������\n");
        if( me->query_skill("kuaihuo-strike", 1) < 200)
                return notify_fail("��Ŀ��ʮ������Ϊ������\n");
        if( me->query_skill("taishan-sword", 1) < 200)
                return notify_fail("���̩ɽ����������\n");
        if( me->query_skill("fengshenjue", 1) < 200)
                return notify_fail("��ķ����������\n");
        if( me->query_skill("aohan-liujue", 1) < 200)
                return notify_fail("��İ�������������\n");

        if( me->query_skill("shiba-pan", 1) < 200)
                return notify_fail("���̩ɽʮ���̲�����\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ����������ϰ������\n");
        return 1;
}

int practice_skill(object me)
{
        object ob;
        int dod=(int)me->query_skill("dodge");
        int swo=(int)me->query_skill("yujianshu");

        if (dod<swo/2)
                return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("������Ƿ�ѣ�ǿ���������к����档\n");
        if ((int)me->query("neili") < 55)
                return notify_fail("���������㣬ǿ�����������߻���ħ��Σ�ա�\n");
        if( me->query_skill("aohan-liujue", 1) < 200)
                return notify_fail("��İ�������������\n");
                
        if( (string)me->query_skill_mapped("force")!= "panshi-shengong")
                return notify_fail("̩ɽ�������������ʯ�񹦲�������\n");
        if( me->query_skill("panshi-shengong", 1) < 200)
                return notify_fail("�����ʯ����Ϊ������\n");
        if( me->query_skill("kuaihuo-strike", 1) < 200)
                return notify_fail("��Ŀ��ʮ������Ϊ������\n");
        if( me->query_skill("taishan-sword", 1) < 200)
                return notify_fail("���̩ɽ����������\n");
        if( me->query_skill("fengshenjue", 1) < 200)
                return notify_fail("��ķ����������\n");

        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ����������ϰ������\n");

        me->receive_damage("qi", 30);
        me->add("neili", -35);

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword"||usage=="parry";
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
         int level;
         object target;
         mapping pre;
         string *skill, a, b;
        int i, lvl, seq, ttl = sizeof(action);
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
        "damage": 820,
        "post_action": (: ruhe :),      
        "damage_type":  "����"]);
        }
        else if((int)me->query_skill("sword",1)> random(300)+100
        && me->query("neili") > 200 
        && me->query_temp("ruhe")){
        me->add("neili", -20);
        return ([
        "action":YEL"$N$w"+YEL"ٿ����$n�̳�������������ÿһ���Ľ��нԲ�Ȼ�й��⣬�������ӣ��ڲ���䣬���ǡ����򽣡�"NOR,
        "force" : 400+random(55),
        "dodge" : 10,
        "parry" : 15,
        "damage": 800+random(55),
        "skill_name" : "����",
        "post_action": (: ruhe :),      
        "damage_type":  "����"]);
        }

        else if((int)me->query_skill("sword",1) > random(280)+80
        && me->query("neili") > 100
        && me->query_temp("ruhe")){
        me->add("neili", -10);
        return ([
        "action":HIC"$N��Ȼ��$n����������$w"+HIC"ʹ������������ˮ�����������߼��ᳵ������·֮�⣬��������������з��ӵ����쾡��"NOR,
        "force" : 333 + random(33),
        "dodge" : 10,
        "parry" : 15,
        "damage": 800+random(33),
        "skill_name" : "�����",
        "post_action": (: ruhe :),      
        "damage_type":  "����"]);
        }
                 level   = (int) me->query_skill("yujianshu",1);
         lvl = (int)me->query_skill("yujianshu", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
        
}
/*mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
*/
string perform_action_file(string action)
{
        return __DIR__"yujianshu/" + action;
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


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("panshi-shengong",1);
damage= 50+(int) me->query("neili",1)/20;
damage2=random(me->query_skill("yujianshu",1))+50;

if (damage > 1600) damage=1600;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "panshi-shengong")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage);
}
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("yujianshu",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}
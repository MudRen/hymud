// aohan-liuejue �������� 
// С��(JIA)  2001.9.26 

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



string *act1=({ 
"$N��¶�׹⣬���ȫ��������$wʹ������$n��", 
WHT"$N"WHT"�ᵶ����$n"WHT"�����������������ĺ���һ�С�����һƳ����Ҳ��ģ������"NOR, 
HIW"$N"HIW"�ᵶһɨ��һ�ɺ�������Ϯ����ֱ��$n"HIW"�����ǰ�������֮������һƳ����"NOR, 
HIW"$N"HIW"⧵ذ�$w"HIW"��ӣ�����һ����һ�С�����һƳ���������Ծ���ֱ���˵�������$n"HIW"��"NOR, 
HIW"$N"HIW"⧵ذ�$w"HIW"�ᵶһɨ����򵥵���һ��ֱ�ɾ��춯�أ������籩�꣬�Ե���ƥ��\n��һ�������������ȣ���Ӳ������$n"HIW"����������ˣ����ǰ�������֮��һ��������һƳ����"NOR, 
}); 

string *act2=({ 
"$N������������$w��$n��ͷ���£�", 
WHT"$N"WHT"ͻȻԾ������$w"WHT"�þ�����$n"WHT"���ƺ��ǰ��������ġ��������ߡ���"NOR, 
HIW"$N"HIW"ͻȻ������գ���������׹֮ʱ$w"HIW"����$n"HIW"��һ�ɵ��罫$n"HIW"�����ε�������ʹ��"NOR, 
HIW"$N"HIW"ͻȻ�������һ�С��������ߡ�������$w"HIW"����һ����������$n"HIW"��"NOR, 

HIW"$N"HIW"ͻȻ�����������$w"HIW"�ճ���$n"HIW"���£�ʹ�����ǰ��������ڶ���֮���������ߡ���\n$n"HIW"����ͷ�ϰ׹�������$w"HIW"δ�������溮���������������������ų���Ŀ����ֱ��$n��"NOR, 
}); 

string *act3=({ 
"$N������$w����һ�ӣ�����$n��$l��", 
RED"$N"RED"�����һ�����ȶ��ˣ�΢΢̧��ͷ����$n���ĵ�һЦ��"NOR, 
HIR"$n"HIR"��$N����ȻһЦ��ס��"HIR"������֮һ�С���ѩ����÷������һ�󵶷磬�졢�ݡ�׼�ؿ���$n"HIR"��"NOR,  
HIR"$N"HIR"���缲��ӵ�ɱ�£�$w"HIR"�ڿ��л���һ�����⣬���Ŵ̹Ǻ���������$n"HIR"��"NOR, 
HIR"$N"HIR"�����һ�����ȶ��ˣ�΢΢̧��ͷ����$n���ĵ�һЦ��$nһ����֮�ʣ�ȴ��֪�Ѿ�����$N�İ�������������֮����ѩ����÷��"HIR"��\n����Ю��һ����磬�����������ʱ�����仨���꣬����$n"HIR"����ÿһ�ؽ���Ϯ��"NOR,
}); 

string *act4=({ 
"$N��������˼�����ͻȻ�ֳ�������һ������$n��", 
MAG"$N���˼������ۼ�$n"MAG"���������ͻȻ����һ���ݺݿ�����"NOR, 
HIM"$N"HIM"����ز������ֽ�$w"HIM"����һ�������Ļ��ߣ�һ�С���֦زز������$n"HIM"��$l"HIM"��"NOR, 
HIM"$N"HIM"����ز������ֽ�$w"HIM"����һ�������Ļ��ߣ�һ�С���֦زز������$n"HIM"��$l"HIM"��"NOR, 

HIM"$N"HIM"����ز�������һת��ʹ�����ǰ����������ľ�֮����֦زز�����ᵶɨ��$n"HIM"��\n$w"HIM"ɢ����һ����Ĺ�â������������ѩ��֦�������޵���ʵ�������ƥ��"NOR, 
}); 

string *act5=({ 
"$N��ǿ����֧���ڵأ�˫�Ƚ���$w����$n��", 
YEL"$N"YEL"ͻȻ˫�ȼе���˫���ڵ���һ�ţ��˾�����$n"YEL"�����С�̤ѩѰ÷��Ҳ�м���ò�ƣ�"NOR, 
HIG"$N"HIG"���ȼе����������ʹ���������������֮��̤ѩѰ÷�����˵�������$n"HIG"��"NOR, 
HIG"$N"HIG"���ȼе����������ʹ���������������֮��̤ѩѰ÷�����˵�������$n"HIG"��"NOR, 
HIG"$N"HIG"����Ծ��ʹ���������������֮��̤ѩѰ÷�����������������Ȳ��ã�ӭ���Ѳ⣡\n$w"HIG"�������������һ��ɭ���ޱȵ���������ৡ���һ��һ��Ѫ�����$n"HIG"��$l"HIG"��"NOR, 
}); 

string *act6=({ 
HIY"$N"HIY"Ǳ�˱��ľ����������ģ�����������$w"HIY"��Ȼ�����ܺ������۳�һ�޴�ѩ�����ݺ����£�\n�������л�����ص���������Ȼ�ǰ�������֮��߾��硸���б��ġ���"NOR, 
HIY"$N"HIY"Ǳ�˱��ľ����������ģ�����������$w"HIY"��Ȼ�����ܺ������۳�һ�޴�ѩ�����ݺ����£�\n�������л�����ص���������Ȼ�ǰ�������֮��߾��硸���б��ġ���"NOR, 
HIY"$N"HIY"Ǳ�˱��ľ����������ģ�����������$w"HIY"��Ȼ�����ܺ������۳�һ�޴�ѩ�����ݺ����£�\n�������л�����ص���������Ȼ�ǰ�������֮��߾��硸���б��ġ���"NOR, 
HIY"$N"HIY"Ǳ�˱��ľ����������ģ�����������$w"HIY"��Ȼ�����ܺ������۳�һ�޴�ѩ�����ݺ����£�\n�������л�����ص���������Ȼ�ǰ�������֮��߾��硸���б��ġ���"NOR, 
HIY"$N"HIY"Ǳ�˱��ľ����������ģ�����������$w"HIY"��Ȼ�����ܺ������۳�һ�޴�ѩ�����ݺ����£�\n�������л�����ص���������Ȼ�ǰ�������֮��߾��硸���б��ġ���"NOR, 
}); 

mapping *action=({ 
(["action" : "", 
"skill_name" : "����һƳ", 
  "extra_damage" : 50, 
"damage_type" : "����", 
"lvl" : 0, 
]), 
(["action" : "", 
"skill_name" : "��������", 
    "extra_damage" : 60, 
"damage_type" : "����", 
"lvl" : 1, 
]), 
(["action" : "", 
"skill_name" : "��ѩ����÷",  
   "extra_damage" : 70, 
"damage_type" : "����", 
"lvl" : 2, 
]), 
(["action" : "", 
"skill_name" : "��֦زز", 
  "extra_damage" : 80, 
"damage_type" : "����", 
"lvl" : 2, 
]), 
(["action" : "", 
"skill_name" : "̤ѩѰ÷", 
  "extra_damage" : 90, 
"damage" : 0, 
"damage_type" : "����", 
"lvl" : 3, 
]), 
(["action" : "", 
  "skill_name" : "���б���", 
  "extra_damage" : 180, 
"damage" : 100, 
"damage_type" : "����", 
"lvl" : 4, 
]), 
}); 

string hit_msg1=HIB"һ��������$n��ʱ���綳���˱�����һ�㣬ȫ��Ӳ���ٲ�Ψ�裡\n"NOR; 
string hit_msg2=HIB"$n��������к���һ�֣�ȫ���ʱ��ֹ��������ѪҺ�������̣�\n"NOR; 

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); } 

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
        if( me->query_skill("shiba-pan", 1) < 200)
                return notify_fail("���̩ɽʮ���̲�����\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ���\n");

       if ((int)me->query_skill("blade", 1) >= 100) 
               return 1; 
       else if ((int)me->query_skill("blade", 1) < 100) 
               return notify_fail("��Ļ�������̫���ˣ������˰���������\n"); 
} 

int practice_skill(object me) 
{ 
       object weapon; 
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
       if (!objectp(weapon = me->query_temp("weapon")) 
       || (string)weapon->query("skill_type") != "blade") 
               return notify_fail("��ʹ�õ��������ԡ�\n"); 
       if ((int)me->query("qi") < 60) 
               return notify_fail("������������������˰���������\n"); 
       me->receive_damage("qi", 50); 
       return 1; 
} 

mapping query_action(object me, object weapon) 
{ 
       int i, level,lvl,lvll; 
string *act; 
mapping nac; 
       level   = (int) me->query_skill("aohan-liujue",1); 
lvll   = (int) me->query_skill("aohan-liujue",1); 
if (level<100) lvl=0; 
else if (level<250) lvl=1; 
else if (level<350) lvl=2; 
else if (level<550) lvl=3; 
else lvl=4; 
       for(i = sizeof(action); i > 0; i--) 
               if(level > action[i-1]["lvl"]) 
{ 
        if (level> 300) level=300;
switch(random(6)) 
{ 
case 0:nac=action[0];nac["action"]=act1[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 1:nac=action[1];nac["action"]=act2[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 2:nac=action[2];nac["action"]=act3[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 3:nac=action[3];nac["action"]=act4[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 4:nac=action[4];nac["action"]=act5[lvl];nac["damage"]=level+nac["extra_damage"];break; 
case 5: 
if (lvll > 700 && random(3)==0) {nac=action[4];nac["action"]=act6[lvl];nac["damage"]=level+nac["extra_damage"];break;} 
else {nac=action[0];nac["action"]=act1[lvl];nac["damage"]=level;break;} 
} 
return nac; 
} 
} 

mixed hit_ob(object me, object victim, int damage_bonus) 
{ 
        int level, jiali, time,level2,damage,damage2;
        object weapon;
        weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("panshi-shengong",1);
damage= 50+ (int) me->query("neili",1)/20;
damage2=random(me->query_skill("aohan-liujue",1))+50;
if (damage > 1000) damage=1000;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "panshi-shengong")
{
if (victim->query("qi")>= damage )
{
victim->apply_condition("cold_poison",5);
victim->receive_damage("qi", damage);
        victim->receive_wound("qi", damage/2);
}
        return hit_msg2; 
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("aohan-liujue",1)) > 150 ) 
{
          victim->receive_wound("qi", damage2+120);
        return hit_msg1;
}


} 


string perform_action_file(string action)
{
        return __DIR__"aohan-liujue/" + action;
}





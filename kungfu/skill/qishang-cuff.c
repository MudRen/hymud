// qishang-cuff
#include <ansi.h>
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action" : "$N�ڳ��б��ߣ����ּȿ��Һݣ��������죬һȭ��׼��$n���ϵ�$lֱ������",
        "force" : 190,
        "dodge" : 55,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N������֮��������һ������$n�ֱۣ��������һȭ���ѽ��ʵʵ����$n$l",
        "force" : 240,
        "dodge" : 5,
        "parry" : 20,
        "damage": 260,

        "lvl" : 5,
        "damage_type" : "����"
]),
([      "action" : "$N��$n����˵������Ȼ��ȭ��ȥ��ֻ�����һ�����죬��һ�������Ǵ���$n$l��",
        "force" : 260,
        "dodge" : 50,
        "parry" : 20,
        "damage": 250,

        "lvl" : 15,
        "damage_type" : "����"
]),
([      "action" : "$Nȭ����磬���������ȭ��������$n���ϣ���ȴ�Ʋ���ʹ�������������壬��˿����",
        "force" : 210,
        "dodge" : 55,
        "parry" : 20,
        "damage": 350,
        "lvl" : 25,
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀ���࣬һ��ߺ�ȣ�����ƾ�մ��˸��������������У�һȭֱ������$n��$l֮��",
        "force" : 400,
        "dodge" : 15,
        "parry" : 20,
        "damage": 350,

        "lvl" : 45,
        "damage_type" : "����"
]),
([      "action" : "$N���˼�������������һ�����ֱ۹Ǹ�����죬��������һ����һȭ����$n$l",
        "force" : 300,
        "dodge" : 55,
        "parry" : 20,
        "damage": 350,

        "lvl" : 55,
        "damage_type" : "����"
]),
([      "action" : "$Nһȭ�����������ֱۣ��ַ�ȭ������һ����������ת��������ǰ��ͦȭ�ͻ�",
        "force" : 270,
        "dodge" : 55,
        "parry" : 20,
        "damage": 300,
        "lvl" : 65,
        "damage_type" : "����"
]),
([      "action" : "$N˫��һ��һ�ȭ����п�ɽ������һ���������ڣ�ֱ����$n��$n�ؿ�һ����ֻ��������Ż",
        "force" : 350,
        "dodge" : 15,
"parry" : 20,
    "damage": 350,

        "lvl" : 75,
        "damage_type" : "����"
]),
([      "action" : "$N���һ����˫ȭ�������������δ��ȭ�ϰ�������ŭ�����࣬��Х���Ϯ��$n",
        "force" : 400,
        "dodge" : 55,
"parry" : 20,
    "damage": 380,

        "lvl" : 85,
        "damage_type" : "����"
]),
([      "action" : "$N˫Ŀ΢�أ�����Ʈ������ƮƮ������ȭ��ȴ�ǰ����ϢҲ�ޣ�$n��ز��΢����壬ȭ��������Ϯ�����",
        "force" : 300,
        "dodge" : 50,
"parry" : 20,
    "damage": 380,

        "lvl" : 75,
        "damage_type" : "����"
]),
    ([  "action":"$N������ȭ���أ�����ʹ��һ�С��������¡�����������$n��$l",
        "lian"  :"$N������ȭ���أ�����ʹ��һ�С��������¡����������������ζ��",
        "zhaoshi":"���������¡�",
        "jibie" : 5,
        "parry":    30,
        "dodge":    10, 
        "sen" : 10,
        "wound":15, 
        "damage" : 200,
        "damage_type":  "����"
    ]),
    ([  "action":"$N������Σ�ʹ��һ�С�����ʵӦ�������ƻ���Ϊʵ����$n��$l",
        "lian"  :"$N������Σ�ʹ��һ�С�����ʵӦ�������ƻ���Ϊʵ������������",
        "zhaoshi" : "������ʵӦ��",
        "jibie" : 10,
        "parry":15, 
        "dodge":15,
        "sen"  : 11,
        "damage" : 225,
        "damage_type":  "����"
    ]),
    ([  "action":"$Nʹ������ȭ����������ˮ����������ǰ��˫��ͬʱ����$n��$l",
        "lian" : "$Nʹ������ȭ����������ˮ����������ǰ��˫�������һ�ġ�",
        "zhaoshi" : "��������ˮ��",
        "jibie" : 7,
        "sen" : 12,
        "parry":30,  
        "wound":20, 
        "damage" : 350,
        "damage_type":  "����"
    ]),
    ([  "action":"$Nʹ��һ�С�����ī���������ڿ�Ծ�𣬶�׼$n��$l�����ĳ�����",
        "lian"  :"$Nʹ��һ�С�����ī���������ڿ�Ծ�𣬶��ſ�������һͨ��",
        "zhaoshi" : "������ī��",
        "jibie" : 30,
        "parry":15, 
        "sen" : 10,
        "damage" : 350,
        "damage_type":  "����"
    ]),
    ([  "action":"$N��������������ָһ��һ����һ�С�������������$n��$l",
        "lian"  :"$N��������������ָһ��һ����ʹ��һ�С��������������������Ӭ��",
        "zhaoshi" : "����������",
        "jibie" : 35,
        "parry":20, 
        "wound":20, 
        "sen" : 12,
        "damage" : 310,
        "damage_type":  "����"
    ]),
    ([  "action":"$N���η��裬һ�С���̽Ѱ����˫��ͬʱ��$n��$l���ƹ���",
        "lian" : "$N���η��裬ʹ��һ�С���̽Ѱ����˫��һ�����أ��������硣",
        "zhaoshi" : "����̽Ѱ��",
        "jibie" : 40,
        "parry":15, 
        "sen" : 10,
        "damage" : 345,
        "damage_type":  "����"
    ]),
    ([  "action":"$N���һ����һ�С���ɽ���롹���������£��Ʒ�����$nȫ��",
        "lian" : "$N���һ����һ�С���ɽ���롹���������£�����һ���Ʒ磬���Կ�����ʯ��",
        "zhaoshi" : "����ɽ���롹",
        "jibie" : 50,
        "sen" : 15,
        "parry":15,
        "wound":25, 
        "damage" : 360,
        "damage_type":  "����"
    ]),
});

string *parry_msg = ({
    "$n˫����㣬һ�С����Ƽ��ա�������׾ٵĵ�����$N��һ����\n",
    "ֻ��$n�㲻��أ�һ�С�˳ˮ���ۡ�����$N�Ĺ��ƻ������Ρ�\n",
    "����$n���˷�����˫��һ�ʹ��һ�С�Ҷ��ժ���������̻���Ϊ�ġ�\n",
});
    


string query_parry_msg(object weapon)
{   
    return parry_msg[random(sizeof(parry_msg))];
}
string  *msg = ({
""+(order[random(13)])+"$Nһȭ������ȭ���о����и������ֲ�ͬ�ľ������ֻ�$n��ȫ��������ʮ����ҪѨ"NOR"",
""+(order[random(13)])+"$N����һ��������˫ȭƽ�죬����������������ȭ���������ֲ�֮ͬ������$n��$l"NOR"",
""+(order[random(13)])+"$NĬ���񹦣�˫ȭ�����޶���ͻȻ�ڿ����г������ֲ�ͬ�ľ�����Ȼ����$n��ǰ��"NOR"",
""+(order[random(13)])+"$N��ȭһ�գ�Ĭ����Ϣ�����ֲ�ͬ�������Ŵ����ȭ���ֵ��ֿ�Ļ���$n��$l"NOR"",
""+(order[random(13)])+"ֻ��$N˫Ŀ��������������Ȼ���͵Ĵ����һ�����������£��������ޱ�֮��������$n��ȫ��"NOR"",
""+(order[random(13)])+"$Nһ����Х��˫Ŀ��죬ȭ·�󿪴��أ�ÿһȭ������������ŭ��ʯ���쾪���Ժ������ڼ������Ĵ�����"NOR"",

});

int valid_combine(string combo) { return combo=="shizi-zhan"; }

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="cuff";
}

int practice_skill(object me)
{
	if( (int)me->query("jing") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("neili") < 10 )
		return notify_fail("������������ˡ�\n");
	if( (int)me->query_skill("dahong-quan",1) < 200 )
		return notify_fail("��Ĵ��ȭ������\n");

	if( (int)me->query_skill("changquan",1) < 200 )
		return notify_fail("���̫�泤ȭ������\n");

	if( (int)me->query_skill("kongdong-xinfa",1) < 200 )
		return notify_fail("�������ķ�������\n");

	if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("���ʮ��ս������\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("��������ʽ������\n");

	if( (int)me->query_skill("kongling-jian",1) < 200 )
		return notify_fail("��Ŀ��齣��������\n");

	if( (int)me->query_skill("luoriquan",1) < 200 )
		return notify_fail("���������ȭ������\n");

	if( (int)me->query_skill("ill-quan",1) < 200 )
		return notify_fail("��Ĳ�άĦȭ������\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);

	return 1;
}

string perform_action_file(string func)
{
	return __DIR__"qishang-cuff/"+func;
}

mapping query_action(object me, object weapon)
{
        int i, level, neili, force;
        level   = (int) me->query_skill("qishang-cuff",1);
        force = me->query_skill("force");
        neili = me->query("neili");
        me->delete_temp("qishang_hit", 1);

        if (level > 100 && force > 150 && neili > 500 
            && me->query("max_neili") > 1000
            && me->query("jiali")
            && random(me->query_str()) > 15
            && random(3)>0
            ){
            me->set_temp("qishang_hit", 1);
            return([      
                   "action": msg[random(sizeof(msg))],                   
                   "force" : 400+random(350),
                   "damage" : 400+random(350),
                   "dodge" : 50+random(100),
                   "damage_type" : random(2)?"����":"����",
                   ]);
            }

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

void skill_improved(object me)
{
   object *ob;
   int i, skill;
   skill = me->query_skill("qishang-cuff", 1);
   if(me->query("max_neili") < skill*15 && skill < 200){
    switch(random(5)){
      case 0 : 
              tell_object(me, HIR"���ͷ����ѨͻȻһ����΢��ʹ���Ƿ������ˣ�\n"NOR);
              me->add("max_neili", -random(70));
              break;      
      case 1 : 
              tell_object(me, HIR"����������ѨͻȻ��ʹ�ѵ����Ǹ������ˣ�\n"NOR);
              me->add("combat_exp", -random(5000));
              break;
      case 2 : 
              message_vision(HIR"$N�������ˣ�ͻȻ���Դ󷢡��޷������ˣ�\n"NOR, me);
              ob = all_inventory(environment(me));
              for(i=0; i<sizeof(ob); i++) {
                if(!living(ob[i]) || ob[i]==me ) continue;
                if(!ob[i]->is_fight(me) ) ob[i]->fight_ob(me);
                }
              break;
      case 3 : 
              tell_object(me, HIR"���ϱ�����ѨͻȻһʱ�����ѵ������������ˣ�\n"NOR);
              me->add("max_qi", -random(70));
              break;
      case 4 : 
              tell_object(me, HIR"��ͻȻ�������������������н�ľˮ�������У��޷������ˣ�\n"NOR);
              me->set_skill("qishang-cuff", skill-2);
              break;
      }
//     me->unconcious();
     }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{


    if( damage_bonus < 60 ) return 0;
if (random(me->query_skill("qishang-cuff",1)) > 90
&& me->query_skill_mapped("force") == "kongdong-xinfa"
)
{
message_vision(HIR"$N��һȭ���У����߽���!\n"NOR,victim);
victim->receive_wound("qi", damage_bonus/2 );
}
    if(random(me->query_skill("qishang-cuff", 1)) > 50
       && random(me->query("neili")) > 500
       && random(me->query("combat_exp",1)) > victim->query("combat_exp",1)/3 ){
       if(victim->query("neili")/3 < me->query("neili"))
          victim->apply_condition("qishang_poison", 32+victim->query_condition("qishang_poison"));       
       else me->apply_condition("qishang_poison", 31+victim->query_condition("qishang_poison"));
        }
}    

int valid_learn(object me)
{
	if( me->query("max_neili") < 1000 )
		return notify_fail("��������������޷�������\n");

	if( (int)me->query_skill("dahong-quan",1) < 200 )
		return notify_fail("��Ĵ��ȭ������\n");

	if( (int)me->query_skill("changquan",1) < 200 )
		return notify_fail("���̫�泤ȭ������\n");

	if( (int)me->query_skill("kongdong-xinfa",1) < 200 )
		return notify_fail("�������ķ�������\n");

	if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("���ʮ��ս������\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("��������ʽ������\n");

	if( (int)me->query_skill("kongling-jian",1) < 200 )
		return notify_fail("��Ŀ��齣��������\n");

	if( (int)me->query_skill("luoriquan",1) < 200 )
		return notify_fail("���������ȭ������\n");

	if( (int)me->query_skill("ill-quan",1) < 200 )
		return notify_fail("��Ĳ�άĦȭ������\n");
						
	return 1;
}
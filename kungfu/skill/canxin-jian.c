//Cracked by Roath
// canxin-jian.c�����Ľ�����
// DHXY_EVIL 2000.7.5
#include <ansi.h>
inherit SKILL;
#include <combat.h>
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

#include "/kungfu/skill/eff_msg.h";
string* skill_head =({
        "$N����һ����һ�� ���쳤�ؾ���ʱ�����˺������޾��ڡ�",
        "$N�������ܣ�һʽ ���ٳ��ӹĳ���ҹ�������Ǻ������졹",
        "$N����Ծ��һ�� ����������»�Ȫ������ãã�Բ�����",
        "$N����ǧ��һʽ ���紵����ƮƮ�٣��������������衹",
        "$N���緢��һ�� �����ݼ�į�����ɣ��滨һ֦�����꡹",
        "$Nһ�����У�һʽ ���쳤�ؾ���ʱ�����˺������޾��ڡ�",
});

string* skill_tail =({
        "������$w����$n��ȫ��",
        "������$w����������⣬��$n�����ŵ�ȥ��",
        "������$w��ƫһ�ᣬֱ��$n��$l��",
        "������$w��âֱ��$n",
        "�����������ٳ���ʵ���ܲ���͸",
        "��$w����ɱ����$n��������",
});
mapping *action = ({
([      "name":   "��������",
    "action" : "$N������ת�����ֽ�ָ������ǰ��һ�紦�̴ٶ�������\n"
    "һ��"HIR"���������ܡ�"NOR"������$w���������һ�����϶�������$n��",
    "dodge" : 5,
    "damage" : 315,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "������",
    "action" : "$N���β�������ǰ�������������ϱ���һ��"HIR"�������֡�"NOR"��\n"
    "����$w��ǰ�·��̣�һ��ָ��$n",
    "dodge" : 10,
    "damage" : 320,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��ҹ����",
    "action" : "$N�����ǰ���ŵ���������$wͻ��ǰ�̣���ת�����\n"
    "ʹ��һʽ"HIR"����ҹ���"NOR"��������ƥ����й��$n",
    "dodge" : 5,
    "damage" : 325,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "����δ��Ե",
    "action" : "$Nƽ��бϴ����Բ��ֱ��˫�Ž��满������������$wʹ��һʽ"HIR"������δ��Ե��"NOR"��"
    "����������ת�������಻������$n",
    "dodge" : 5,
    "damage" : 335,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��˿�Ѷ�",
    "action" : "$N����̧�ۣ�����ǰ����Ϸ������ͦ����ƽ��������ǰ������$wʹ��\n"
    "һʽ"HIR"����˿�Ѷϡ�"NOR"����$n",
    "dodge" : 10,
    "damage" : 330,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "���Ѹ�",
    "action" : "$N���ϲ����������أ�����$wһʽ"HIR"�����Ѹ���"NOR"��"
    "����Բ�󣬴���$n",
    "dodge" : 0,
    "parry"  :15,
    "damage" :330,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "�̽�����",
    "action" : "$N�����˲������ֽ�ָ��ת������$wһ��"HIR"���̽�������"NOR"��"
    "��������ָ��$n",
    "dodge" : 10,
    "damage" : 340,
    "parry"  :15,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "����Զ",
    "action" : "$N�鲽�������ὣ�ؽ��������ϱ���һ��"HIR"������Զ��"NOR"ֱȡ$n",
    "dodge" : 5,
    "damage" : 340,
    "parry"  :25,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "�������һ����",
    "action" : HIG"\n��һ���������ɵ������ɣ��������һ�������������϶��£�"NOR,
    "dodge" : 15,
    "damage" : 40,
    "force"  : 300,
    "parry"  :10,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "����������Բȱ",
    "action" : HIG"\n�ڶ���������������Բȱ��������ңĪ���У����������ң�"NOR,
    "dodge" : 15,
    "damage" : 350,
    "parry"  :10,
    "force"  : 100,
    "lvl" : 0,
    "damage_type" : "����"
]),
([      "name":   "��������ʶ��Ů",
    "action" : HIG"\n����������������ʶ��Ů��ͬ������Ѱ��;��������ת������"NOR,
    "dodge" : 10,
    "damage" : 360,
    "parry"  :10,
    "force"  : 100,
    "lvl" : 0,
    "damage_type" : "����"
]),
       ([      "name":		"���������������У��������տ�������",
		"action":	"$Nһʽ"+HIG"���������������У��������տ�������"NOR"����̤���㡹λ��
����һ�Σ���$n��ǰ��ʧ��������$n���
һ��б�̣�����$w������Ϣ�ش���$n��$l",
 "dodge":        0,
"parry":        0,
		"damage":	420,
		"damage_tupe":	"����",
		"parry_msg":	"$Nһʽ���������������У��������տ�����������̤���㡹λ��
����һ�Σ���$n��ǰ��ʧ��������$n���",
		"parry_power":	10,
	]),
	([	"name":		"���ٳ��ӹĳ���ҹ�������Ǻ������졹",
		"action":	"$Nһʽ"+HIG"���ٳ��ӹĳ���ҹ�������Ǻ������졹"NOR"����ռ������λ��
����$w����һ������, �����ӵ�к�����$n$l",
 "dodge":        0,
		"parry":	0,
		"damage":	425,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ���ٳ��ӹĳ���ҹ�������Ǻ������졹����ռ������λ��
����$w����һ����Ӱ, �Ŀ�$n�Ĺ���",
		"parry_power":	10,
	]),
	([	"name":		"����������»�Ȫ������ãã�Բ�����",
		"action":       "$Nһʽ"+HIG"����������»�Ȫ������ãã�Բ�����"NOR"��������λ��
����$w��Ϊ���콣Ӱ��������������������$nȫ�����",
"dodge":        0,
		"parry":	10,
		"damage":	425,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ����������»�Ȫ������ãã�Բ�������������λ��
����$w��Ϊ���콣Ӱ������������������ס$Nȫ�����",
		"parry_power": 10,
	]),
	([	"name":		"��¥���������������д�Լ�����ӡ�",
		"action":	"$Nһʽ"+HIG"��¥���������������д�Լ�����ӡ�"NOR"����$n������ת��
��ΪһȦ��Ӱ���ڡ��ޡ�λͻ��һ������̩ɽѹ��֮ʽ����$n$l",
"dodge":        15,
		"parry":	0,
		"damage":	330,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ��¥���������������д�Լ�����ӡ�����$n������ת��
��ΪһȦ��Ӱ���㿪$n�Ĺ���",
		"parry_power":	10,
	]),
	([	"name":		"���紵����ƮƮ�٣��������������衹",
		"action":	"$Nһʽ"+HIG"���紵����ƮƮ�٣��������������衹"NOR"�����弱����ת��
�ڡ��롹λ��һ�����磬����$w৵ؿ���$n��$l",
 "dodge":        0,
		"parry":	0,
		"damage":	420,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ���紵����ƮƮ�٣��������������衹�����弱����ת��
�ڡ��롹λ��һ�����磬��ȥ$n�Ĺ���",
		"parry_power": 	10,
	]),
	([	"name":		"�����ݼ�į�����ɣ��滨һ֦�����꡹",
		"action":	"$Nһʽ"+HIG"�����ݼ�į�����ɣ��滨һ֦�����꡹"NOR"��ռס���ҡ�λ��
������$w��������ǹ⣬����$nȫ��",
 "dodge":        10,
		"parry":	10,
		"damage":	430,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ�����ݼ�į�����ɣ��滨һ֦�����꡹��ռס���ҡ�λ��
������$w��������ǹ⣬����$n��$l����ȥ$n�Ĺ���",
		"power_power":	10,
	]),
	([	"name":		"������Ը���������ڵ�ԸΪ����֦��",
		"action":	"$Nһʽ"+HIG"������Ը���������ڵ�ԸΪ����֦��"NOR"����̤��Ǭ����������λ��
����$w������������$n��$l��ȥ",
 "dodge":        0,
		"parry":	0,
		"damage":	520,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ������Ը���������ڵ�ԸΪ����֦������̤��Ǭ����������λ��
��$n�Ĺ��������˳�ȥ",
		"parry_power":	10,
	]),
	([	"name":		"���쳤�ؾ���ʱ�����˺������޾��ڡ�",
		"action":	"$Nһʽ"+HIG"���쳤�ؾ���ʱ�����˺������޾��ڡ�"NOR"���ɡ�������Ǭ�����ˣ�
����$w����һ��������$n$l��ȥ",
 "dodge":        10,
		"parry":	20,
		"damage":	530,
		"damage_type":	"����",
		"parry_msg":	"$Nһʽ���쳤�ؾ���ʱ�����˺������޾��ڡ����ɡ�������Ǭ�����ˣ�
����$w����һ�����絴����$n�ķ�â",
		"parry_power":	10,
	]),
});
int valid_enable(string usage) { 
    return (usage == "sword") || (usage == "parry");
}
int valid_learn(object me)
{
   object ob;

	if ((int)me->query("max_neili") < 800)
		return notify_fail(HIC"�������������\n"NOR);

	if ((int)me->query_skill("chuanyun-shou", 1) < 250)
		return notify_fail(HIC"��Ĵ��Ʋ�����\n"NOR);

	if ((int)me->query_skill("tianchang-zhang", 1) < 250)
		return notify_fail(HIC"����쳤�Ʋ�����\n"NOR);
	if ((int)me->query_skill("lingxu-bu", 1) < 250)
		return notify_fail(HIC"������鲽������\n"NOR);
	if ((int)me->query_skill("baiyun-xinfa", 1) < 250)
		return notify_fail(HIC"��İ����ķ�������\n"NOR);
	if ((int)me->query_skill("hengshan-jian", 1) < 250)
		return notify_fail(HIC"��ĺ�ɽ����������\n"NOR);	
	if ((int)me->query_skill("rousi-whip", 1) < 200)
		return notify_fail(HIC"�����˿�ֱ޲�����\n"NOR);	

	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("���Ľ���������ϰ����ķ���������\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ�ѽ���������\n");

   return 1;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 20;
	int d_e2 = 50;
	int p_e1 = 20;
	int p_e2 = 0;
	int f_e1 = 200;
	int f_e2 = 250;
	int m_e1 = 120;
	int m_e2 = 380;
	int i, lvl, level,seq, ttl = sizeof(action);
        level   = (int) me->query_skill("canxin-jian",1);
	if(me->query_temp("hengshan") 
	&& random(level) > 160 ){
        me->add("neili", -20);
        return ([
        "action":HIG"$N�ζ�$w��̤���ţ���ƫ�棬������˼����������ޱȣ�����ʵ�ң��ѵ���$n$l"NOR,
        "force" : 700,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 800,
        "damage_type":"����"]);
        }
        else if (me->query_temp("hengshan") 
        && random(level) > 100 ){
        me->add("neili", -20);
        return ([
        "action" : HIW"$N����һ��������б������â�Ӱ����ֱк��������$n��$lն��"NOR,
        "force" : 680,
        "dodge" : 35,
        "parry" : 20,
        "damage" : 850,
        "damage_type":"����"]);
        }

	lvl = (int) me->query_skill("canxin-jian", 1);
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
int practice_skill(object me)
{
object weapon;
object ob;
	if ((int)me->query_skill("baiyun-xinfa", 1) < 250)
		return notify_fail(HIC"��İ����ķ�������\n"NOR);
	if ((int)me->query_skill("hengshan-jian", 1) < 250)
		return notify_fail(HIC"��ĺ�ɽ����������\n"NOR);	
	if ((int)me->query_skill("rousi-whip", 1) < 200)
		return notify_fail(HIC"�����˿�ֱ޲�����\n"NOR);	

	if( (string)me->query_skill_mapped("force")!= "baiyun-xinfa")
		return notify_fail("���Ľ���������ϰ����ķ���������\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("���������һ�ѽ���������\n");
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 3 )
                return notify_fail("�����������������û�а취��ϰ���Ľ�����\n");
	me->add("qi", -30);
	me->add("neili", -3);
//        write(HIC"�������������ϣ������޺��³�Բ��\n"NOR,me);
	return 1;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
	int jiali, time,level2,damage,damage2;

        level   = (int) me->query_skill("canxin-jian",1);	
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("baiyun-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("canxin-jian",1))+50;

        level   = (int) me->query_skill("canxin-jian",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

if (damage_bonus < 30) damage_bonus=30;
if (damage > 1600) damage=1600;
  
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "baiyun-xinfa")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("canxin-jian",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}  
else
	if( random(10)==1 || random(level) > 160)
	{

        victim->receive_wound("qi", damage_bonus+10 );	
        return HIM "��Ӱ��������һ����Ѫ��$n���������!\n" NOR;
  }
  
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("baiyun-xinfa", 1);

        
            if ( random(8) == 0 || random(level) > 180){
          if (random(3)==0  && !ob->is_busy()) ob->start_busy(2);
         msg = HIG"$N��������ķ����³�һ����Ѫ!!��\n"NOR;
         msg += GRN"$N���˺ö���!!��\n"NOR;
if ((int)me->query("qi")<=(int)me->query("max_qi")*2)
{
             me->add("qi",(level+100));
             me->add("eff_qi",(level+100));
}
msg += damage_msg(damage, "����");
message_vision(msg, me, ob);
}

            return damage;
}

string perform_action_file(string action)
{
	return __DIR__"canxin-jian/" + action;
}
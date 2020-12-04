// lingboweibu.c �貨΢��
#include <ansi.h>

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";

string *dodge_msg = ({
        HIR"$n����һ�����ģ���������б���벽��ǡ�������貨΢���С��������塹�Ĳ��ӣ����˿�����\n"NOR ,
        HIC"$nʹ���������ѩ������бб���˼������ƺ������·���ȴ�ڼ䲻�ݻ��Ŀ�϶�ж����$N�Ĺ��ơ�\n"NOR,
        HIB"$N����ʽ�������԰�$nΧס����֪���ģ�$nһʽ�����Ʊ��¡���������Ȱ�Ŀ����Ȧ��\n"NOR,
        HIW"$nһʽ���������ҡ���հ֮��ǰ�������ں�$N��ʽ������$n���Ӽ��������֮�\n"NOR,
        HIY"$n����������ͻȻת��ʹ���ˡ������ϡ���$N�ӽ����ƣ����޷�����$nһƬ�½ǡ�\n"NOR,
        HIC"$n���һ����ʹ����է������������������̤��������̤ʵ֮ʱ�����������������ϡ�\n"NOR,
        HIG"$nһʽ��Ʈ�����񡹣�����б�����������ȼá���������δ�á������ü��������۵�$N�����\n"NOR,
        HIG"$nһʽ����Ѹ���ɡ����ƺ��Թ��Ե�̤����������ᣬÿһ����̤�ڱ������벻�������ڡ�\n"NOR,
        RED"����$n����Ʈ��������һ�ݣ����ѱܿ���\n"NOR,
        YEL"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n"NOR,
        GRN"����$n����һ�ã�$N��һ�����˸��ա�\n"NOR,
        HIG"ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n"NOR,
        HIW"$n����΢�Σ��о����յرܿ���$N��һ�С�\n"NOR
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move") || (usage == "parry"); 
}

int valid_learn(object me)
{
    if ((int)me->query_skill("literate", 1) < 100)
		return notify_fail("���֪ʶ�������޷�����貨΢����\n");
        if( me->query("family/family_name") != "��ң��")
{
    if ((int)me->query("int") < 30)
		return notify_fail("������Բ������޷�����貨΢����\n");
}
	   return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
if( (int)me->query("jing") < 60 )
		return notify_fail("�������̫���ˣ��������貨΢����\n");
if( (int)me->query("qi") < 60 )
		return notify_fail("�������̫���ˣ��������貨΢����\n");

	me->receive_damage("jing", 40);
       me->receive_damage("qi", 40);
if( (int)me->query("qi") < 40 )
return notify_fail("�������̫���ˣ��������貨΢����\n");
        me->receive_damage("qi", 30);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"lingboweibu/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1;
        string msg;
        int p,j,skill, neili, neili1;
        object weapon;
        int level,level2,damage2,nlevel;

        level = (int) me->query_skill("bahuang-gong",1);
        level2= (int) me->query_skill("bahuang-gong",1);
        nlevel= (int) me->query_skill("lingboweibu",1);
        if (!level) level=(int) me->query_skill("beiming-shengong",1);
        
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("lingboweibu", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

if (damage <10)
{
damage=10;      
}

        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (damage2>= 3800) damage2 = 3800;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "bahuang-gong")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
if (me->query("neili") < me->query("max_neili"))
me->add("neili",(damage2+nlevel));
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIR"$NͻȻ����,$nȫ����������ˮ��ԴԴ����������$N������\n"NOR;

           message_vision(msg, me, ob);
           j=-(damage/3);
           return j;
}       


if (me->query_skill("beiming-shengong",1) <100)
{
           me->delete_temp("lingboweibu");
           return 1;
}
      if(me->query_temp("lingboweibu")){
           me->delete_temp("lingboweibu");
           return 1;
           }
      if(skill > random(ob->query_skill("dodge", 1)) 
         && me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("dodge") == "lingboweibu"
         && neili > 400 && skill > 150)
        {
         me->add_temp("lingboweibu", 1);    
         msg = HIG"$N�������κζ�����ֻ������һ��һת�����һ��ת��$n�ı���\n"NOR;
	  tell_object(ob, HIR "��ֻ����ǰһ���������˶��ֵ���Ӱ��\n" NOR);
         if(neili >= neili1+random(neili1)+damage){
              msg += HIR"$nһ�д�գ���æ���������������˻�����\n"NOR,
//              if (damage < 10) damage=10;
              ob->receive_damage("qi", damage);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "����");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -(damage*3);
              ob->start_busy(1);
              }             
           else if(neili >= random(neili1)+damage){
              msg += HIG"\n���$n����������㿪�ˣ�\n"NOR, 
              j = -(damage*2+skill*2);
              }
           else if(neili < random(neili1)+damage && neili*2 > random(neili1)+damage){
              msg += HIC"\n���$n�������������һ�룡\n"NOR, 
              j = damage/2;               
              }
           else{
              msg += HIB"\n���$Nֻ�����$n��һС��������\n"NOR, 
              j = damage/2+random(damage/2); 
              }           
           message_vision(msg, me, ob);
           return j;
           }          
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl,nlevel;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	string msg;
	
if (random(6)==0 && me->query_skill_mapped("dodge") == "lingboweibu")
{
        if( me->query("gender") == "����")
               {msg = YEL
"$N������������̬Ʈ��,һ�������貨,��������֮����\n" NOR;}
        else   {msg = YEL 
"$N����������ʩչ�貨΢��������������������Ů�·���\n" NOR;}

if (!victim->is_busy()) victim->start_busy(3);
	return msg;
}

}
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage,damagea;
    string msg;
    object weapon;
       int p,skill;
       int d;
       
    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail(RED"��ʲô��Ц��ûװ������ôʹ�����λ�Ӱ����\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("�����λ�Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("zileidao", 1) < 90 )
   return notify_fail(WHT"������׵���������죬��ʹ���������λ�Ӱ����\n"NOR);

if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "lengyue-shengong")
                return notify_fail("��ʹ��������!\n");

        if((int)me->query_skill("lengyue-shengong",1) < 200)
                return notify_fail("��������񹦻�����������\n"); 
        if((int)me->query("neili") < 1800 )
                return notify_fail(WHT"����������㡣\n"NOR);
   
    if ((int)me->query("max_neili")<1800)
   return notify_fail(RED"���������Ϊ���㣬�޷����㡸���λ�Ӱ����������\n"NOR);
    if ((int)me->query("neili")<1800)   
          return notify_fail(HIC"����������������û�ܽ������λ�Ӱ��ʹ�꣡\n"NOR);
  
    msg = HIC "$N���һ����ȫ���Ĵ��ζ���$nֻ����$N����������Ӱ�����쵶��ϯ�������\n$n����һ�ܣ���$N������·��$nֻ��סһ����\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3||
   random((int)target->query("combat_exp")) < (me->query("combat_exp")) )
    {
   
   damage = 200+(int)me->query_skill("zileidao", 1);
   damage = damage + random(damage);
   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/3);

   target->receive_damage("jing", damage/4);
   msg += HIC"$n����û����ܣ���ʱ����������$n��ͷ��\n"+HIR"$n��Ѫ����$n�Ծ���ǰһƬ�ʺ죬��ס���ߣ�\n"NOR;

     me->start_busy(random(3));

    }else
    {
   me->start_busy(2);
   msg += HIY"����$p���Կ����������У����������̹Ȼ��ԣ�����ֻ�м�ס����ʵ�С�\n"NOR;
    }
   me->add("neili", -150);
    message_vision(msg, me, target);
if ((int)me->query_skill("zileidao", 1)>= 200)
{
   message_vision(HIM"������ $Nǰ�����ߣ���������������"+BLINK""+ weapon->name()+ NOR" "+HIM"ԽʹԽ�죬������ӰѤ����ٻ���š�\n\n"HIC"$n"HIC"����$N��"BLINK""+weapon->name()+ NOR""+HIC"�������ߣ�����ȴ���������ۻ����ҡ�\n"NOR,me,target);
           target->add("neili",-300);
           target->add("qi", -50);
        if(!target->is_busy()) target->start_busy(2);
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 800);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));         
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -800);

}

if ((int)me->query_skill("zileidao", 1)>= 380)
{
 d = (int)me->query_skill("zileidao",1);       
 skill = me->query_skill("zileidao",1)/2;
           damage = 200+skill*2 + random(skill);
           damage = damage + random(damage);
  message_vision(HIR"\n$N����ͷ��������ȫ��������һ������\n\n"NOR,me,target);
message_vision(MAG"\n�������һ����ɫ���滮��,����һֻ����\n"NOR,me,target);
     COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if (random(me->query_skill("force")) > target->query_skill("force")/3){
          target->receive_damage("qi", damage);
          target->receive_wound("qi", damage/3);
  message_vision(HIB"\n$n������ɫ�����Χ��......\n"NOR,me,target);
       }
       else{
  message_vision(HIG"\n$n��æ��Ծ���Ž����㿪����Ĺ�����\n"NOR,me,target);
     me->start_busy(2);
     //me->add("qi",-100);
     me->add("neili", -100);
       }      
    message_vision(HIW"\n
$NĬ�������񹦣���צ��ʩ���λε�Ӱ�У�����������צ�硣
��ʱ�䣬����ɳ��������צӰ�������ǵ�������צצҪ��"NOR,me,target);
       target->start_busy(2);
        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 800);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
               me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -800);
       target->add("neili", -skill*2);    
       target->add("qi", -100);


}

if ((int)me->query_skill("zileidao", 1)>= 680 || !userp(me))
{
	damagea=200+random((int)me->query_skill("dodge")*2);
if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
{
              message_vision(HIW"\n$N����ͻתʹ�������񵶵ľ�ѧ--������������\n"NOR,me,target); 

              message_vision(HIG"\n��һ��----�����磬$N���е�������һ�󼲷�㹥��$n��\n"NOR,me,target);
              // modify by mudring ....nk bug....hmm..
              target->receive_damage("qi", damagea);
              target->receive_wound("qi", damagea/2);
              target->receive_damage("jing", damagea/4);
              target->start_busy(2);
              COMBAT_D->report_status(target);
}
if ((int)me->query_skill("zileidao", 1)>= 980 || !userp(me))
{
	        me->add_temp("apply/attack", 100);
        me->add_temp("apply/damage", 800);
              message_vision(HIM"\n�ڶ��С��������磬$N���е����������嵶��һ��ʢ�ŵ�÷����\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIW"\n�����С���ѩ���磡$N���е�����ͻ��һ�����⣬��ƬƬѩ������\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                message_vision(HIC"\n�����С��������磡$N���е����д������£�֮������������һ�����£���\n"NOR,me,target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
               damage=200+(int)me->query_skill("blade")+random((int)me->query_skill("parry"));

        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -800);
if(random((int)target->query("combat_exp"))<(int)me->query("combat_exp"))
{

               message_vision(HIG"\n�绨ѩ�¡���������\n"NOR,me,target);

              target->receive_damage("qi", damage/2);
              target->receive_wound("qi", damage/3);
              COMBAT_D->report_status(target);
}
}
  me->add("neili", -100);



}
 me->start_busy(2);
    return 1;
}

// BY wuyou@sk_xyj 2002-12-1

#include <ansi.h>
#include <combat.h>



inherit F_SSERVER;

int perform(object me, object target)
{
    int ap, dp, damage, mypot;
    string msg;
    object weapon;
    int k1, k2, k3;        

    if (!target)
        target = offensive_target(me);

    if (!target
        || !target->is_character()
        || target->is_corpse()
        || target==me)
            return notify_fail("��Ҫ��˭ʩչ"HIG"�����ˡ���"+NOR"������\n");
    
    if (!me->is_fighting())
        return notify_fail("�����ˡ���ֻ����ս����ʹ�ã�\n");
 
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "zhanzhuang-gong")
                return notify_fail("��ʹ����ƽ����վ׮��!\n");

    if ((int)me->query_skill("hellfire-whip", 1) < 280)
        return notify_fail("��������һ�޵ȼ�������ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("yijinjing", 1) < 150)
                return notify_fail("����׽���𻹲�����ʹ����һ�л������ѣ�\n");
    if ((int)me->query_skill("buddhism", 1) < 200)
        return notify_fail("��������ķ���������ʹ����һ�л������ѣ�\n");

    if ((int)me->query("max_neili") < 2000)
        return notify_fail("�������������\n");

    if ((int)me->query("neili") < 800)
        return notify_fail("����������㣡\n");

    if ((int)me->query("jing") < 400)
        return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

    dp = target->query("combat_exp"); 
    ap = me->query("combat_exp"); 
     
    msg = HIW"\n$N˫�ֻ�һ��Բ����Ȼ������٣�������������������������" BLINK + HIG"�����ˡ���"
        NOR HIW "���С�\n" NOR;
    msg += HIW"     \n"NOR;
    msg += HIW"        "HBRED HIG"������������"NOR"       "HBRED+HIG"������������\n"NOR;       
    msg += HIW"        "HBRED HIG"��   "NOR BLINK HIR "߱" NOR HBRED HIG "   ��" NOR "       "
        HBRED HIG "��   " NOR BLINK HIR "��" NOR HBRED HIG "   ��\n"NOR;       
    msg += HIW"        "HBRED HIG"������������"NOR"       "HBRED HIG"������������\n"NOR;       
    msg += HIM"ֻ��$N���г����ڿ��л��˸��뻡��"HIG"�������һ�ޡ�"HIM"ֱɨ��$n��\n"NOR;

    k1=(int)me->query_skill("hellfire-whip", 1);      
    mypot = k1 * k1 * k1 / 10 + ap;        

    if (random(mypot + dp) > dp * 3 / 5 || random(3)==0)
    {              
        damage = k1 + random(k1) + me->query("force_factor") + 200;
        msg += HIC"���$n��"HIG"�������һ�ޡ�"HIC"ɨ����������ʹ���̣�\n"NOR;
        message_vision(msg, me, target);                                                                     
if (damage > target->query("qi",1)) damage=target->query("qi",1)/2;
        target->receive_damage("qi",damage,me);
        target->receive_wound("qi",damage/2,me);
        COMBAT_D->report_status(target);                                 
    }
    else
    {
        msg +="���Ǳ�$nȫ�㿪�ˡ�\n"NOR;
        message_vision(msg, me, target);       
    }

    msg = HIW"     \n"NOR; 
    msg += HIW"        "HBYEL+HIG"������������"NOR"       "HBYEL+HIG"������������"NOR"\n"NOR;      
    msg += HIW"        "HBYEL+HIG"��   "NOR+BLINK+HIR"ɱ"NOR+HBYEL+HIG"   ��"NOR"       "
        HBYEL+HIG"��   "NOR BLINK HIR"��"NOR+HBYEL+HIG"   ��"NOR"\n"NOR;
    msg += HIW"        "HBYEL+HIG"������������"NOR"       "HBYEL+HIG"������������\n"NOR;  
    msg += HIY"ֻ��$N�������������򳤱޹�ע������"+HIC"��ʱ��ֱ�����"+HIM"����ɥ����"
        HIY"��������ֱ����$n��\n"NOR;

    k2=(int)me->query_skill("buddhism",1);      
    mypot=k2*k2*k2/10 + ap;        
    if (random( mypot+ dp) > dp*3/5  || random(3)==0)
    {              
        damage = k2+random(k2)+me->query("force_factor")+300;
        msg += HIC"���$n"+HIC"��ɨ�����ţ�\n"NOR;
        message_vision(msg, me, target);                                                                      
   if (damage > target->query("qi",1)) damage=target->query("qi",1)/2;
        target->receive_damage("qi",damage,me);
        target->receive_wound("qi",damage/2,me);
        COMBAT_D->report_status(target);
    }
    else
    {
        msg +="$n����ıܿ��ˡ�\n"NOR;
        message_vision(msg, me, target);       
    }
     
    msg = HIW"     \n"NOR; 
    msg += HIW"        "HBWHT+HIG"������������"NOR"       "HBWHT+HIG"������������"NOR"\n"NOR;      
    msg += HIW"        "HBWHT+HIG"��   "NOR+BLINK+HIR"ն"NOR+HBWHT+HIG"   ��"NOR"       "
        HBWHT+HIG"��   "NOR BLINK HIR"��"NOR+HBWHT+HIG"   ��"NOR"\n"NOR;
    msg += HIW"        "HBWHT+HIG"������������"NOR"       "HBWHT+HIG"������������\n"NOR;  
    msg += HIG"$N���г����罣������$n���ؿڣ���ʱ�ٹ��뺿������������ԭ������"+HIB"��׷�꽣��"
        HIG"��\n"NOR;

    k3=(int)me->query_skill("zhanzhuang-gong",1);      
    mypot=k3*k3*k3/10 + ap;        

    if ( random( mypot+dp ) > dp*3/5  || random(3)==0)
    {              
        damage = k3+random(k3)+me->query("force_factor")+500;
        msg += HIC"���$n"+HIC"���޷�����������ֱ͸�ز���\n"NOR;
        message_vision(msg, me, target);   
        if (damage > target->query("qi",1)) damage=target->query("qi",1)/2;
        target->receive_damage("qi",damage,me);
        target->receive_wound("qi",damage,me);
        me->receive_damage("qi",10);
        COMBAT_D->report_status(target);
    }
    else 
    {
        msg +="���Ǳ�$n�͵�һ�ɣ��㿪�ˡ�\n"NOR;
        message_vision(msg, me, target);       
    }


    me->add("neili",-300);
    me->start_busy(2);

    return 1;
}



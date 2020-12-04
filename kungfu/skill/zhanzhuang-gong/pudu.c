#include <ansi.h>


#include <combat.h>


inherit F_SSERVER;

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD,BLINK });
                        
        if( str && stringp(str) ) 
        {
                i = sizeof(color);
                while( i-- ) 
                {
                        str = replace_string(str, color[i], "");
                };
                return str;
         }
}



int exert(object me)
{
        string msg,spells_skill,name;
        int ap,dp,ap1,dp1,pp,i,j,p;
        object weapon,*inv;
 object target;
        if( !target ) target = offensive_target(me);

        if( (int)me->query_skill("buddhism",1) < 100)
                return notify_fail("��������ķ�������������[�նɴȺ�]������\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("����㻯˭��\n");  
   
           if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"���նɴȺ���ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
   
        if (!me->is_fighting() && (userp(target)))
                return notify_fail("���±����£��α�����֮��\n");
   
        if((int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("jing") < 200 )
                return notify_fail("���޷����о�����\n");

        me->add("neili", -200);
        me->receive_damage("jing",100);
        if ( me->query_skill("buddhism",1)< 100) 
                return notify_fail("�㻹û��ѧ��[�նɴȺ�]......\n");  
                if( me->is_busy() )
                return notify_fail("��������æ���أ����п��˹���\n");
        
        me->start_busy(2);
        spells_skill = target->query_skill_mapped("buddhism");
        ap = me->query_skill("buddhism") + me->query("str");
        dp = target->query_skill("buddhism",1) + target->query("str");
        ap1= me->query("str");
        dp1= target->query("str");
                        pp = me->query_skill("buddhism",1);
        if ((string)me->query("bonze/class") =="bonze" )
                pp = me->query_skill("buddhism",1)*2;
        
        weapon=target->query_temp("weapon");
        inv=all_inventory(me);
        i=sizeof(inv);
//        me->delete_temp("condition/carrying_ok");
        j=0;

       if( !present(target, environment(me)) )
                return notify_fail("��λ��ǵ����˴������˰ɡ�\n");
            
        if( random(ap+dp) > dp)
        {
                if( random(ap1)>random(dp1) ) 
                { 
                        msg = HIC"$N˫�ֺ�ʮ������΢�գ��������У�ȫ��£����һƬϼ��֮�С�����$N�����\n"NOR;          
                        switch (random(3))
                        {
                        case 0:
                        { 
                                msg += HIC"
    ������Χ�ƣ�����צ�ɲ�����˹������������ޱ߷���\n
    ���߼���Ы�������̻�Ȼ����˹�������Ѱ���Ի�ȥ��\n
    ���׹ĳ��磬���������꣬��˹�������Ӧʱ����ɢ......\n"NOR; break;}
      
                        case 1:
                        {
                                msg += HIC"
    �������������������
    �������������ܾ������......\n"NOR; break; }
                        case 2:
                        { 
                                msg += HIC"
    ����������ǧ����������������գ�
    ���ǹ�����������һ�ĳ�����������������ʱ�����������Եý��ѡ�
    ���г��ǹ������������ߡ������𣬻����գ����������������ʡ�
    ��Ϊ��ˮ��Ư���������ţ�����ǳ��......\n"NOR; break; }
    
                        }             
                if ( random(3)==0 )
                {                 
                		if ( userp(target) && pp > target->query("jing",1)/3) pp=target->query("jing",1)/3;    
                        target->receive_damage("jing", pp*2,me);  
                        target->receive_wound("jing", pp*2,me);
                        target->receive_wound("qi", pp*2,me);
                        target->add("neili",-800);
                        target->add("neili",-pp*3,me);
                        target->start_busy(5);
                        if (target->query("neili")<0) target->set("neili",0);
                }
                         else 
                {
                	if ( userp(target) && pp > target->query("jing",1)/3) pp=target->query("jing",1)/3; 
                        target->receive_damage("jing", pp*3/2,me);  
                        target->receive_wound("jing", pp,me);
                                                target->receive_wound("qi", pp*2,me);
                        target->add("neili",-500);
                        target->add("neili",-pp*2);
                        target->start_busy(3);
                        if (target->query("neili")<0) target->set("neili",0);
                }
                      
                msg += HIR"��֪������$n��Ȼ���������棬�૵�������ˣ�����......\n"NOR;
               
                if(objectp(weapon) && (  random(10)>7 ) )
                {
                        weapon->unequip();
                        target->start_busy(8);
                        //weapon->move(environment(target));  
                        msg+="$n�������е�"+weapon->query("name")+"��̾������"+RANK_D->query_self(me)+"����ʼ�Ŵ����Ը�������ҷ�\n"NOR;
                
                }
                message_vision(msg,me,target);         
                COMBAT_D->report_sen_status(target);
        }
    
        else
        {
                msg = HIW"$N�����ȵ����������������سɷ𣡷������������سɷ𣡣��������������سɷ𣡣���\n"NOR;
                if (random(ap1+ap1)>random(dp1)) 
                {
                        msg += HIW"ֻ��$n�����㱣�����ҡҡ��׹��\n"NOR;
                        message_vision(msg,me,target);         
                        COMBAT_D->report_sen_status(target);
                        if ( userp(target) && pp > target->query("jing",1)/3) pp=target->query("jing",1)/3; 
                        target->receive_damage("jing", pp,me);  
                        target->receive_wound("jing", pp/2,me);
                                                target->receive_wound("qi", pp*2,me);
                        target->start_busy(3);
                        target->add("neili",-100);
                        target->add("neili",-pp);
                        if (target->query("neili")<0) target->set("neili",0);
                }
   
                else {
                        if (spells_skill) {
                                msg += HIW"$nĬ��"+CHINESE_D->chinese(spells_skill)+HIW"��һ����ȣ������ڴ�װ��Ū��\n"NOR;                             
                                message_vision(msg,me,target);         
                                        me->start_busy(2+random(3));
                        } 
                }
        } 
   
        
  
        return 1+random(4);
        }
   
        message_vision(HIR"$n������Ц�����������Ҳ����ˣ�Ҫ����"+RANK_D->query_rude(me)+"����߶Щʲô!\n"NOR,me,target);     
         
        return 3+random(4);     
}
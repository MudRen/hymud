//By exp
//changed by wuyou@sk_xyj 2002-12-6

#include <condition.h>
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string str;
        string msg;
        int extra;
        object weapon;
        object ob,victim;              // ���ֵ�����
        int i,attack_time,skill,damage,lvl;        

        extra = me->query_skill("sanqing-jian",1);
            if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("sanqing-jian", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("kongdong-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "sanqing-jian")
          //      return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ�����ѧ��ʹ������ἵľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               
victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}


     
        lvl = me->query_skill("sanqing-jian", 1);   
victim=target;

        weapon = me->query_temp("weapon");
        if (extra > 200) extra=200;
        me->add_temp("apply/damage",2500);
        me->add_temp("apply/attack",200);
        msg=HIW"$N���е�"+ weapon->name()+  "һ���ʣ��ͻ���һ���⻪����$n��
һ�����εĹ⻪�����á��Ի͡�������\n" + HIG"�⻪����������á��߸����ϣ�����Ʈ����$n
ֻ��������⻪�ݷ�����Լ�ü�޼䣬ȴ�ֲ���ȷ���������
���ı仯�������ѳ�Խ�����������ļ��ޣ������������޷����š�"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg="������ȷʵ����������޴����ڡ�
���Ǿ���$n��ȷ��������ʱ������Ȼ�ֲ����ˡ�"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=WHT"���漣���Ȼ���֣����漣���Ȼ��ʧ��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg=HIR"���еĶ����ͱ仯��������һɲ�Ǽ���ɣ���ֹ��
���������ǣ�ȴ���������磬ȴ�ֱ����Ǻ�������ӽ��漣��
��Ϊ�߶���仯������������$N�������ġ�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->add_temp("apply/damage",-2500);
       me->add_temp("apply/attack",-200);
       //me->add("neili", -100);
       //me->start_busy(2);


       msg = HIM "$N������̾,ʹ���ˡ���һ���ķ��项,�����д������־���,��������,���ֿɰ���һ�ֲ���һ����\n";

  if(random(me->query_skill("sword")*me->query("int") ) > ((int)target->query_skill("force")*target->query("int"))/3)
        {
 skill=me->query_skill("sanqing-jian",1);
                if (! objectp(ob = target->query_temp("weapon")))
                {
                        msg += HIM "�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!"NOR"\n"HIR"���$n��Ϊ$N�Ľ�������,��,��һ���³�һ����Ѫ��\n" NOR;
                        //me->start_busy(1);
                        damage = 700 + skill;
                target->receive_damage("qi", damage,me); 
                target->receive_wound("qi", damage,me);
                        //target->start_busy(random(3));
                      
        message_vision(msg, me, target);
                } else
                {
                          msg += HIM"�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!"NOR"\n"HIR"���$n��Ϊ$N�Ľ�������,��,��һ���³�һ����Ѫ��\n" NOR;
                          msg += YEL"��һ��,������$n�����"+ob->query("name")+"��\n"NOR;

                        ob->unequip();
                        damage = 700 + skill;
                target->receive_damage("qi", damage,me);
                        target->receive_wound("qi", damage,me);
                        //me->start_busy(1);
                        //target->start_busy(1);

        message_vision(msg, me, target);

                } 
            
        }
else
        {
                msg += HIM"�ǽ�����һ���������,ȴ�Ȳʺ����Ѥ��!\n"NOR"\n"HIY"���$n������������ע���ܿռ�,������$N�Ľ��⡣\n" NOR;
                //me->start_busy(3);
                message_vision(msg, me, target);

        } 


msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "�����" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

                msg = HIG "$n��$Nȭ��ɨ�У�ֻ��ȫ������ʧȴ��Ԧ�����⼱к��\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
        message_vision(msg, me, target);

 msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "�ݸγ���" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

              msg = HIG "$nǰ������$Nȫ��һ����ֻ��һ���ʹ�����ۡ���һ�����һ����Ѫ��\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
        message_vision(msg, me, target);


        msg = HIY "$N" HIY "ŭ��һ����˫ȭ������ʩ�����С�" HIR "���־�" HIY "����˫ȭѸ���ޱ�"
              "��Ϯ��$n" HIY "��\n" NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

                msg = HIG "ֻ��$P" HIG "��һȭ��$p" HIG"���˳�ȥ�����ص�ˤ�ڵ��ϣ���Ѫ��ֹ��\n" NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
        message_vision(msg, me, target);

     msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "�˷ξ�" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {


                msg = HIG "$N��ȭ���������ף����족��һ������$n���ϣ�\n$nֻ���ú�����˳����ʱ�Ų�������࣡\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
        message_vision(msg, me, target);
        
       msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "���ľ�" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

msg = HIG "$N����ȭ������ף�$n����$N��ɽ��ʯ��һȭ����ʱ������𣬲���������У�\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
        message_vision(msg, me, target);
        
       msg = HIY "$N��������ʹ������ȭ�ܾ��еġ�" HIR "���㱾�" HIY "����˫ȭ������������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
 msg = HIC "���$N˫ȭ����ʱ��ȴ���������ޡ�\n$n������ּ䣬�ѱ�$N��������ס������лк����ģ�\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*2),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*2),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
        message_vision(msg, me, target);

msg = HIY "$N�����˹���ʹ��������ȭ�����ľ��У����ֹ��ޱ�ǿ����������Х������$n���ϸ���ҪѨ��\n"+HIC "$n���ᵤ��֮������������ײ����"+chinese_number(i)+"�ɾ���������\n"NOR;
        message_vision(msg, me, target);	
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {

msg = HIY"���$n���ܲ�ס$N�����־������������ص�ײ����"+GRN"\n($n"+HIR"���ܵ�������ʵ���ᡣ"+GRN")\n"NOR;
target->receive_damage("qi", (me->query_skill("sanqing-jian",1)*4),me);
target->receive_wound("qi", (me->query_skill("kongdong-xinfa",1)*4),me); 
		//msg += "($n"+str+")\n";
        }
        else
        {
                msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
        }
        message_vision(msg, me, target);                                        


me->start_busy(4);


       return 1;
}


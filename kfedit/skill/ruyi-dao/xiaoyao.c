//xiaoyao ��ң��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill,ap,dp;
	int extra;
        string msg,pmsg;
        int damage;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
                return notify_fail("�����õ�����ʩչ��\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("ruyi-dao", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("liuyang-zhang", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("beiming-shengong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ��ң����ѧ��ʹ������ң�ɵľ�ѧ֮���裡\n" NOR;
	if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
        message_vision(msg, me, target);              

        
        skill = me->query_skill("ruyi-dao");
	extra = me->query_skill("ruyi-dao",1) / 20;
	extra += me->query_skill("ruyi-dao",1) /20;
        me->set_temp("ruyi");
	if (random(3)==0) target->start_busy(3);
	me->add_temp("apply/attack", 200);	
	me->add_temp("apply/damage", 2800);
        msg = HIY "$Nһ����Ц��ֻ���������⣬�������أ��Ĺ�ʲô�Ƿ����裬����һ��������\n"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB"$N�������������δ������������һ����\n"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
        msg = HIR"$N���浶ת��˳������һ����\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
        msg = HIG"$N���浶ת��˳������һ����\n"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
        msg = HIC"$N���浶ת��˳�����һ����\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
        msg = HIW"$N������ת������һ���ֻ�ת������\n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
	msg = BLU "$N��ˮΪ�����������У�˫ָһ�������ϼ�����⼱������$n��\n";
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("ruyi-dao",1)));
	target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/50) + 2 +
	target->query_condition("ss_poison"));

       me->start_busy(4);
       me->delete_temp("ruyi");
	me->add_temp("apply/attack", -200);
	me->add_temp("apply/damage", -2800);
        msg = HIC "$N���г�����âԾ�������Ⱪ����һ�����������⽥���ƽ�$n��\n"NOR;
        msg += HIM"$n�������쵶�⣬�����Ծ��ֻ��һɲ�����쵶Ӱ��Ϊһ��ֱ��$nǰ�أ�\n"NOR;
        msg += HIR"**************��������***************"NOR;
	if( weapon = target->query_temp("weapon") ){
        if( random(me->query("str")) > (int)target->query("str")*3/4 || random(3)==0) {  
if (!weapon->query("systemmake") && !weapon->query("ownmake"))
{

    msg += HIM"\n$pֻ���û���һ�ȣ����ƻ��ھ�ʹ������"
                + target->query_temp("weapon")->query("name") + "���ֶ�����\n" NOR;
		message_vision(msg, me, target);
		(

		target->query_temp("weapon"))->move(environment(target));
}
                target->start_busy(2);
	} else {
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
		message_vision(msg, me, target);
	}
        }

 if (random(me->query("combat_exp")) >target->query("combat_exp")/3 || random(3)==0)
	{
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("ruyi-dao", 1);
		
		damage = damage*7 + random(damage)+800;
		
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage),me;
		
		if( damage < 300 ) msg += HIC"\n���$n��ɫ��һ�����У��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIC"\n���һ�����У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += HIR"\n������䡹��һ����һ������������,$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬һ����������,$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		
	} else 
	{
    msg += HIY"\n$pΣ����ͻȻ���ط����������ܹ���������һ�������ŵ���ɫ�԰ף�\n" NOR;
	}
	message_vision(msg, me, target);


msg = WHT" \nֻ��$N" WHT "��Ȼ��Ե�����������֮ɫ��˿˿����������䣬ת˲���ѽ�$P�����ư���������\n" +
             "���ô�ʱ��$n" WHT "�Ѿ������֪�������㣬$N" WHT "���С�" HIY "һ������" WHT "����Ȼ������ǰ��������\n" +
             "������$pֻ�����ܵĿ����·��Ѿ����ᣬ��һ��֮���ѽ���������ǰ�����������ʵ����\n"+
             "�԰��ѡ�˲��Ŀ�������ֱ��һ����մ󶴣�ʹ�����ܵ��˾�����һ�����ͣ�\n\n"NOR;

        ap = me->query_skill("strike") + me->query("con") * 20; 
        dp =  target->query_skill("force") + target->query("con") * 20; 
             
        if (ap  + random(ap) > dp || random(3)==0)
        {

     damage = (int)me->query_skill("beiming-shengong", 1);
         //damage = random(damage)+1000;                
                target->receive_damage("qi", damage*8,me);
                target->receive_wound("qi", damage*8,me);   
                pmsg = HIR "$n" HIR "�ۼ�$N" HIR "һ���������ƾ���飬�������ȣ�Ȼ��������������֮�У����޿ɱܣ�ֻ��\n" +
                       "��΢Ų���Ų�Ҳ������֮���������$N" HIR "һ��ӡ����ǰ���Ǹ�һ��ʹ����裬ȴ���߹Ǳ�\n" +
                       "��һ��֮����ϣ���Ѫ��ӿ��Ȼʧ�أ�һ����Ѫ�����ӿڱ������˳�����\n\n" NOR;

                msg += HIR "$n" HIR "�ۼ�$N" HIR "һ���������ƾ���飬�������ȣ�Ȼ��������������֮�У����޿ɱܣ�ֻ��\n" +
                       "��΢Ų���Ų�Ҳ������֮���������$N" HIR "һ��ӡ����ǰ���Ǹ�һ��ʹ����裬ȴ���߹Ǳ�\n" +
                       "��һ��֮����ϣ���Ѫ��ӿ��Ȼʧ�أ�һ����Ѫ�����ӿڱ������˳�����\n\n" NOR;
                //msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 65, pmsg);
      
        } else
        {
                msg += HIG "����$n" HIG "�����쳣��һ�۵���$N" HIG "���е�����֮���������е����ģ���伫Ϊ����������\n"+
                       "���ֳ�ָ��������$N" HIG "���������ϣ�������ָ����$P���ĵ�" HIR "�ٸ�"
                       HIG "��" HIR "�͹�" HIG "��Ѩ�����$N" HIG "Ѩ����\n" +
                      "�⣬�������޴���й������ʴ�������$P�����ֽ���ڴ����࣬����������ˣ�\n\n" NOR;

        }
        message_combatd(msg, me, target);


        return 1;
}

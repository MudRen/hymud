//����������
//by junhyun@SK

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon,victim;

        int mkee;

        int ap, dp;

        int times, extra,i;
        string number;

        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("club",1);
        myskill1= (int)me->query_skill("bawang-qiang",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";

                 if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "club")
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

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");



        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");


       if( !wizardp(me) &&(int)me->query_skill("bawang-qiang", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("taixuan-gong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");



        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "bawang-qiang")
          //      return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ���͵���ѧ��ʹ�������͵��ľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               
//victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}


        if ( !wizardp(me) && me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("��ʹ��̫����!\n");

 
        
        
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("neili");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("neili",-100);
        //me->receive_damage("jing", 50);
        message_vision(HIW"$N������ǹ������Ծ������ǹ�ߣ�����ɱ��������
            �����������꡻ \n" NOR,me,target);        
        message_vision(HIY"$N������ǹ����һ���������һ��������ֱ�Ĵ���Է���\n"NOR,me);
         if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
                msg = HIR"$n�����������������б�$N���˴�ǹ͸�������\n"NOR;
                damage=100+(int)(myskill1);
                if(damage<1)damage = 1;
                target->receive_damage("qi",damage*4,me);
                target->receive_wound("qi", damage*4,me);
                //target->start_busy(3);
                message_vision(msg, me, target);
                COMBAT_D->report_status(target);
                me->start_busy(1);
        }
        else
        {
                msg = HIW"$n��֪���У�����һ��,���ŵ���ƽƽ�ķ��˳�ȥ��\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(target, me, tweapon);
                me->start_busy(2);
        }        
message_vision(HIC"$Nһ����Х��"+ weapon->query("name")+ HIC"��һת�������������$n������"+number+"ǹ��ǹǹҪ����\n"NOR,me,target);
                if (!target->is_busy()) target->start_busy(1);
        me->add_temp("apply/attack", 180);
        me->add_temp("apply/damage", 2200);
        times=6;
        for(i=1;i<=times;i++)
{
                        msg = HIY "��"+chinese_number(i)+"ǹ-------> ��\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
}        
        me->add_temp("apply/attack", -180);
        me->add_temp("apply/damage", -2200);

       damage = 100+random(me->query_str()) + me->query_skill("taixuan-gong");
      message_vision(HIW "$N" HIW "ͻȻ��ֻ���������¡�ԨҺѨ����һ����һ���������š�����"
                     "����������\n���š����¡��������š���Ѩ��ȥ��\nһ�С�ʮ��ɱһ�ˡ���"  + 
                     "ȭ��������ʹ����������ʽԴԴ��������$n" HIW "���֡�\n" NOR, me, target);

 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
               
target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
                msg =HIY "$n" HIY "ȴ��$N" HIY "�������ƻֺ룬�������������ֵ�������������"
                "���������ˣ�\n$n" HIY "�ƺ�һ�������˼������پ���Ϣ��ɢ��" + "˫��" + HIY 
                "������Ⱦ����Ѫ��\n" NOR;

        } else
        {
                msg = HIC "$n" HIC "����˫�ۣ������Զԣ�����$N" HIC "֮��жȥ��\n" NOR;
        }
        message_vision(msg, me, target);


        message_vision(HIW "$N" HIW "�����������ѣ���Ϣ�������������š��Կ��Ϻ�ӧ�����׾�����"
                     "��ͼ��ת����\nͬʱ�����㵸�����Ǵ�ϲ�����ƴ���ա�\n" NOR, me);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
               
target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
                msg =HIY "$n" HIY "��Цһ��������$N" HIY "���з�ǳ֮������"
                                          "�������мܣ�\n��Ȼ�䣬�����͡���һ����" + "һȭ" +
                                          HIY "�Ѵ�͸$n" HIY "�����ţ���Ѫ����ӿ����\n" NOR;

        } else
        {
                msg = HIC "$n" HIC "����һЦ������$N" HIC "�����е�����������ʩ�о������л�ȥ��\n" NOR;
        }
        message_vision(msg, me, target);


        message_vision(HIW "���Կ��Ϻ�ӧ���ȱϣ�����ȥ���ǡ��⹳˪ѩ������$N" HIW "��"
                    "��˼����\nʯ���ϵ�ͼ��һ�������Ժ�����Ȼӿ�����ԡ������հ���ֱ����˭������¡���\n"
                    "һ���ǳɵ�ʹ�˳�����\n" NOR, me);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
               
target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
                msg =HIY "$n" HIY "����һ��������$N" HIY "�⼸�������ޱȣ���ʽ�仯Ī�⣬"
                "������ȴ��Ȼ������\n����ԥ�䣬$n" HIY "ȴ�����У��ٸо������ã���"
                "��������\n" NOR;

        } else
        {
              msg = HIC "$n" HIC "Ĭ���ڹ����ھ�����ȫ�������ֵ�ס$N" HIC "���С�\n" NOR;
        }
        message_vision(msg, me, target);


        message_vision(HIW "���á�˭������¡����׹������꣬$N" HIW "ֻ����Ϣ��ת"
                     "������������Ӣ����ʹ��ȥ��\n" NOR, me);
 if(random(3)==0 || (random(me->query("combat_exp",1)) >= target->query("combat_exp")/3))
        {
               
target->receive_damage("qi", damage*3,me);
		target->receive_wound("qi", damage*3,me);
                msg =HIY "$N" HIY +  "ȭ�������ޱȣ���ʽʱ������������ʱ��"
                "�������裬���Ǽ�$n" HIY "�ѱ������ˡ�\n$N" HIY "��Ȼ��" + "ȭ��" + HIY "һ"
                "ת����ʽ��Ȼ�ӿ죬��$n" HIY "����Χס������һ˿��϶��\n" NOR;

        } else
        {
                            msg = HIC "$n" HIC "�������������ͣ����μ��ˣ�˲��Ʈ����"
                      "�ɣ����Ŷ��$N" HIC "���С�\n" NOR;
        }
        message_vision(msg, me, target);


me->start_busy(4);
     
        return 1;
}

///NOV.13.2000 by lucas
// jinwu.c ���ڶ��

/*
�������϶Է������Ĺ��������perform������������Ϊ�˱��ֶ��¾Ž���
��һ����ĵ�һ��λ���صضԷ�����һ�������������ڳ�����������������
ϣ���Ժ����ʦ��Ҫ������Щ�趨���Ͼ���weapon�书�У����ܳ�Խlonely-sword�ĵ�λ��
*/

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2,target,*inv;
        int skill, ap, dp, neili_wound, qi_wound,equip,skill1,skill2,skill3,skill4;
int attack_time,i;
        me->clean_up_enemy();
        target = me->select_opponent();
        skill  = me->query_skill("jinwu-blade",1);
        skill1 = me->query_skill("xueshan-sword",1);
        skill2 = me->query_skill("bingxue-xinfa",1);
        skill3 = me->query_skill("blade",1);
        skill4 = me->query_skill("unarmed",1);


        if( !(me->is_fighting() ))
            return notify_fail("��"+HIR"���ڶ��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( skill < 100)
            return notify_fail("��Ľ��ڵ����ȼ�����, ����ʹ�á�"+HIR"���ڶ��"NOR+"����\n");
        if(me->query_skill("bingxue-xinfa",1)<100)
            return notify_fail("��ı�ѩ�ķ��ȼ�����, ����ʹ�á�"+HIR"���ڶ��"NOR+"����\n");
 

        if( me->query("neili") < 700 )
            return notify_fail("��������������޷����á�"+HIR"���ڶ��"NOR+"����\n");

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
attack_time = random((int)me->query_skill("jinwu-blade", 1) / 30);
me->start_busy(2);
if (attack_time > 9 ) attack_time=9;
        for(i = 0; i < attack_time; i++){
         msg = HIR "$N�����ϵĸֵ������"+HIW"ѩ��"+HIR"һ�㣬ͻȻ��ѩ��������һ������\n" NOR;
me->set_temp("noauto",1);
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
me->delete_temp("noauto");
me->add("neili",-50);
          }
}
        msg = HIY
    "$N����Ծ��,ʹ��"+HIR"�����ڶ�ء�"NOR+""+HIY"������"NOR""+weapon->name()+""NOR+HIY"�Ӱ���лӵ�ֱ��������\n��������������ߣ��������ǳ�ɳ����ܲ���Ҷ�����缤�����Ŷ��裬\n��$n�Ӷ��˱ܵĿ�϶�������ʵʵ��\n"NOR;
        message_combatd(msg, me, target);

        ap = random(me->query("combat_exp") + skill*5);
        dp = target->query("combat_exp")/2;
        if( dp < 1 )
            dp = 1;
        if( ap > dp )
        {
            if(userp(me))
                 me->add("neili",-250);
            msg = HIC"$n���޿ɱ�,ֻ��һ�ɸ���֮���ľ������������ʹ��ֱ����Ϣ��\n$n�������˸�����ȴֻ��"NOR""+weapon->name()+""HIC"����һ��������ͣϢ��һ���������š�\n"NOR;
            qi_wound = (int)me->query_skill("jinwu-blade",1)+(int)me->query_skill("blade",1)+(int)me->query_str()*10;
            qi_wound = random(qi_wound*2);
// if(qi_wound > target->query("qi")) qi_wound = 100; ?  damage limit is wrong (by xbd)
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi") > 100 ? target->query("qi") - 100 : target->query("qi");
if (qi_wound < 10) qi_wound=10;
if (qi_wound >100000) qi_wound=100000;


            target->receive_damage("qi", qi_wound);
// 4 pfm all npc die, too power? please consider it. (by xbd)
            target->receive_wound("qi", qi_wound/3);
target->apply_condition("ill_shanghan",50);
target->apply_condition("iceshock",50);
target->apply_condition("xuantian_han",50);
target->apply_condition("xuanming_poison",50);

            target->start_busy(2+random(1));
            me->start_busy(1+random(2)); 

       objectp(weapon2 = target->query_temp("weapon"));

         if(me->query("str")>=20                                 //����������벻С����20
       && objectp(weapon2 = target->query_temp("weapon"))
       && me->query_str() >= 45                                 //����������벻С��45
       && me->query("max_neili") > 2500                        //��������������2800
       && !me->query("betrayer")                               //����û�ѹ�ʦ
       && (me->query("neili") - me->query("max_neili")) > 300  //����������������������300����������������550��ʵ�ʱ������550
       && skill > 200                                           //��ѩ�ķ��������200��
       && skill1 > 200                                          //����ȭ�ű������200��
       && skill2 > 200                                          //ѩɽ�����������200��
       && skill3 > 200                                          //���ڵ����������200��
       && skill4 > 200                                          //���������������200��
       && !weapon2->query("no_drop")                           //������Щ��ȷ�����������������������
       && !weapon2->query("no_get") 
       && !weapon2->query("no_put")
       && !weapon2->query("no_beg")
       && !weapon2->query("no_steal")
       && !weapon2->query("no_give") 
       )
       {
		inv = all_inventory(target);
		for(equip=0; equip<sizeof(inv); equip++)
        {
            if(inv[equip]->query("weapon_prop") && ((string)inv[equip]->query("equipped")=="wielded"))

		{
if (!inv[equip]->query("systemmake") && !inv[equip]->query("ownmake"))
{
msg += HIW "$N����δ�������е��Ʋ���������$n����"NOR""+inv[equip]->query("name")+HIW"һ�����ϡ�\nֻ������һ����$n���ϵ�"NOR""+inv[equip]->query("name")+HIW"�ѱ��������룬�����˵��ϣ�\n"NOR;
        message_combatd(msg, me,target);

			inv[equip]->unwield();
			inv[equip]->reset_action();
			inv[equip]->move(environment(target));
			inv[equip]->set("name", "�ϵ���"+ inv[equip]->query("name") );
			inv[equip]->set("value", 0);
			inv[equip]->set("weapon_prop", 0);
			inv[equip]->set("long", "һ���������������жϿ����ƿ����룬�����Ǳ�����һ�������ġ�\n");
}
			}
		}

          return 1;
         }
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = HIW"����$n�������Ա�һ��,�չ���$N���ɱ��һ����\n"NOR;
            me->start_busy(2);
}

//        }
        message_combatd(msg, me, target);
        return 1;
}


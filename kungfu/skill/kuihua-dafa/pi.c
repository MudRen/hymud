#include <ansi.h>
#include <combat.h>

#define PI "��" HIW "Ⱥа����" NOR "��"
#define HUI "��" HIW "����" HIR "���" NOR "��"
#define WSWD "��" HIR "��"BLU"˫"HIM"��"HIW"��" NOR "��"
#define WS "��" HIR "��"BLU"˫" NOR "��"
#define WD "��" HIM"��"HIW"��" NOR "��"

inherit F_SSERVER;

string *finger_name = ({ "������ָ", "��������ָ", "����ʳָ",
                         "������ָ", "��������ָ", "����ʳָ", }); 

int perform(object me, object target)
{
        string msg;
        string name;
        object weapon;
        int i,j;
        int skill,lvl,ap,dp,damage;
        int count;

        int x,a;
        string nextmsg;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail(PI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");

        if (weapon && weapon->query("skill_type") != "sword" &&
            weapon->query("skill_type") != "pin")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" PI "��\n");

        if (me->query_temp("weapon"))
                name = "����" + weapon->name();
        else
                name = finger_name[random(sizeof(finger_name))];

        skill = me->query_skill("kuihua-dafa", 1);

        if (skill < 120)
                return notify_fail("��Ŀ����񹦲�����죬����ʩչ" PI "��\n");

        if (me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" PI "��\n");
       if ((int)me->query_skill("kuihua-xinfa", 1) < 50)
               return notify_fail("��Ŀ����ķ�̫���ˡ�\n");
               
        if (weapon && me->query_skill_mapped("sword") != "kuihua-dafa")
                return notify_fail("��û��׼��ʹ�ÿ����񹦣�����ʩչ" PI "��\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "���κ�Ȼ��죬��ĳ���$n" HIW "��" + name +
              HIW "����������Ӱ����ʱ�����ǹ�һ������$n" HIW "��\n" NOR;
        message_vision(msg, me, target);

        count = skill / 5;
        me->add_temp("apply/attack", 200);
        me->add_temp("apply/damage", 1800);
me->set_temp("action_flag", 1);
        me->add_temp("pixie-jian/hit_msg", 1);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 0 && ! target->is_busy())
                        target->start_busy(2);

	msg = HIY "$N��������ޱȣ�������$n������"+chinese_number(i+1)+"�У���\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add("neili", -100);
        me->start_busy(3);
        me->add_temp("apply/attack", -200);
        me->add_temp("apply/damage", -1800);
        me->delete_temp("pixie-jian/hit_msg");
        me->delete_temp("action_flag");
if (skill>300 && target && me && weapon)
{
lvl = me->query_skill("kuihua-dafa", 1);

        //message_vision("\n\t\t" + BBLU + HIR "��    ��    " HIW "��    ��\n" NOR, me);

        // ��һʽ-----����
        ap = me->query_skill("force") + me->query_skill("dodge");
        dp=target->query_skill("force")+target->query_skill("dodge");

        message_vision(HIW "\n��Ȼ��$N" HIW "������ת��ɲʱ����糱�����Ʊ�"
                     "�գ����Ϊ֮��ɫ�������ǡ��������䡷�����ؾ�ѧ��" HIR "����"
                     "ʽ" HIW "����\nת�ۼ�$N" HIW "�Ѳ�������Ӱ��ֻ����һ����Х��һ"
                     "���׹������½�$n" HIW "���֣�" NOR, me, target);

        if (ap * 4 / 5 + random(ap) > dp || random(3)==0)
        {
                damage = ap+300 ;
           target->receive_damage("qi",damage,me);
           target->receive_wound("qi",damage/2,me);


                msg =HIR "\n$n" HIR "���д󾪣�ֻ��$N" HIR "һ��"
               "ҫ�۰׹�һ�����ѻ����Լ���ǰ����������������"
               "�����С�\n";

        } else
        {
                msg = HIC "\n$p" HIC "������죬��������һ������������С���\n" NOR;
        }
        message_vision(msg, me, target);

}

if (skill>400 && target && me && weapon)
{
  message_vision(HIM "\n������$N" HIM "����һ�Σ���û���ټ���ɲ�Ǽ䣬$n" HIM "ֻ���õض�"
                     "ɽҡ��������ӿ��\n����ԥ�䣬$N" HIM "�Ѵ���$n" HIM "���һ��"
                     "��" HIR "��ؾ�" HIM "��ʹ�� ����\n" NOR, me, target);

        ap = me->query_skill("force") + me->query_skill("dodge")+500;
        dp=target->query_skill("force")+target->query_skill("dodge");

        if (ap * 4 / 5 + random(ap) > dp  || random(3)==0)
        {
           target->receive_damage("qi",damage,me);
           target->receive_wound("qi",damage/2,me);

                msg += HIR "\nֻ��$n" HIR "һ���Һ�����$N" HIR
                "���б��ģ������꿦�ꡱ�߹�����ϡ�\n";

                                           
        } else
        {
                msg = HIC "\n$p" HIC "ֻ���������������͵�����Ծ������������С�\n" NOR;
        }
        message_vision(msg, me, target);
}

if (skill>500 && target && me && weapon)
{
   msg = HIM "\n$NͻȻ����һתգ�ۼ�ʹ�ÿ���ħ�����ռ�����----" NOR
                WSWD HIM "֮" NOR WS "\n"HIW"$N����ӨȻ�й⣬�ƺ�������ħ��֮�С�\n" +
                "$N����" + weapon->name() + "������˫��Ӱ����$n��\n";
        ap=me->query_skill("kuihua-dafa",1)*1+me->query("dex")*20+
                me->query_skill("dodge", 1);
        dp=target->query_skill("parry")+target->query("dex")*10+
                target->query_skill("dodge", 1);

        me->start_busy(2);


        if (ap / 2 + random(ap) < dp  && random(2)==0)
        {
            msg += HIG "Ȼ��$n" HIG "�ֵ��÷�����$N" HIG
                    "�Ĺ���һһ���⡣\n" NOR;
        } else
        {
            damage = ap +600;
           target->receive_damage("qi",damage,me);
           target->receive_wound("qi",damage/2,me);

                msg += HIY "$n" BLU "ֻ�����Ѿ����������ħ��֮�У�" HIY
                    "$N����" + weapon->name() + WHT
                    "��ͬ�����еĹ��㣬�Ӹ�����λ���˹��������޿ɱܣ�\n" NOR;

        }
       message_vision(msg, me, target);
}
if (skill>600 && target && me  && weapon)
{
 nextmsg = HIM "\n˵�ǳ���ʱ�죬$N������תʹ����" NOR WSWD "֮" WD HIM
                "ʽ��ɲ�Ǽ���������ܲ���\n" NOR HIM "$n�����༸��ֹͣ������������������$N\n" NOR;
        ap=me->query_skill("kuihua-dafa",1)*1+me->query("dex")*20+
                me->query_skill("dodge", 1);
        dp=target->query_skill("parry")+target->query("dex")*10+
                target->query_skill("dodge", 1);

        me->start_busy(2);


        if ( ap / 2 + random(ap) < dp && !(target->is_busy()) && random(2)==0)
        {
                nextmsg += HIG "��ʱ$n��ס����" HIG "�ֵ��÷�����$N" HIG
                        "�Ĺ���һһ���⡣\n" NOR;
        } else
        {

                damage = ap  +800;
           target->receive_damage("qi",damage,me);
           target->receive_wound("qi",damage/2,me);
                nextmsg += HIY "$n" BLU "ֻ��������ͬ�򽣴���һ�㣬" HIY "$N"
                        WHT "��ͬ����һ�㣬�Ʊ�Ҫȡ$n������\n" NOR
                        HIM "��ʱ�˿�$N����������" + weapon->name() + HIM
                        "��˲��仯�˼������У�����$n�����޷��ҳ��ƽ�֮����\n" +
                        "˵ʱ����ʱ��" + weapon->name() + HIM
                        "�Ѿ��̽���$n�����ţ���Ѫ����һ�أ���\n" NOR;
 
        }
        message_vision(nextmsg, me, target);
}

        return 1;
}
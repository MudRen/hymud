// zhenwu.c �����а

#include <ansi.h>
#include <combat.h>

#define PFM_NAME        "�����а"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage,s2;
        string msg;
        int ap, dp,i,attack_time,dmg;
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("��" + PFM_NAME + "��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if ((int)me->query_skill("taiji-jian", 1) < 290)
                return notify_fail("���̫������������죬����ʹ�á�" + PFM_NAME + "����\n");

        if ((int)me->query_skill("raozhi-roujian", 1) < 200)
                return notify_fail("�����ָ�ὣ���̫ǳ��\n");

        if ((int)me->query_skill("yitian-zhang", 1) < 200)
                return notify_fail("������������ƻ��̫ǳ��\n");

        if ((int)me->query_skill("paiyun-shou", 1) < 200)
                return notify_fail("����������ֻ��̫ǳ��\n");
                
        if ((int)me->query_skill("shenmen-jian", 1) < 200)
                return notify_fail("�������ʮ�������̫ǳ��\n");
                                
        if ((int)me->query_skill("force", 1) < 250)
                return notify_fail("����ڹ���Ϊ�����ߣ��������á�" + PFM_NAME + "����\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 250)
                return notify_fail("���̫������Ϊ�����ߣ��������á�" + PFM_NAME + "����\n");


                                    
        if ((int)me->query("neili") < 2500)
                return notify_fail("��������������������ʹ�á�" + PFM_NAME + "����\n");

        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("��û�м���̫������������ʹ�á�" + PFM_NAME + "����\n");

        if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("��û�м���̫���񹦣�����ʹ�á�" + PFM_NAME + "����\n");

        msg = HIY "$N" HIY "��Ŀ���������ת��һ�г���̫������ġ�" HIW + PFM_NAME +
              HIY "������ʹ�������з��ӹ��棬����ƽ�����棬\nʵ��㼯�����֮���������"
              HIY "������" + weapon->name()+ "�û�������̫����Ȧ������ǵص�ѹ��$n��\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        
        // ��ǿ ap
        if (me->query("shen") >= 10000) ap += (30 + random(20));
        if (target->is_bad()) ap = ap * 3 / 2;
        // ���� ap
        //if (me->is_not_good()) ap = ap / 2;
        if (me->query("shen") <= 0) ap = ap / 3;
        if (target->query("shen") >= 10000) ap = ap * 4 / 5;

        if (wizardp(me) && me->query("env/combat_test"))
        {
                tell_object(me, HIY "AP: " + ap + ". DP: " + dp + ".\n" NOR);
        }
        if (ap * 2 / 3 + random(ap) > dp)
        {
                s2=300;
                damage = 300+me->query_skill("sword")*3+(int)me->query_skill("taiji-jian",1);
if (me->query("shen") >= 10000) s2=me->query("shen",1)/1000;
if (s2>3800) s2=3800;
damage=damage+s2;
                me->add("neili", -250);
//              tell_object(me, HIC "DAMAGE: " + damage + ".\n" NOR);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);     
                msg += HIR "\n$p" HIR "��$P���������壬��Ȼ�ŵù˲����мܣ�"
                                           "��һ�����ؿ���С���Ữ������\n��ʱ��Ѫ�ɽ���\n" NOR;
                //me->start_busy(3);
        } else 
        {
                msg += WHT "\nȻ��$p" WHT "��Ȼ˿������Ϊ�⣬���赭д�Ľ�$P"
                       WHT "�Ľ��мܿ���\n" NOR;
                me->add("neili", -250);
               // me->start_busy(3);
        }
        
        message_combatd(msg, me, target, 0, 1);



       msg = HIC "ֻ��$N" HIC "���������Խ����˽�������" + weapon->query("name") + HIC "ÿ�����Ի���"
              "�̳��������ջأ�ÿ��һ�ж��Ʒ�\n��һ��ϸ˿��Ҫȥ����$n" HIC "����ʽ֮�ϡ�\n" NOR;
        me->add("neili", -50);

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        
        if (ap / 2 + random(ap ) > dp)
        {
                //me->add("neili", -30);
                damage = me->query_skill("sword")+100+(int)me->query_skill("taiji-jian",1);

                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage,me);  
                msg += HIR "ȴ��$n" HIR "�Ķ�����" +
                                           weapon->query("name") + HIR "��ס�󲻶����������������ټ�ɬ"
                                           "�ͣ��������ɿ�к������\n" NOR;
               
                if (ap / 2 + random(ap) > dp && ! target->is_busy())
                        target->start_busy(4 + random(2));

        } else
        {
                msg += CYN "$n" CYN "������ʧɫ����æԾ�����������Ű���$N"
                       CYN "��������\n" NOR;
                me->add("neili", -10);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        //msg="";
        msg = HIW "�Ӹ��ţ�$N" HIW "һ����Х������" + weapon->name() +
              HIW "��������������һ����ԲȦ����$n" HIW "Ȧ�ڵ�"
              "�С�\n" NOR;
                        msg += HIY "���$p" HIY "��$P" HIY
                       "���˸����ֲ������������˲�Ͼ��\n" NOR;
attack_time = (int)me->query_skill("taiji-jian", 1)/50;
                if (attack_time > 9)
                attack_time = 9;
        msg += HIC "��� $N" HIC "һ����Х����̨�����������Ԫ��ʹ��̫�����еĽ����ת��\n"
              HIY "����" + weapon->name() + HIY "��ʽ��Ȼ��������ޱȣ�һת��"
              HIY "����Ȼ����" + chinese_number(attack_time) + "�У�\n" NOR;
message_combatd(msg, me, target);
                	me->add_temp("apply/attack", 200);
	me->add_temp("apply/damage", 3800);
dmg=random((int)me->query_skill("taiji-shengong", 1))+200;
        for (i = 0; i < attack_time; i++)
        {
                 if (random(2)==0)
                 	{
                target->receive_damage("qi",dmg,me);
                target->receive_wound("qi",dmg,me);  	
                 	 if (!target->is_busy())target->start_busy(2);
                me->add("neili", -30);
                }
	msg = HIY "$N�ý����˵�"+chinese_number(i+1)+"��Ȧ��һ��������������\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
	me->add_temp("apply/attack", -200);
	me->add_temp("apply/damage", -3800);
me->start_busy(2);
        return 1;
}


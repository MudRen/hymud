// /daemon/class/yaomo/kusong/wuyue-spear/fengchan  ��������
// writted by jie 2001-2-8
// ������ ��������ȡ���Ϲ��˵۶���������
// ������������5�У�������� ƽ����ӹ ���º�� �������� ��������
// ��l=(int)me->query_skill("literate",1)�й�
// ������ʼ������3�� ������� �������� ��������
// �����ܷ����ı�ɱ�� ������������ɽ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


string get_name(string str)
{
        str="��������";
        return str;
}



int calculate_damage(object me, object target, int base_damage, int damge_bonus);
int perform(object me, object target)
{
        string msg, str;
        object weapon;
        int myskill, k, l,level;
        int ap, ap2, dp, dp2, pp,i,lmt;
        int youcps, mycor, mystr, youstr;
        int damage_bonus, damage, wound;
        int delay;
        object ob;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        


        myskill=(int)me->query_skill("wuyue-spear",1);
        if(myskill<150) 
                return notify_fail("��ģ�������ǹ�ݻ��������죡\n");
       
 
 
         
        k=(int)me->query_skill("club");

 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail(RED"��ʲô��Ц���������ԣ�\n"NOR);

        if ( !wizardp(me) && me->query_skill_mapped("force") != "hanbing-zhenqi")
                return notify_fail("��ʹ�ú�������!\n");

        if((int)me->query_skill("hanbing-zhenqi",1) < 200)
                return notify_fail("��ĺ�������������������\n"); 

        if(k<150)        
                return notify_fail("���ǹ�����𻹲�����ʹ����һ�л������ѣ�\n");
        l=(int)me->query_skill("literate",1);                   
        if((int)me->query("max_neili") < 1000 )
                return notify_fail("����ڹ�̫�\n");
        
        if((int)me->query("neili")<500) 
                return notify_fail("������������ˡ�\n");

        msg = HIC "$N������"+ weapon->query("name")+ HIC"�ҳ�һʽ\n\n";
        msg +=HIC "������������\n";
        msg +=HIC "��������ک�\n";
        msg +=HIC "������������\nһ�ɺ�Ȼ����������$nȫ��\n";
        mycor=me->query_str();
        youcps=target->query_kar();
        ob=target->query_temp("weapon");
        str="�ұ�";
        if(objectp(ob)) str="���е�"+ob->query("name");
        ap = k;
        ap = (ap /12) * ap * ap;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        ap2=me->query_skill("club",1);
        dp2=me->query_skill("dodge",1);
        dp2/=2; 
        pp=target->query_skill("parry",1);
        pp/=2;
        if(objectp(ob)) pp/=2;
        mystr=me->query_str();
        youstr=target->query_str();
        damage_bonus = k;
        damage_bonus=mystr*(damage_bonus+100+me->query("jiali"))/100;

        if( random(youcps) < 15 || random(ap+dp+ap2+dp2)>(dp+dp2)) {
                msg += "$n����"+str+HIC"һ�ܣ�����ǹ������������΢һ���ɡ�\n";
                msg += "$Nǹ�ƶ�ת��"+ weapon->query("name")+ HIC"�����������ǵĺ�Х��$n��ȥ��\n\n" NOR;
                msg += HIB "˲������ǹ���ѵ���$n���ʺ�\n";
                if(random(ap2+pp)>pp) {
                        msg +=HIB "   ������������\n";
                        msg +=HIB "   ������������\n";
                        msg +=HIB "   ������������\n��ʽ���绪ɽһ����ֱȡ$nҪ����\n";
                        damage=500+calculate_damage(me, target, 20, damage_bonus);
                        wound=500+random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("qi", damage,me);
                                if(wound>0) target->receive_wound("qi", wound,me);
                                msg+=HIB"���$n�ʺ�һ�飬��㴭����������\n" NOR;
                        }
                }
                else msg+="�����$n���ɵ����ˡ�\n" NOR;
if (myskill> 200)
{
                msg += HIW "\n������$N��ת"+ weapon->query("name")+ HIW"β����$n�Ĵ��ȣ�\n";
                msg += "ͬʱ��Х��������Ϫ����������������";
                if(random(ap2+pp)>pp) {
                        msg += "$n����˫�ۣ����Ҳ��С�\n" NOR;
                        damage=600+calculate_damage(me, target, 40, damage_bonus);
                        wound=600+random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("qi", damage,me);
                                if(wound>0) target->receive_wound("qi", wound,me);
                                msg +=HIW "      ������������\n";
                                msg +=HIW "      ���������ũ�\n";
                                msg +=HIW "      ������������\n";
                                msg +=HIW"��ʽ�������Σ����$n���Ȳ������������һ�����ӡ�\n" NOR;
                        }
                }
                else msg+="$n��׼���ƣ����������ˡ�\n" NOR;
}
if (myskill> 300)
{
                msg += HIM "\n$N����˳�����˴�"+ weapon->query("name")+ HIM"ײ��$n���·��紪�ޱʱ�ī��ֽ��";
                if(random(ap2+pp)>pp && k>170 && l>100) {
                        msg += "��$n�ε����ѣ�\n" NOR;
                        msg +=HIM "         ������������\n";
                        msg +=HIM "         �����º�婧\n";
                        msg +=HIM "         ������������\n";
                        msg +=HIM"��ʽ��á��紪�������ݺᡱ�����裡\n" NOR;
                        damage=700+calculate_damage(me, target, 60, damage_bonus);
                        wound=700+random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("qi", damage,me);
                                if(wound>0) target->receive_wound("qi", wound,me);
                                msg+=HIM"���$n�����Ժ�������ε���\n" NOR;
                        }
                }
                else msg+="���$nһ�����ģ�ȴûˤ����\n" NOR;
}
if (myskill> 500)
{
                if(random(ap2+pp)>pp && k>240 && l>140) {
                        msg += HIY "\n$Nǹ�����࣬"+ weapon->query("name")+ HIY"ƽƽ������ֱȡ��·����$n��";
                        msg += "$n����������������Ȼ��֪���Ӧ����\n" NOR;
                        msg +=HIY "            ������������\n";
                        msg +=HIY "            ��ƽ����ӹ��\n";
                        msg +=HIY "            ������������\n";
                        msg +=HIY"��ʽ�������ң��ѻ���ǹ���ġ���ƽ��һʽ���ӵ�����ۣ�\n" NOR;
                        damage=800+calculate_damage(me, target, 80, damage_bonus);
                        wound=800+random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("qi", damage,me);
                                if(wound>0) target->receive_wound("qi", wound,me);
                                msg+=HIR"������ۣ�����һ����$n�ؿڱ��������������\n" NOR;
                        }
                }
                message_vision(msg, me, target);
}
// ����һ��������
// ap2+pp>pp
// ��Ч�ȼ�����300������ʶ�ִ���180
// 300���ֵ����297
// �����Ե����25
// ͬʱ���㣬���ʼ���΢С
if (myskill> 800)
{
                  if(random(ap2+pp)>pp && k>300 && l>200 && random(5)==0 && random(me->query("kar"))>18) {
                        
                        msg = HIG "\n$N����¶���־�֮ɫ��"+ weapon->query("name")+ HIG"��Ȼ����ʹ����";
                        msg += "������ħ����һ�㣬\n��ǹ���Ѿ�����������֮�ʣ���������������ɱ����������Ծ��\n" NOR;
                        msg +=HIG "������������������\n";
                        msg +=HIG "��������������ɽ��\n";
                        msg +=HIG "������������������\n";
                        msg +=HIG"��ʽ�����ϵ���ʮ����ħ�������һ�У����ǹ������䣬��ض�ʱʧɫ��\n" NOR;
                        me->add_busy(1);
                        target->add_busy(2);
                        me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), random(2)+1);
                        message_vision(msg, me, target);
                        
                
        }       
        COMBAT_D->report_status(target); 
        } else {
                msg += "����$p������$P����ͼ�����Խ����\n" NOR;
                message_vision(msg, me, target);
        }
}        
 
 
      msg = HIY  "$Nǹ�����࣬�·��紪�ޱʱ�ī��ֽ�����е�\n"+ weapon->name()+  "���籩������$n������\n\n" NOR;
        message_vision(msg,me,target);
        lmt = random(4)+3;
        		       me->add_temp("apply/attack", 150);    
        me->add_temp("apply/damage", 1500);
        for(i=1;i<=lmt;i++)
        {
        msg =  HIC "$N���һ�����ӵ�"+chinese_number(i)+"ǹ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
		       me->add_temp("apply/attack", -150);    
        me->add_temp("apply/damage", -1500);
 
 
        me->start_busy(3);
        me->add("neili", -100);

        return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
        int damage;
        int myexp, youexp;

        damage=(int)me->query_skill("wuyue-spear",1)+base_damage+(damage_bonus+random(damage_bonus))/2;
        myexp=me->query("combat_exp");
        youexp=target->query("combat_exp");
        if(random(youexp)>myexp) {
                damage-=damage/3;
                youexp/=2;
        }
        if (wizardp(me) )
                tell_object(me, sprintf(HIC "damage: %d\n" NOR, damage));

        return damage;
}

void kill_him(object me, object target)
{
        string msg;
        int damage1;
        int damage2;
        if (!objectp(me) || !objectp(target)) return;
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
damage1=target->query("max_jing")/2;
damage2=target->query("max_qi")/2;
if (damage1 > 60000) damage1=60000;
if (damage2 > 60000) damage2=60000;
                msg =HIR"\n$nֻ������ǰһ�����ʺ��ѱ��Դ�����������\n\nһ��Ѫ����ӿ��������$n���۾�������ͻ�˳�������\n" NOR;
                target->receive_damage("jing",damage1);
                target->receive_wound("jing",damage1);
                target->receive_damage("qi",damage2);
                target->receive_wound("qi",damage2);
                COMBAT_D->report_status(target);
                        
                message_vision(msg, me, target);

        }
        return ;
}



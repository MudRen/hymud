//lestat 2001

#include <ansi.h>
inherit F_SSERVER;

int exert(object me)
{
        int invocation_time;
        object soldier;
object target;
int skill;
mapping ob_fam; 
        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в�����Τ���·���\n");
        
        if( !target ) target = offensive_target(me);
   	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		        if((int)me->query_skill("buddhism",1) < 200)
                return notify_fail("��������ķ�������������\n");

        if((int)me->query_skill("bitao-shengong",1) < 200)
                return notify_fail("��ı����ķ�������������\n"); 
                
               	if ((!(ob_fam = me->query("family")) || ob_fam["family_name"] != "������") && userp(me))
return notify_fail("�����ֲ�����Τ���·���\n"); 

if (!userp(me) && me->query_temp("nozh"))
	return notify_fail("�����޷��ٷ���\n");

if (me->query_temp("invoker"))
return notify_fail("�����޷��ٷ���\n");

if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("����һ��ս�����ޡ�\n");         
        
        invocation_time=30+(200-(int)me->query_skill("buddhism"));
        
        if(invocation_time<30) invocation_time=30;
        
        if((time()-me->query_temp("last_invocation"))<invocation_time+30 && !wizardp(me))
                return notify_fail("�����Τ���·������������㣡\n");

        if ((int)me->query_condition("zdizi_busy") && !wizardp(me))  
        return notify_fail("�����Τ���·����������㣡\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("jing") < 500 )
                return notify_fail("��ľ����޷����У�\n");

        skill=(int)me->query_skill("bitao-shengong",1);
        skill=skill*0.6;
        message_vision(HIG"$N����Ȧ���������̷�š�\n"NOR, me);
 message_vision(HIY"\n$N������࣬Խ��Խ�ǳ�Ͱ�����ȫ����������ʥ��Ĺ�ԡ�\n"NOR,me,target);
 
 
message_vision(HIY"\n��ȴ�ʼ���գ������ǻ������"NOR,me,target);
message_vision(HIY"\n�Ž⹦����Ϊ�ף�Ը������ʮ���С�"NOR,me,target);
message_vision(HIY"\n���ȱ�ʥ�����������ǻ�ʦ���⡣"NOR,me,target);
message_vision(HIY"\nʾ�����ж����ͣ�ʵ����Ը�ĵزء�\n"NOR,me,target);
 
        me->add("neili", -600);
        me->receive_damage("jing", 300);

        if( random(me->query("max_neili")) < 500 ) 
        {
                message("vision", "����ʲôҲû�з�����\n",environment(me));
                return 1;
        }

        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set("possessed", me);
	      soldier->set_name(HIY"�ֵ�Τ��"NOR,({"weituo"}));
        soldier->invocation(me);
        soldier->initlvl(skill,59);
        soldier->set_temp("nozh",1);
	 message_vision(HIG"$N�ȵ���������ħ��\n"NOR, soldier);

        if (!userp(me)) me->add_temp("zhrs",1);
        me->set_temp("last_invocation",time());
        me->start_busy(3);
        if(me->query_skill("bitao-shengong", 1) >= 400)
                call_out("sanqing2", 1, me, target);   
        return 1;
}

int sanqing2(object me, object target)
{
        object soldier;
        int skill;
        skill=(int)me->query_skill("bitao-shengong",1);
        skill=skill*0.6;

        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));

        soldier->set_temp("invoker",me);
        soldier->set_temp("invoker",me);
        soldier->set("possessed", me);
	      soldier->set_name(HIG"�ֱ�Τ��"NOR,({"weituo"}));
        soldier->invocation(me);
        soldier->initlvl(skill,57);
        soldier->set_temp("nozh",1);
	 message_vision(HIG"$N�ȵ���������ħ��\n"NOR, soldier);

        if(me->query_skill("bitao-shengong", 1) >= 600)
                call_out("sanqing3", 1, me, target);   

        return 1;
}

int sanqing3(object me, object target)
{
        object soldier;
        int skill;
        skill=(int)me->query_skill("bitao-shengong",1);
        skill=skill*0.6;

        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
        soldier->set("possessed", me);
	      soldier->set_name(HIR"����Τ��"NOR,({"weituo"}));
        soldier->invocation(me);
        soldier->initlvl(skill,58);
	 message_vision(HIG"$N�ȵ���������ħ��\n"NOR, soldier);

        return 1;
}


//jianzhen.c �����ǽ���csy 99.05.26

#include <ansi.h>

inherit F_SSERVER;

void npc_attack(object invoker, object target, string npc, object where);

int perform(object me, object target)
{
        string msg;
        string npc_dir = "/d/quanzhen/npc/";
        object where;
        int fenshen_time; //this time is the time interval fenshen can be used again. 
        object soldier;
int skill;
mapping ob_fam; 
  

        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me
        ||   !me->is_fighting(target))
                return notify_fail("������ȫ����ӶԸ�˭ѽ��\n");

        if(userp(me) && (string)me->query("family/family_name") != "ȫ���" )
                return notify_fail("���ֲ���ȫ��̵��ӣ�ȫ������������㣿�\n");

        if(userp(me) && (string)target->query("family/family_name") == "ȫ���" )
                return notify_fail("ͬ���භ��ʦ����æ��\n");

        if(me->query_temp("nojz") )
                return notify_fail("ͬ���භ��ʦ����æ��\n");

        if((int)me->query_skill("qixing-array", 1) < 150)
                return notify_fail("��ı�����������Ϊ����޷���ȫ�������Ͻ���\n"); 

        if((int)me->query_skill("quanzhen-jian", 1) < 150)
                return notify_fail("���ȫ�潣����Ϊ������ܺ�ȫ���������ϡ�\n");        

if (me->query_condition("zdizi_busy"))
return notify_fail("��ո��ٻ���������ȫ�����ˣ���ʱû�˰��㣡\n");
        if((int)me->query("neili") < 300 )
                return notify_fail("�������������û�취��ȫ���������ϡ�\n"); 
       
        if((int)me->query("jing") < 60 )
                return notify_fail("���������ǲ��壬�����������������ˣ�\n");


if (!userp(me) && me->query_temp("nozh"))
	return notify_fail("�����޷��ٷ���\n");

if (me->query_temp("invoker"))
return notify_fail("�����޷��ٷ���\n");

if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("����һ��ս�����ޡ�\n");    

if (!environment(me))
return notify_fail("�޷�ʹ��!\n");    

        me->add("neili", -50);
        me->receive_damage("jing", 10);

        if( random(me->query("max_qi")) < 60 ) 
        {
                write("�ף�������̫�أ����в��˾�Ԯ��\n");
                return 1;
        }

     msg = HIR "\n$N����һչ��һ�����������ֻ����$N���һ����ȫ��������ںδ���\n" NOR +
              HIY "\nֻ������һ�����������������ȫ����ӣ��ڴˣ�\n"NOR +
              HIR "\n$Nһָ$n�������޶��������񼫣���ʦ�ֵ�����������ˣ�\n\n" NOR;      
        message_vision(msg, me, target);
        msg = HIC "$n����$N����������üһһӵ�����ˣ��������㣡\n\n" NOR;     
        message_vision(msg, me, target);

  me->receive_damage("jing", 40);
        skill=(int)me->query_skill("qixing-array",1);
        skill=skill*0.8;
 seteuid(getuid());
        soldier = new("/d/biwu/qz");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
        soldier->set_temp("nozh",1);
        soldier->set("possessed", me);
        if (me->query("vendetta/authority")) soldier->set("vendetta/authority",1);
        soldier->add_team_member(me);
        me->add_team_member(soldier);
              soldier->set_name(this_player()->query("name")+"��ʦ�ֵ�",({"qz dizi"}));
   

        soldier->set_temp("nojz",1);
        soldier->initlvl(skill,18);
soldier->invocation(me);
        me->start_busy(2);

        return 30+random(30);
}


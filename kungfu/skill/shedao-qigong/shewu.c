// shewu.c ����
#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me)
{
    int skill,n;
    object ob,snake,target,soldier;
    me=this_player();
    skill = me->query_skill("shedao-qigong",1);


        if( !target ) target = offensive_target(me);

        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me
        ||   !me->is_fighting(target))
                return notify_fail("����Ը�˭ѽ��\n");

    if ((int)me->query("neili") < 500 )
        return notify_fail("���������������,�޷����������衹��\n");
    
    if ((int)me->query("jing") < 50 )
        return notify_fail("��ľ�������,�޷�ר�ĵ��١�\n");

    if (me->query_skill("shedao-qigong",1)<100)
        return notify_fail("����ߵ��湦������졣\n");
    
    if (skill < 100)
        return notify_fail("����ߵ��湦������졣\n");


        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("��յ��������衹\n");

    if(environment(me)->query("sleep_room"))   
        return notify_fail("�������ٻ��ƺ���̫�ʺϰɡ�\n");  

    if(environment(me)->query("no_fight"))   
        return notify_fail("�������ٻ��ƺ���̫�ʺϰɡ�\n");  

    if(me->is_busy())
        return notify_fail("��������æ���أ�\n");


    message_vision(HIB"$N��ϥ������˫�ַ��٣�ʱ���켲��ʱ�����������ƺ���δ����������\n"NOR,me); 
    
   
            message_vision("ͻȻ��$N�о���ߺ�Ӱ������ֻ��һ���Ľ��������������ӣ���������$N˫�ֵĽ����趯��\n",me);

        skill=(int)me->query_skill("shedao-qigong",1);
        skill=skill*0.8;
        seteuid(getuid());
        soldier = new("/d/biwu/dulong");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
        soldier->set("possessed", me);
        soldier->invocation(me);
        soldier->set_skill("dodge",skill*3/4);
        soldier->set_skill("dragon",skill*3/4);
        soldier->set_skill("parry",skill*3/4);        
        soldier->set_skill("unarmed",skill*3/4);
        soldier->set_skill("force",skill*3/4);   
        me->start_busy(3);
        me->add("neili",-300); 
        me->add("jing",-200); 
        me->apply_condition("zdizi_busy",5);
        me->start_busy(3);

    return 1;    
}

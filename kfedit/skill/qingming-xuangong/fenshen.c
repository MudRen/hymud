// fenshen.c ������

#include <ansi.h>
inherit F_SSERVER;

string get_name(string str)
{
        str="������";
        return str;
}

string get_help(string str)                
{
        str="ָ����������������\n"
        +"����һ��Ϊ�����ü�������㹥���Է��Լ������Է��Ĺ�����";
        return str;
}

int exert(object me)
{
	object target;
        int fenshen_time; //this time is the time interval fenshen can be used again. 
        object soldier;
int skill;
mapping ob_fam; 
  if( !target ) target = offensive_target(me);

        if((int)me->query_skill("taoism",1) < 100)
                return notify_fail("��ĵ�������������\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("ֻ��ս��ʹ��\n");


           if( !target 
         || !me->is_fighting(target) 
         || !living(target)
         || environment(target)!=environment(me))
                return notify_fail(WHT"ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if ((!(ob_fam = me->query("family")) || ob_fam["family_name"] != "�����") && userp(me))
return notify_fail("����ɲ��ܷ���\n");  

        if((int)me->query("neili") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("jing") < 100 )
                return notify_fail("���޷����о�����\n");

if (me->query_temp("nozh"))
	return notify_fail("�����޷��ٷ���\n");
	
if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("����һ��ս�����ޡ�\n");   	
	
	
        fenshen_time=60+(200-(int)me->query_skill("taoism"));
        if(fenshen_time<60) fenshen_time=60;
        if((time()-me->query_temp("last_fenshen"))<fenshen_time)
                return notify_fail("��ոշֹ����ٷ����Σ�գ�\n");
                //hehe...at least 1 minute between 2 fenshens to
                //prevent ppls using too many ���� to kill top masters...weiqi.

        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("����ù����������������㣡\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("������������ˣ�\n");
        
        if( (int)me->query("neili") <1000)
                return notify_fail("������������ˣ�\n");

        if( (int)me->query("jing") < 50 )
                return notify_fail("��ľ����޷����У�\n");

        message_vision("$N�૵����˼����������!!\n", me);

                me->add("neili",-(int)me->query_skill("taoism"));



        me->receive_damage("jing", 40);
        skill=(int)me->query_skill("qingming-xuangong",1);
        skill=skill*0.8;
 seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
        soldier->set("possessed", me);
              soldier->set_name(this_player()->query("name")+"�ķ���",({"dizi"}));
   

        soldier->invocation(me);
        soldier->initlvl(skill,41);
         message_vision(HIG"$N�ȵ�������������� ̫�������� ��\n"NOR, soldier);
         if (!userp(me)) me->add_temp("zhrs",1);
        me->set_temp("last_fenshen",time());
        me->start_busy(3);

        return 3+random(5);
}


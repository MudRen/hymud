// lifeheal.c

#include <ansi.h>

int exert(object me)
{
int damage;
        if (!wizardp(me) && !me->query("5zhuan") && !me->query("4zhuan") && !me->query("zhuanbest") && !me->query("guard/flag") && !me->query("zhuanshen"))
		return notify_fail("�����ԭ����ֻ��ת����ſ���ʹ�ã�\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("����ڹ���Ϊ��������\n");

	if( (int)me->query("max_neili") < 100 )
		return notify_fail("���������Ϊ������\n");

	if( (int)me->query("neili") < 10 )
		return notify_fail("�������������\n");
if (!me->is_fighting() && me->query_temp("zsgyf",1)>0 ) 
{
me->set_temp("zsgyf",0);
message_vision(HIR "$N����һ�������ɫ��������ˡ�\n" NOR, me);
}




if ((int)me->query_temp("zsgyf",1) >=6 && !me->query("5zhuan") && !me->query("4zhuan") && !me->query("zhuanbest") && !me->query("guard/flag"))  return notify_fail( me->name() + "��Ѫ���ڷ��ڣ��������ս���޷��ٴ�ʹ���ˡ�\n");
if ((int)me->query_temp("zsgyf",1) >=12 && !me->query("5zhuan") && !me->query("4zhuan")) return notify_fail( me->name() + "��Ѫ���ڷ��ڣ��������ս���޷��ٴ�ʹ���ˡ�\n");
if ((int)me->query_temp("zsgyf",1) >=16 && !me->query("5zhuan")) return notify_fail( me->name() + "��Ѫ���ڷ��ڣ��������ս���޷��ٴ�ʹ���ˡ�\n");
if ((int)me->query_temp("zsgyf",1) >=30) return notify_fail( me->name() + "��Ѫ���ڷ��ڣ��������ս���޷��ٴ�ʹ���ˡ�\n");

if (me->query_condition("guiyuan")) return notify_fail( me->name() + "���ù������ԭ������Ѫ���ڷ��ڣ�\n");

	if( (int)me->query("qi") >= (int)me->query("max_qi") 
	&& (int)me->query("jing") >= (int)me->query("max_jing")
	&& (int)me->query("neili") >= (int)me->query("max_neili")
	&& (int)me->query("eff_qi") >= (int)me->query("max_qi") 
	&& (int)me->query("eff_jing") >= (int)me->query("max_jing")	)
		return notify_fail( me->name() + "��δ���ˣ�\n");



message_vision(HIR "$Nҧ����� �������ԭ�� �³�һ����Ѫ ����ȫ��ľ�����Ǳ����\n" NOR, me);
if (me->is_fighting()) me->add_temp("zsgyf",1);
if (userp(me) && me->query("5zhuan"))
{
if( (int)me->query("qi") < (int)me->query("max_qi")*2) 
me->add("qi",me->query("max_qi"));
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*2) 
me->add("eff_qi",me->query("max_qi"));

if( (int)me->query("jing") < (int)me->query("max_jing")*2) 
me->add("jing",me->query("max_jing"));
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*2) 
me->add("eff_jing",me->query("max_jing"));
if( (int)me->query("neili") < (int)me->query("max_neili")*2) 
me->add("neili",me->query("max_neili"));
if (me->is_busy()) me->start_busy(1);
if (me->is_busy()) 
{
me->interrupt_me();
me->start_busy(1);
me->start_busy(0);	
}	
me->apply_condition("guiyuan",1);
}


else if (userp(me) && me->query("4zhuan"))
{
if( (int)me->query("qi") < (int)me->query("max_qi")) 
me->add("qi",me->query("max_qi")*3/4);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")) 
me->add("eff_qi",me->query("max_qi")*3/4);

if( (int)me->query("jing") < (int)me->query("max_jing")) 
me->add("jing",me->query("max_jing")*3/4);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")) 
me->add("eff_jing",me->query("max_jing")*3/4);
if( (int)me->query("neili") < (int)me->query("max_neili")) 
me->add("neili",me->query("max_neili")*3/4);
if (me->is_busy()) 
{
me->interrupt_me();
me->start_busy(1);
me->start_busy(0);	
}	
me->apply_condition("guiyuan",1);
}

else if (userp(me) && me->query("zhuanbest"))
{
if( (int)me->query("qi") < (int)me->query("max_qi")) 
me->add("qi",me->query("max_qi")*3/4);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")) 
me->add("eff_qi",me->query("max_qi")*3/4);

if( (int)me->query("jing") < (int)me->query("max_jing")) 
me->add("jing",me->query("max_jing")*3/4);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")) 
me->add("eff_jing",me->query("max_jing")*3/4);
if( (int)me->query("neili") < (int)me->query("max_neili")) 
me->add("neili",me->query("max_neili")*3/4);
if (me->is_busy()) 
{
me->interrupt_me();
me->start_busy(1);
me->start_busy(0);	
}	
me->apply_condition("guiyuan",1);
}


else if (userp(me) && me->query("zhuanshen"))
{
if( (int)me->query("qi") < (int)me->query("max_qi")) 
me->add("qi",me->query("max_qi")*1/2);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")) 
me->add("eff_qi",me->query("max_qi")*1/2);

if( (int)me->query("jing") < (int)me->query("max_jing")) 
me->add("jing",me->query("max_jing")*1/2);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")) 
me->add("eff_jing",me->query("max_jing")*1/2);
if( (int)me->query("neili") < (int)me->query("max_neili")) 
me->add("neili",me->query("max_neili")*1/2);
if (me->is_busy()) 
{
me->interrupt_me();
me->start_busy(1);
me->start_busy(0);	
}	
me->apply_condition("guiyuan",2);
}

if (!me->is_fighting() ) me->apply_condition("guiyuan",3);		



	return 1;
}

// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if ((int)me->query_skill("wudu-shengong", 1) < 30)
		return notify_fail("����嶾����Ϊ��������\n");
	if( (int)me->query("neili") < 50 ) 
		return notify_fail("�������������\n");
       
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "��ȫ����ɣ��嶾����תȫ��\n" NOR);
	message("vision",
		HIW + me->name() + "����ֳ�һƬ���죬��ͷ���߳�ϸϸ�ĺ��顣\n" NOR,
		environment(me), me);
       me->set_temp("nopoison", 1);
       me->clear_condition("yf_poison");
       me->clear_condition("nx_poison");
       me->clear_condition("x2_poison");
       me->clear_condition("xx_poison");
       me->clear_condition("ice_poison");
       me->clear_condition("ss_poison");

if (me->query_condition("ill_fashao"))
        me->clear_condition("ill_fashao");
if (me->query_condition("ill_kesou"))
        me->clear_condition("ill_kesou");
if (me->query_condition("ill_shanghan"))
        me->clear_condition("ill_shanghan");
if (me->query_condition("ill_zhongshu"))
        me->clear_condition("ill_zhongshu");
if (me->query_condition("ill_dongshang"))
        me->clear_condition("ill_dongshang");
                if (me->query_condition("scorpion_poison"))
        me->clear_condition("scorpion_poison");
                if (me->query_condition("ss_poison"))
        me->clear_condition("ss_poison");
                if (me->query_condition("drunk"))
                        me->clear_condition("drunk");
                if (me->query_condition("flower_poison"))
                        me->clear_condition("flower_poison");
                if (me->query_condition("ice_poison"))
                        me->clear_condition("ice_poison");
                if (me->query_condition("iceshock"))
                        me->clear_condition("iceshock");
                if (me->query_condition("rose_poison"))
                        me->clear_condition("rose_poison");
                if (me->query_condition("scorpion_poison"))
                        me->clear_condition("scorpion_poison");
                if (me->query_condition("slumber_drug"))
                        me->clear_condition("slumber_drug");
                if (me->query_condition("snake_poison"))
                        me->clear_condition("snake_poison");
                if (me->query_condition("ss_poison"))
                        me->clear_condition("ss_poison");
                if (me->query_condition("xx_poison"))
                        me->clear_condition("xx_poison");
        if (me->query_condition("snake_poison"))
        {          me->clear_condition("snake_poison");}
        if (me->query_condition("wugong_poison"))
        {          me->clear_condition("wugong_poison");}
        if (me->query_condition("zhizhu_poison"))
        {          me->clear_condition("zhizhu_poison");}
        if (me->query_condition("xiezi_poison"))
        {          me->clear_condition("xiezi_poison");}
        if (me->query_condition("chanchu_poison"))
        {          me->clear_condition("chanchu_poison");}
        if (me->query_condition("xx_poison"))
        {          me->clear_condition("xx_poison");}
        if (me->query_condition("cold_poison"))
        {          me->clear_condition("cold_poison");}
        if (me->query_condition("flower_poison"))
        {          me->clear_condition("flower_poison");}
        if (me->query_condition("chilian_poison"))
        {          me->clear_condition("chilian_poison");}
        if (me->query_condition("yufeng_poison"))
        {          me->clear_condition("yufeng_poison");}
        if (me->query_condition("anqi_poison"))
        {          me->clear_condition("anqi_poison");}
       if (me->query_condition("yf_poison"))
        {          me->clear_condition("yf_poison");}
       if (me->query_condition("nx_poison"))
        {          me->clear_condition("nx_poison");}
       if (me->query_condition("x2_poison"))
        {          me->clear_condition("x2_poison");}
       if (me->query_condition("sanpoison"))
        {          me->clear_condition("sanpoison");}
       
       if (me->query_condition("insect_poison"))
        {          me->clear_condition("insect_poison");}
        
      
        if (me->query_condition("snake_poison"))
        {          me->clear_condition("snake_poison");}
        
        if (me->query_condition("wugong_poison"))
        {          me->clear_condition("wugong_poison");}
        
        if (me->query_condition("zhizhu_poison"))
        {          me->clear_condition("zhizhu_poison");}
        if (me->query_condition("xiezi_poison"))
        
        {          me->clear_condition("xiezi_poison");}
        
        if (me->query_condition("chanchu_poison"))
        {          me->clear_condition("chanchu_poison");}
        if (me->query_condition("wuhudu_poison"))
        {          me->clear_condition("wuhudu_poison");}

       
	write( HIW "���������һ�������������չ鵤��о�����ö��ˡ�\n" NOR);
	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	return 1;
}

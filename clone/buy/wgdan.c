// shenliwan.c ��Ե��

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "�书��" NOR, ({ "wg wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ���߲ʵ��书������˵����(usewg)��������ָ���书һ�ټ�(���600��)��\n");
                set("value", 10000);
		set("no_put",1);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "usewg");
}

int do_eat(string arg)
{
	object me;
	string skillname;
	int skill, skill_basic, times, pertimes;
	
        if (! arg)
                return notify_fail("��Ҫ���Ӽ�ʲô�书��\n");

        me = this_player();



	skill = me->query_skill(arg, 1);
	if( skill < 1 )
		return notify_fail("�����û��ѧ������ܰɣ�\n");

		if( (string)SKILL_D(arg)->type()=="knowledge" )
return notify_fail("֪ʶ�༼�ܳ����û�õġ�\n");
		
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if ((skill+1) > 601)
        {
                message_vision("$Nգգ�ۡ�\n", me);
                tell_object(me, "�������ҩûɶζ���������绨���óԡ�\n");
        } else
{
                tell_object(me, HIR "������ƺ��Լ������˱仯��\n" NOR);
                me->add_skill(arg, 100);
                me->set_skill(arg, skill+100);
}
        destruct(this_object());
	return 1;
}

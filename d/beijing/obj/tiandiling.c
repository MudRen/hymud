#include <ansi.h>
//shenshe.c
inherit ITEM;
void create()
{
	set_name("��ػ�����", ({ "tiandi ling", "xinwu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��ػ������������ػ�����ͨ�������ص���ػ��ܶ档(��Ҽ���home����)\n");
		set("unit", "��");
		set("value", 0);
	}
}
void init()
{
	add_action("do_home","home");
}
int do_home()
{
	string dir;
	object me = this_player();
        object ob;
//if( !SKILL_D(skill_name[item])->valid_learn(me) )
//return SKILL_D(skill_name[item])->valid_learn(me);
        if (me->is_busy())
            return notify_fail("��������æ���ء�\n");
        if (me->is_fighting() )
            return notify_fail("�����޷�ʹ���������!\n");

        if( !objectp(ob = present("tiandi ling", me)) )
                return notify_fail("��û�����ֶ�����\n");
                
    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       ||environment(me)->query("magicroom"))
		return notify_fail("�����޷�ʹ���������! \n");
		
        if (!environment(me)->valid_leave(me,"up"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"down"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"enter"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"out"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"east"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"west"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"south"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"north"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"southeast"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"southwest"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"northeast"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"northwest"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"eastup"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"westup"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"southup"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"northup"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"eastdown"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"westdown"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"southdown"))
		return notify_fail("�����޷�ʹ���������! \n");
        if (!environment(me)->valid_leave(me,"northdown"))
		return notify_fail("�����޷�ʹ���������! \n");
	if(me->query("family/family_name") != "������")
	return notify_fail("�㲻�������ŵ��ӣ������޷�ʹ��������\n");
	message_vision("$N�ӻ����ͳ���ػ������ϵ�˸����������ŵ��ӣ�\n
	�ͼ�$N������һ������������ʧ�ˡ�������\n",me);
	me->move("/d/beijing/dating");
        me->start_busy(6);
        me->add("jing",-me->query("eff_jing")/20);
//	destruct(this_object());
	return 1;
}

//yitianjian.c

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("���н�", ({ "tianyi jian", "tianyi","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 100000);
//        	set("no_drop", "1");
        	set("material", "iron");
        	set("long", "�������µ�һ�����ķ���Ʒ���С����첻����˭�����桱֮˵��\n");
        	set("wield_msg","ֱ�������ˮ���������һ�㣬$n����$N���У����Ϊ֮��ɫ��\n");
        	set("unwield_msg", "$N��$n������䣬�����������ؼ�ֻ��������\n");
	}
    	init_sword(860);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
if (random(5)==0)
{
        victim->receive_damage("qi", me->query("str") * 5);
        victim->receive_wound("qi", me->query("str") * 4);
        return WHT "���н�Я�Ŵ̹Ƿ���������ʣ�$n"
               WHT "ֻ��ȫ��������һ˿˿���Ž���ӿ����\n" NOR;
}
        return damage_bonus;
}

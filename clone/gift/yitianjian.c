//yitianjian.c

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("天倚剑", ({ "tianyi jian", "tianyi","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 100000);
//        	set("no_drop", "1");
        	set("material", "iron");
        	set("long", "这是天下第一利器的仿制品，有“倚天不出，谁与争锋”之说。\n");
        	set("wield_msg","直如矫龙吞水，长虹冠日一般，$n已在$N手中，天地为之变色。\n");
        	set("unwield_msg", "$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。\n");
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
        return WHT "天倚剑携着刺骨风声划破天际，$n"
               WHT "只觉全身力气竟一丝丝随着剑锋涌出。\n" NOR;
}
        return damage_bonus;
}

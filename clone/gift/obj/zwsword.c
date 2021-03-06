// #pragma save_binary

// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIC "真武剑" NOR, ({ "zwsword" }) );
	set_weight(7000);
        set("owner","张三丰");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "这是武当镇山之宝的真武宝剑。\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        set("task",1);
        set("no_put_in",1);
	}
	init_sword(900);
	setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;


        switch (random(5))
        {
        case 0:
                victim->start_busy(me->query_skill("sword") / 40 + 2);
                return HIC "$N" HIC "跨前一步，手中的" NOR + HIY "真武剑" NOR
                       + HIC "幻化成无数圆圈，向$n" HIC "逼去，剑法细密之极。"
                       "$n" HIC "大吃一\n惊，不知如何抵挡，只有连连后退！\n" NOR;

        case 1:
                n = me->query_skill("sowrd",1);
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                n = victim->query("jing");
                n /= 3;
                if (n > 6000) n=6000;
                victim->receive_damage("jing", n);
                victim->receive_wound("jing", n / 2);
                return random(2) ? HIY "$N" HIY "一声长吟，手中的真武剑化作一"
                                   "到长虹，“唰”的扫过$n" HIY "而去！\n" NOR:
                                   HIY "$N" HIY "突然大声喝道：“邪魔外道，还"
                                   "不受死？”手中真武剑" HIY "忽的一抖，$n"
                                   HIY "登时觉得眼花缭乱！\n" NOR;
        }

        // double effect
        return damage_bonus;
}

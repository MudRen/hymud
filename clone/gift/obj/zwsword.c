#pragma save_binary
 
// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIC "���佣" NOR, ({ "zwsword" }) );
	set_weight(7000);
        set("owner","������");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "�����䵱��ɽ֮�������䱦����\n");
		set("value", 10000);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
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
                return HIC "$N" HIC "��ǰһ�������е�" NOR + HIY "���佣" NOR
                       + HIC "�û�������ԲȦ����$n" HIC "��ȥ������ϸ��֮����"
                       "$n" HIC "���һ\n������֪��εֵ���ֻ���������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("sowrd",1);
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                n = victim->query("jing");
                n /= 3;
                if (n > 6000) n=6000;
                victim->receive_damage("jing", n);
                victim->receive_wound("jing", n / 2);
                return random(2) ? HIY "$N" HIY "һ�����������е����佣����һ"
                                   "�����磬��ৡ���ɨ��$n" HIY "��ȥ��\n" NOR:
                                   HIY "$N" HIY "ͻȻ�����ȵ�����аħ�������"
                                   "�����������������佣" HIY "����һ����$n"
                                   HIY "��ʱ�����ۻ����ң�\n" NOR;
        }

        // double effect
        return damage_bonus;
}

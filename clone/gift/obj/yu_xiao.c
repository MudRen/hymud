#pragma save_binary
 
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{  
        set_name( CYN"����" NOR,({ "yu_xiao" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "ֻ");
        set("long","һֻ��Ө͸��������������������ġ�������ż�����\n"
					HIM"\t\tӯӯ��\n"NOR);
        set("value", 100000);
        set("material", "�������");
        set("wield_msg", "$N�ӻ�������һֻ$n��Ϊ������\n");
        set("unwield_msg", "$N�����е�$n���뻳�\n");
        set("owner","�����");
		set("task",1);	
        set("no_put_in",1);
            }
                init_sword(950);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        switch (random(6))
        {
        case 0:
                n = me->query_skill("staff",1);
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIG "$N" HIG "����������һ�񣬵�ʱ�ó������Ӱ�����$n"
                       HIG "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
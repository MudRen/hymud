#include <weapon.h>
#include <ansi.h>
inherit CLUB; 
void create()
{
        set_name(HIW"����ɫ�ĳ�ǹ"NOR, ({ "silver spear" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������ĳ�ǹ��������Լ��ʮ�������ҡ�\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ����$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������¡�\n");
        }
        ::init_club(255);
}    
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_jing");
        victim->receive_damage("jing",dam/10);
        return HIW"��ǹǹ���Ϸ���һ���׹⣬������������$n����$n���Ķ��ײ��ܶ�����\n" NOR;
}   
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
    set_name( HIG "��絶" NOR, ({ "windblade" }) );
    set_weight(70000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
            "һ�������񣬵���һ����ֻ��ı���������ʮ�����������֮һ\n");
        set("for_bandit",1);
        set("material", "steel");
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        set("value", 6000);
/*      set("no_sell",1);
        set("no_get",1);
        set("no_drop",1); */ 
    }
    
    ::init_blade(375);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    int pro;
    int dam;
    dam = (int) me->query("max_neili");
    if((int)victim->query("jing") > (int)victim->query("max_jing")*3/4)
    if (dam> 10000) dam=10000;
    victim->receive_damage("jing",dam/20);
    return HIG "��絶�����ĺ�Х���ŵ�$n��������\n" NOR;
}
 
/*void owner_is_killed(object killer)
{
        message_vision(HIG"\n \n ��絶 " NOR +"���ڵ��ϣ��ֵ���$N�Ļ��У�\n\n",killer);
        this_object()->move(killer);
}*/    

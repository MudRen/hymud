#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name( CYN "清风剑" NOR, ({ "wind sword","sword" }) );
    set_weight(7000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long",
            "一把明如秋水的宝剑。\n");
        set("for_bandit",1);
        set("material", "steel");
        set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
        set("unequip_msg", "$N将手中的$n插入腰间剑鞘。\n");
        set("value", 3000); 
    }
    
    ::init_sword(533);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    int pro;
    int dam;
        dam = (int) me->query("max_jing")/10;
        if (dam> 10000) dam=10000;

//    if((int)victim->query("jing") > (int)victim->query("max_jing")*3/4)
    victim->receive_damage("jing",random(dam)+1);
    return CYN "清风剑仿佛如清风吹过，$n的心神不禁一荡。\n" NOR;
}
        

 // tblade.c
#include <ansi.h> 
#include <weapon.h> 
inherit HAMMER;
void create()
{
        set_name(WHT"���黷"NOR, ({ "lover ring","ring" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ˫���������������\n
���������һ�ֺޣ���ޣ�\n"
);
                set("value", 1000);
                set("material", "silver");
                set("rigidity", 100000); 
        }
        ::init_hammer(30);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        me->add("bellicosity",10+random(30));
        return HIR "$N�����б������������\n"NOR;
} 

 // TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
    set_name("������", ({ "shengkuai" }) );
    set_weight(50000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "һ����ط�����������\n");
    set("rigidity", 400);
        set("for_create_weapon",1);
        set("value", 2000);
        set("material", "heavyiron");
        set("base_damage",15);
    set("max_enchant",6);
    }
    
    ::init_hammer(115);
}  

 // TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("������", ({ "shoukuai" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ص������顣\n");
                set("rigidity", 800);
                set("for_create_weapon",1);
                set("value", 5500);
                set("material", "copper");
                set("base_damage",25);
                set("max_enchant",4);
        } 
        ::init_hammer(325);
}      

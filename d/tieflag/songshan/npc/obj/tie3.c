 // TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("������", ({ "zhukuai" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ط�����������\n");
                set("rigidity", 600);
                set("value", 5000);
                set("base_damage",20);
                set("for_create_weapon",1);
                set("material", "heavyiron");
                set("max_enchant",5);
        } 
        ::init_hammer(120);
}    

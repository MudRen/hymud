 // TIE@FY3
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("������", ({ "tiekuai" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����صĺ����顣\n");
                set("rigidity", 1000);
                set("for_create_weapon",1);
                set("value", 9000);
                set("base_damage",30);
                set("material", "iron");
                set("max_enchant",3);
        } 
        ::init_hammer(530);
}     

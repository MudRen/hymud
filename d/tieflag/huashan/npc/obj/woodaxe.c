 // woodaxe.c
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name(HIR"��ͷ"NOR, ({ "woodaxe" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ��������ľ�ĵĸ�ͷ��\n"
);
                set("value", 1000);
                set("material", "steel");
                set("rigidity", 10000);
                
        } 
        ::init_axe(20); 
}
   

#include <weapon.h>
inherit THROWING; 
void create()
{
        set_name("��", ({ "golden flower", "flower" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long",     "һ��ƽ������黨\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 50);
                set("base_value", 1000);
        }
        set_amount(99);
        init_throwing(100);
        setup();

}   

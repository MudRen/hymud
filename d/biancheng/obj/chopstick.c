#include <weapon.h>
inherit THROWING; 
void create()
{
        set_name("�����", ({ "chopstick" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "֦");
                set("unit", "Щ");
                set("long", "һ�ԳԷ��õ�����ӡ�\n");
                set("base_weight", 40);
                set("base_value", 5);
        }
        set_amount(1);
        ::init_throwing(2);
}   

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(RED"С��ɵ�"NOR, ({ "flying blade","feidao" }) ); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("wield_msg","$N��֪������ͻȻ��ק��һ�ѱ�����$n�������\n");
                set("unit", "Щ");
                set("base_value", 1);
                set("hxweapon",1);
                set("material", "steel");
                set("base_unit", "��");
                set("base_weight", 10); 
        }       
        set_amount(1);
        init_throwing(200);
        setup();
}

 //  An example non-weapon type of weapon
#include <weapon.h>
inherit RING;
void create()
{
        set_name("����", ({ "ironfist" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������������\n");
                set("value", 50);
                set("material", "steel");
        }
        init_ring(10); 
        set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
        set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");  
}       

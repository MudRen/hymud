 //  An example non-weapon type of weapon
#include <weapon.h>
inherit RING;
void create()
{
        set_name("��ָ��", ({ "steelfist" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ִ����ָ�ס�\n");
                set("value", 50);
                set("material", "steel");
        }
        init_ring(30); 
        set("wield_msg", "$N�ӻ�������һ��$n�������ϡ�\n");
        set("unwield_msg", "$N�����ϵ�$n���������뻳�С�\n");  
}  

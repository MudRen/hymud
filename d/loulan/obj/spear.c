#include <weapon.h>
inherit SPEAR; 
void create()
{
        set_name("�滨ǹ", ({ "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���Ѫɳ���ϵĽ�ʿ���õĳ�ǹ��\n");
                set("value", 10);
                set("material", "steel");
        }
        init_spear(45);
        set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");
}  

 // Tie@fengyun
#include <weapon.h> 
inherit BLADE; 
void create()
{
    set_name("ֽ��", ({ "paper dagger","dagger" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѱ���ֽ�������Ķ̵���\n");
        set("value", 5000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        }
    init_blade(60);
}

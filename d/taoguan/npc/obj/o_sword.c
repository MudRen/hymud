#include <weapon.h>
inherit SWORD; 
void create()
{
    set_name("��ľ��", ({ "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "һ��������ĺ�ľ���ɵı�����\n");
        set("value", 20000);
                set("material", "steel");
        }
    ::init_sword(40); 
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");  
}    

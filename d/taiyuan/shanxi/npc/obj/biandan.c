#include <weapon.h>
#include <ansi.h>
inherit STAFF; 
void create()
{
        set_name("�ⵣ", ({ "biandan" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ֳ��ִֵıⵣ��\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        ::init_staff(105);
}  

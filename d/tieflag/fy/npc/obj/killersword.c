 // sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name(HIR"ɱ����"NOR, ({ "killerdagger" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "ɱ�˲�մѪ��������\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�ػػ��ڡ�\n");
        }
        ::init_sword(55);
}   

 // sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>
inherit DAGGER; 
void create()
{
        set_name(YEL"��ͼذ"NOR, ({ "over dagger" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�̿�����õ�������\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�ػػ��ڡ�\n");
        }
        ::init_dagger(91);
}   

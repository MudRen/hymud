#include <weapon.h>
inherit SWORD; 
void create()
{
        set_name("��ľ��", ({ "black clip", "clip" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200);
                set("material", "wood");
                set("wield_msg", "$N��ͷ�ϰ���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n����ͷ�ϡ�\n");
        }
        ::init_sword(10);
}    

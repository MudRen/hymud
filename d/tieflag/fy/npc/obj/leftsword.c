#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name( HIC "��潣" NOR, ({ "left-sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ǰ���潣�б���һ�����潣�������ᱡ���������㣬�����ʺ���Ʋ��ʹ�á�\n");
                set("value", 2500);
                set("material", "steel");
                set("wield_msg", "$N����һ�����γ�$n�������֡�\n");
                set("unwield_msg", "$N�����е�$n������\n");
/*              set("no_drop",1);
                set("no_get",1);
                set("no_sell",1);*/
        }
        init_sword(305);
} 

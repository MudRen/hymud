#include <weapon.h>
#include <ansi.h>
inherit CLUB; 
void create()
{
      set_name(HIC"��ǹ"NOR, ({ "yin spear","spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "һ�˷����������쳣����ǹ��\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N��֪��ʲô�ط�����һ��$n,��ৡ���һ���������С�\n");
                set("unwield_msg", "$N�����е�$n����\n");
        }
    ::init_club(360);
}  

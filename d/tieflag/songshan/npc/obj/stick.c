 // staff.c : Gun zi
#include <weapon.h> 
inherit CLUB; 
void create()
{
        set_name("ɮ��", ({ "monk-stick" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������൱��ͨ��ɮ��");
                set("value", 300);
                set("material", "wood");
        }
        init_club(130);
        set("wield_msg", "$N��$n�������������С�\n");
        set("unwield_msg", "$N�ɿ������е�$n��\n");
} 

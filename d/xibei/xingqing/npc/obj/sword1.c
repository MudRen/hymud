//  standard sword.c(�ڶ���) edit by lin on March 3,  97
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
//inherit F_SAVE;
//inherit F_AUTOLOAD;
void create()
{
        set_name("����", ({ "sword"}) );
        set_weight(1500);
        set("long","һ�Ѿ��ִ�͵ĳ������������濪�У����Ƿ�����\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1500);
                set("material", "steel");
        }
        init_sword(15);
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        setup();
}


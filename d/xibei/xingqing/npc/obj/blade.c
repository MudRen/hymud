//  standard blade.c(��͵�) edit by lin on March 3,  97
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
//inherit F_SAVE;
//inherit F_AUTOLOAD;
void create()
{
        set_name("�ӵ�", ({ "blade"}) );
        set_weight(2500);
        set("long","һ������ͨͨ����������Լ����\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "iron");
        }
        init_blade(15);
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        setup();
}


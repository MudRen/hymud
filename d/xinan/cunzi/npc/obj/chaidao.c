//writen by lnwm
//chaidao.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
        set_name("��", ({ "chai dao","dao","axe"}) );
        set_weight(1500);
        set("long","ɽ�񿳲��õĲ�\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value",100);
                set("material", "steel");
        }
        init_axe(5);
        set("wield_msg", "$N���һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        setup();
}


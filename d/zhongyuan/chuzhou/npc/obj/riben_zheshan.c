// �ձ����� /d/city/chuzhou/npc/obj/riben_zheshan.c
// by lala, 1997-12-14

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( WHT"ֽ����"NOR, ({ "zhe shan","fan"}) );
        set_weight(100);
        set("long","һ���ձ����������ȣ���ֽ���棬����ʲôҲû�л���\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 600);
                set("material", "bamboo");
        }
        init_sword(11);
        set("wield_msg", "$N��һ�������������С�\n");
        set("unwield_msg", "$N�����е�$n���س������\n");
        setup();
}

// �ձ����� /d/city/chuzhou/npc/obj/wodao.c
// by lala, 1997-12-14

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name("����", ({ "wo dao", "blade"}) );
        set_weight(2500);
    set("long", @LONG
�ձ������ĵ�����Ϊ�������ձ��ı������켼���ܸߣ������õĸ��ʵغܺá���
������ʮ�ַ�����������ԭ������ʿ��ϲ����
LONG
    );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "steel");
        }
        init_blade(35);
        set("wield_msg", "$N��ৡ���һ�����һ�Ѻ�����˵�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
        setup();
}

// windspring.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
// inherit F_UNIQUE;

void create()
{
        set_name( CYN "��Ȫ֮��" NOR, ({ "sword of windspring", "sword" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "���ǲ����������ഫ���������տ��ɫ�Ľ�������ɫ������ʹ\n"
                        "�÷�Ȫ֮����Ϊ���С���֮���ߡ�������������֮�⣬��ѽ�Ҳ��\n"
                        "���������������\n");
                set("value", 15000);
                set("material", "sapphire");
                set("wield_msg", "$N��ˢ����һ�����һ�����������$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
                set("weapon_prop/courage", 15);
                set("weapon_prop/intelligence", 15);
                set("weapon_prop/personality", 15);
                set("rigidity", 40);
                set("replica_ob", "/obj/longsword");
        }

        init_sword(575);
        setup();
}
/*
void owner_is_killed(object killer)
{
        object soul;

        if( environment()->id("sword soul") ) return;

        if( !killer ) killer = environment();
        seteuid(getuid());
        soul = new(__DIR__"sword_soul");
        soul->move(environment(killer));
        move(soul);
        wield();
        soul->reset_action();

        tell_room(environment(killer),
                "\n�㿴����Ȫ֮�������ڵ��� ... \n"
                "\n�� ... ��Ʈ��������һ�����κ�Ȼ���֣�������������Ȫ֮����\n\n");
        soul->chant();
}
*/
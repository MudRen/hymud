// ganjiangsword.c
// by dicky

#include <weapon.h>
#include <ansi.h>
inherit SWORD;


void create()
{
        set_name(HIB"Īа"NOR, ({ "moxie sword","sword" }) );
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("no_get", 1);
		set("no_give", 1);

		set("long", "�˽��������а룬���������������������������ޱȣ�
����������ȴ����ɱ����ʵ�����µ�һ������\n");
		set("value", 2000);
		set("material", "blacksteel");
		set("wield_msg", HIY"$Nֻ�������ˡ���һ�����ڹ����֣�$N�ӱ�����Īа��
�پ��������棬������Ȼ��\n"NOR);             
                set("unwield_msg", BLU "$N��Īа����Īа����һ���Ϲ⣬��ৡ��ط��뽣�ʡ�\n" NOR);
		set("wield_skill",([
			"sword" : 100,
		]));
		set("wield_ability",([
			"combat_exp" : 50000,
		]));
	}
        init_sword(920);
        setup();
}

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"���̽�"NOR, ({ "feiyu sword","sword" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���̽����������ɽ֮����\n");
                set("value", 5000);
                set("material", "black_iron");
		set("wield_msg", "$N���һ��ѩ�׵�$n��������,��ʱ����ɱ������.\n");
		set("unwield_msg", "$N�����е�$n��ؽ����С�\n");
		set("wield_skill",([
			"sword" : 150,
		]));
		set("wield_ability",([
			"combat_exp" : 500000,
		]));
        }

        init_sword(580);
        setup();
}

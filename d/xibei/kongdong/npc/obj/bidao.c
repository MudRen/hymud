#include <weapon.h>
#include <ansi.h>
inherit BLADE;


void create()
{
	set_name(GRN"�̵�"NOR, ({"bi dao","blade"}) );
	set_weight(2000);
        set("long","һ����״���صĶ̵���Ѫ�ۼ��֣�������һ���̹�͸����\n" NOR);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",15000);
                set("cant_sell","����ѵ���˭���ģ���С��ɲ������ۣ�\n");
		set("material", "steel");
	}
	init_blade(35);
	set("wield_msg", "$N��ৡ���һ�����һ�����λε�$n�������С�\n");
	set("unwield_msg", "$N�����е�$n�������䡣\n");
	setup();
}

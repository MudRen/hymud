// liuyun-sword.c
// edit by pian
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name( "ľ��" , ({ "wood sword" }) );
	set_weight(6000);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
һ��Ӳľ��ɵĽ����������й��ӵĻ��ƣ����Ѿ����̻�Ѭ��������ڵ��ˡ�
LONG
);

		set("valid_number",3);
		set("value", 300);
		set("material", "wood");
		set("wield_msg", "$N��ˢ����һ�����һ��������ڵ�$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
}
        init_sword(15);
        setup();
}

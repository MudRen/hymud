// jinghong_sword.c

#include <ansi.h>
#include <weapon.h>


inherit SWORD;

void create()
{
	set_name( RED "���豦��" NOR, ({ "jinghong sword" }) );
	set_weight(8000);
	set("valid_number",1);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long","����һ�ѻ���ı������������ɻƽ��ͣ�
����Ƕ�Ÿ�ɫ��ʯ��������󣬽�������
���ӳ���·���˿˿����ɫ�Ĺ⡣\n"
);
		set("value", 5000);
		set("material", "black_iron");
		set("wield_msg", "$N��ˢ����һ�����һ�����������$n�������С�\n");
		set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
		set("weapon_prop/karma", 10);
		set("weapon_prop/intelligence", 5);
		set("weapon_prop/personality", 5);
	}

	init_sword(575);
	setup();
}

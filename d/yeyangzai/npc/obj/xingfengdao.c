// blade.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name("�ȷ絶",({"xingfengdao","dao","blade"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value",3000);
		set("material", "iron");
		set("long","һ�������ĸֵ������淺���������̹⡣\nһ����ζֱ�����ţ��ƺ��ж���\n");
		set("wield_msg",GRN"$N�ӵ����г��$n��"+
		RED"��ʱ����������ɱ����\n"NOR);
		set("unequip_msg","$N���˸���������$n���뵶���С�\n");
	}
	init_blade(170);
	setup();
}

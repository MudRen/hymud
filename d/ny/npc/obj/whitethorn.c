
// blackthorn.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("���޽�", ({ "whitethorn sword", "whitethorn", "sword" }) );
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"����һ��ͨ��Ұ׵��ؽ������������˼���ĵ�����������������\n"
			"�����ഫ�ı�������˵��ѽ�ɱ�˼�Ѫ����Զ��մɱ����\n");
		set("value", 2400);
		set("material", "greysteel");
		set("wield_msg", "ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
		set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(63);
	setup();
}

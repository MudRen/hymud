// gangzhang.c ����

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("�Ͷ���", ({ "fo club" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ƿ����� �Ͷ�����\n");
		set("value", 5000);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�ջء�\n");
	}
  	init_club(725);
	setup();
}

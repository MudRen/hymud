#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("�����", ({"dragon mace", "mace", "ironmace"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 500);
    set("material", "iron");
    set("long", "һ����ɫ���̻���ﵡ�\n");
    set("wield_msg", "$N����һ��$n�����˸���ʽ��\n");
    set("unwield_msg", "$N��$n������䡣\n");
  }
  init_staff(650);
  setup();
}


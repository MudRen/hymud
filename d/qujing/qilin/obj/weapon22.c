#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("ԧ���", ({ "yuanyang gun", "gun", "staff" }) );
  init_staff(40);
  set("unit", "��");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 410);
    set("material", "bone");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}


#include <weapon.h>

inherit CLUB;

void create()
{
  set_name("������", ({ "tie jingji", "jingji", "club" }) );
  init_club(35);
  set("unit", "��");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 400);
    set("material", "iron");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}


#include <weapon.h>

inherit CLUB;

void create()
{
  set_name("�̻��", ({ "cihuai jian", "jian", "club" }) );
  init_club(25);
  set("unit", "��");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 240);
    set("material", "wood");
  }
  setup();
}


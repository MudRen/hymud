//Cracked by Roath

#include <weapon.h>

inherit CLUB;

void create()
{
  set_name("�ڷ��", ({ "wufeng jian", "jian", "club" }) );
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 1000);
    set("material", "steal");
    set("long", "һ������ɫ��������ڷ�ﵡ�\n");
    set("wield_msg", "$N����$n�������һ������ﵡ�\n");
  }
  init_club(65);
  setup();
}


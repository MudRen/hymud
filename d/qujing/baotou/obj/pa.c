// rake.c

#include <weapon.h>

inherit F_UNIQUE; 
inherit STAFF;

void create()
{
  set_name("С�ų���", ({ "xiao jiuchi pa", "jiuchipa", "pa","staff" }) );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 2000);
    set("material", "iron");
    set("no_sell", 1);
    //set("no_drop", 1);
    set("is_monitored", 1);
    set("replace_file", "/d/obj/weapon/rake/gangpa");
    set("long", "һ���ų��٣��������Ƴ��ѡ�\n");
    set("wield_msg", "$N����һ��$n��������˳��һ����\n");
    set("unwield_msg", "$N����$n�������һ�ϡ�\n");
  }
  init_staff(665);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("һ������������$n��ͻ��������ϼ�������ˣ�\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();


  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}


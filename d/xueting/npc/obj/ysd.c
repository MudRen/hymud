// by dicky 2002/11/6

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name( "����" , ({"yangshen dan", "dan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ź����͵�������\n");
    set("value", 10000);
    set("no_sell", 1);
    set("food_remaining", 100);
    set("drug_type", "��Ʒ");
  }
  setup();
  }

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="yangshen dan" && arg!="dan") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*3+random(120));
  me->set("water", (int)me->max_water_capacity()*3+random(120));
  message_vision(HIG "$N����һ�������ͽ��������¡�\n" NOR, me);
  tell_object(me, "��ʱ����ø������ȣ�ƮƮ���ɣ�\n");
  destruct(this_object());
  return 1;
}


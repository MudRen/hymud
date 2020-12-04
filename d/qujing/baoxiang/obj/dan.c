
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG "�������ڵ�" NOR , ({"shelizi neidan", "neidan", "dan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ż�������������ڵ��������������֮ĥ�ѣ����˼�ת�������Ͷ��ɡ�\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("no_get","�������ڵ����ܴ��ֶ��ã�\n");
  set("no_give","�������ڵ������⴫Ҳ��\n");
  set("no_drop","�������ڵ�������ʧҲ��\n");
  set("no_sell","�������ڵ��޼�֮��Ҳ��\n");
  set("is_monitored",1);
  setup();
}

void init()
{
  add_action("do_eat", "eat");
  call_out("destruct_me",3600);
}

int do_eat(string arg)
{
  object dan = this_object();
  object me = this_player();

  if (present(arg,me) != dan)
    return 0;
    
  me->set("eff_jing", (int)me->query("max_jing"));
  me->set("jing", (int)me->query("max_jing"));
  me->set("eff_jing", (int)me->query("max_jing"));
  me->set("jing", (int)me->query("max_jing"));
  me->set("eff_qi", (int)me->query("max_qi"));
  me->set("qi", (int)me->query("max_qi"));
  me->set("neili", (int)me->query("max_neili"));
  me->set("neili", (int)me->query("max_neili"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(HIG "$N���������ڵ������������£�һ�������Ե��ﻺ���鲼ȫ���ˣ�\n" NOR, me);
  me->start_busy(5);
  destruct(dan);
  return 1;
}

void destruct_me ()
{
  message_vision("�������ڵ���ɷ�ĩ�ڷ��д�ɢ�ˣ�\n", this_object());
  destruct (this_object());
}

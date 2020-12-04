// by snowcat 6/1/1997
// xiantao.c ����

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(YEL "����" NOR, ({"xian tao", "tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�����ϲ�������罺˵����ҡ�\n");
    set("value",0);
    set("drug_type", "��Ʒ");
  }

  setup();
}

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"����ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }            
  add_action("do_eat", "eat");
}


int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

  me->set("food", (int)me->max_food_capacity());
  switch (random(3))
  {
    case 0:
    {
      message_vision(HIG "$N����һ�����ң���Ȼ�������\n" NOR, me);
      me->set("eff_gin", me->query("max_gin"));
      me->set("gin",     me->query("max_gin"));
      me->set("neili",   me->query("max_neili"));
      me->set("mana",    me->query("max_mana"));
      break;
    }
    case 1:
    {
      message_vision(HIG "$N����һ�����ң���Ȼ��ɫ�Ƿ���\n" NOR, me);
      me->set("eff_qi", me->query("max_qi"));
      me->set("qi",     me->query("max_qi"));
      me->set("neili",   me->query("max_neili"));
      me->set("mana",    me->query("max_mana"));
      break;
    }
    case 2:
    {
      message_vision(HIG "$N����һ�����ң���Ȼ������ȣ�\n" NOR, me);
      me->set("eff_jing", me->query("max_jing"));
      me->set("jing",     me->query("max_jing"));
      me->set("neili",   me->query("max_neili"));
      me->set("mana",    me->query("max_mana"));
      break;
    }
  }
  destruct(this_object());
  return 1;
}

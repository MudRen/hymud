// sheyao.c

inherit COMBINED_ITEM;

void create()
{
  set_name("��ҩ",({"sheyao", "drug","snake drug"}));
  set("long",
      "����һ���������߶���ҩ\n"
      "������(yong/cure)�����߶�!\n");
  set("value",1000);
  set("unit","��");
  set("base_unit","��");
  set("base_weiht",100);
  set_amount(1);
}

void init()
{
  add_action("do_cure",({"yong", "cure"}));
}

int do_cure()
{
        object me;

        me=this_player();
  if(((int) (me->query_condition("snake_poison"))) <= 0)
        return notify_fail("��û�����߶���\n");
  message_vision("$N������ҩ����ʱ�о��ö��ˡ�",me);
        me->apply_condition("snake_poison",
                (int)me->query_condition("snake_poison") - 1);
  if((int) (me->query_condition("snake_poison")))
        message_vision("����$N�е��߶���û����ȫ�����\n",me);
        else
        message_vision("$N����������������е��߶���\n",me);
  add_amount(-1);

  return 1;
}
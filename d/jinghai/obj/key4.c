inherit ITEM;

void create()
{
      set_name("����Կ��", ({"di key", "key"}));
      set_weight(100);
      if (clonep())
      set_default_object(__FILE__);
      else {
      set("unit", "��");
      set("long", "ͭ�Ƶ�Կ�ף��������Կ���������դ���š�\n");
      }
      setup();
}


inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("���", ({"penghu", "peng hu", "hu"}));
  set_weight(5000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "һ����������ľ��ˮ�ĺ���\n");
     set("unit", "��");
     set("value", 2000);
     set("max_liquid", 15);
     set("mask","ׯ");
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "����ˮ",
        "remaining": 15,
        "drunk_supply": 12,
      ]));
}


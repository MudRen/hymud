// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "��ͷ��",
  "������",
  "���",
  "����",
  "��β",
  "����",
  "���",
  "�����",
});

void create()
{
 set_name(names[random(sizeof(names))], ({"zhu rou","rou","zhurou"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��Ѫ���ܵ��⡣\n");
    set("unit", "��");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 85);
  }
}

void init()
{
  if (query("name")=="��ʽ����")
    set_name(names[random(sizeof(names))], ({"mian tiao","miantiao","mian"}));
  ::init();
}

inherit ITEM;
int do_apply (string arg);
void create()
{
  set_name("������", ({"jinlong fu", "jinglong", "fu"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_sell", 1);
    set("no_drop", 1);
    set("unit", "��");
  
  set("long", "һ�Ż�ɫ��ֽ�������滭��β��������Ľ�����
�������Ի�(apply)���\n");
    }
    setup();
}

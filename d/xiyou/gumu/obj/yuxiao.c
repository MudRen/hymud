// created 4/5/1997 by snowcat


inherit ITEM;
inherit F_UNIQUE;
void init();

void create()
{
  set_name("�������" , ({ "yu xiao"})); 
  set_weight(1000);
        set("unique", 1);
  set("long","����һ֧����������������������������ࡣ\n���˰�������,����Դ���(blow)��\n");
  set("unit", "��");
  setup();
}

 // bat_drug.c
#include <weapon.h> 
inherit THROWING; 
void create()
{
        set_name("��ҩ", ({ "bat drug", "drug" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
      set("long",
           "����һ�����������𶾵�ҩ\n"
            "������(cure)��������!\n");
                set("unit", "��");
                set("base_unit", "��");
                set("base_weight", 10);
                set("base_value", 10);
        }
        set_amount(1);
        ::init_throwing(1, 0);
} 
void init()
{
  if(this_player()==environment())
  add_action("do_cure","cure");
} 
int do_cure()
{
  object me;
  me = this_player();
 if  (((int) me->query_condition("bat_poison")) <= 0)
  return notify_fail("��û�������𶾡�\n");
  message_vision("$N���½�ҩ����ʱ�о��ö��ˡ�",me);
        me->apply_condition("bat_poison",
                (int)me->query_condition("bat_poison") - 1);
  if((int) (me->query_condition("bat_poison")))
      message_vision("����$N�е����𶾲�û����ȫ�����\n",me);
  else
        message_vision("$N����������������е����𶾣�\n",me);
  add_amount(-1); 
  return 1;
}    

// by snowcat 12/17/1997

#include <ansi.h>
#include <weapon.h>
 
inherit F_UNIQUE;
inherit ITEM;
void remove_npc(object victim);
 
void create()
{
      set_name("��������ƿ",({"yinyang erqi ping", "ping", "fabao"}));
  set_weight(5000);
  set_max_encumbrance(100000000000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","ֻ");
    set("value", 10);
    set("material","cloth");
      set("long","������������������������װ��ƿ�У�һʱ���̻�Ϊ��ˮ��\n");
  }
  set("no_fight", 1);
  set("no_magic", 1);
  set("unique", 1);
    set("no_sell", "��������ƿ�˷���û�˸���Ҳ��\n");
set("no_put",1);
    set("no_give", "��������ƿ�˷�����������Ҳ��\n");
    set("replace_file", "/d/xiyou/xueshan/obj/pingfake.c");
  set("is_monitored",1);
  setup();
} 


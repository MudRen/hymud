//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/obj/luzi.c

 
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
  set_name(YEL"��ͭ��¯"NOR, ({ "shou lu","luzi"}) );
  set_weight(500);
  set_max_encumbrance(20000);
 
  if( clonep() ){
    object ash;
    seteuid(getuid());
      set_default_object(__FILE__);
  } else {
    set("unit", "ֻ");
    set("long", "���Ǹ��ܱ��µ�¯�ӡ�\n");
    set("value", 2000);
    set("no_get",1);
  }
  init_hammer(1);
}

int is_container() { return 1; }

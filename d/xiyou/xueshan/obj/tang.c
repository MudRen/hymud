inherit ITEM;

#include <ansi.h>


int do_he(string);

void create() 
  {
   set_name(YEL "������" NOR,({"tang"}));
   set("long","һ�뻨�����̵�"+this_object()->query("name")+"������(he)ζ����\n");
   set_weight(50);
   set("unit","��");
   setup();
  }


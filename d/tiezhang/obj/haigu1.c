#include <ansi.h>

inherit ITEM;

void create()
{
       set_name("����", ({"haigu"}) );
       set_weight(10000);
       set_max_encumbrance(6000000);
       if( clonep() )
               set_default_object(__FILE__);
       else{
       set("unit", "��");
       set("long", "����һ�����ӵĺ��ǡ�\n");
       set("value", 0);
       set("material","wood");
       set("no_get",1);
       set("init",0);
       }
       setup();
}


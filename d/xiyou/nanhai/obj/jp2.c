//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// jingping.c ��ƿ 

inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
   set_name("��ƿ", ({"jingping", "bottle"}));
   set_weight(1000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "�Ϻ�����ʢˮ�ľ�ƿ��\n");
     set("unit", "��");
     set("value", 50);
     set("max_liquid", 500);
   }

   // because a container can contain different liquid
   // we set it to contain wine at the beginning
   set("liquid", ([
     "type": "water",
     "name": "ʥˮ",
     "remaining": 10,
     "drunk_apply": 20,
   ]));
}

 inherit ITEM;
#include <ansi.h>
void create()
{
  set_name(HIG"��֦һҶ��"NOR,({ "flower" }) );
  if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",1000);
                set("unit","��");
                set("long", "һ�俴��ȥʮ����ͨ��Ұ����ɢ�����������ζ��\n");
                }
}   

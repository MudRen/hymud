#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"����"NOR, ({ "jade" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("value", 2000);
            set("material", "jade");
            set("long", "��Ө��覵ı��񣬱���̫ƽ�������ϵģ���ֵ���ǡ�\n");
          } 
    
}       

 inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIM"����"NOR, ({ "huafen" , "����"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����ʤ���һ����ϵȻ���\n");
                set("value", 1000);
        }
        
}     

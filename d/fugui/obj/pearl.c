 inherit ITEM;
#include <ansi.h> 
void create()
{
        set_name(HIG"ҹ������"NOR, ({ "pearl"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "һֻ�ں�ҹ��Ҳ�����������ҹ���飬�����������ü�Ǯ��\n");
                set("value", 2000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("no_sell",1);
                set("thief_obj",1);
        }
        
}    

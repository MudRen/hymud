#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(HIG"�ټ�"NOR, ({ "chainarmor"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "vine");
                set("long", "һ��������֯�ɵĻ��ף�����ҩ���н��ݹ��������쳣��\n");
                set("value", 1000);
                set("armor_prop/armor", 60);
        }
        
} 

#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(HIY"�ƽ��"NOR, ({ "golden chainarmor","chainarmor"}) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "gold");
                set("long", "һ����������Ļƽ���ס�\n");
                set("value", 1000);
                set("armor_prop/armor", 80);
        }
        
}    

#include <ansi.h>
#include <armor.h>
inherit CLOTH; 
void create()
{
    set_name(HIR"����ȹ"NOR, ({ "red skirt", "skirt" }) );
    set_weight(1800);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("long", "һϮ��ȹ���������˼���ˮ����\n");
        set("unit", "Ϯ");
        set("value", 3000);
        set("material", "cloth");
        set("armor_prop/armor", 5);
        set("armor_prop/dodge", 10);
    }
    
}   

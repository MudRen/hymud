#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(YEL"����Ƥ"NOR, ({ "gatorskin"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "vine");
                set("long", "һ��ǧ�����Ƥ�������쳣��\n");
                set("value", 1000);
                set("armor_prop/armor", 80);
                set("armor_prop/dodge", -10);
                set("armor_prop/courage",5);
        }
        
}  

#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(BRED YEL"�ϻ�Ƥ" NOR, ({ "tiger cloth", "cloth" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ�Ű���ͻ���Ƥ��\n");
                set("value", 5000);
                set("material", "leather");
                set("armor_prop/armor", 18);
        }
        setup();
}

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIY "������" NOR, ({"long pao","cloth","longpao","pao"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long","����һ�������ޱȵ������ۡ��㲻�ɵ��봩���������ʵ�񫡣\n");
                set("value", 600);
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 15);
             }
	setup();
}

#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
    set_name(HIW"����ϻ��׽��"NOR, ({ "ring" }) );
    set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("material", "gold");
                        set("value", 2000);
            set("long", "һ������ϻ��׽��,����������ͣ�����ӡ��ʵΪ�����Ʒ\n");
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 6);
                set("wield_msg", "$N�ӻ�������һ��$n������ָ�ϡ�\n");
        set("unwield_msg", "$N�����ϵ�$nС������ز��뻳�С�\n");
        }
        
}      

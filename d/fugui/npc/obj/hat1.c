#include <armor.h>
#include <ansi.h>
inherit HEAD; 
void create()
{
        set_name(HIM"����Ƕ���Ͻ��"NOR, ({ "goldenhat"}) );
        set_weight(23);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����������Ƕ���Ͻ�ڡ�\n");
                set("unit", "��");
                set("value", 5000);
                set("armor_prop/armor", 30);
                set("armor_prop/personality", 5);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
                set("female_only", 1);
        }
        
}      

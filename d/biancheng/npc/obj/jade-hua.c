#include <armor.h>
inherit HEAD;
#include <ansi.h>
 
void create()
{
        set_name(HIG"�黨"NOR, ({ "jade flower"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�䱾Ӧ�����˴�ͷ���黨\n");
                set("unit", "��");
                set("value", 3000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 10);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n"); 
                set("female_only", 1); 
        }

}       

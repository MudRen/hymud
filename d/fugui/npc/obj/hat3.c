#include <armor.h>
#include <ansi.h>
inherit HEAD; 
void create()
{
        set_name(HIY"���������Ĩ��"NOR, ({ "doublepin"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������Ķ��������Ĩ��������ͣ����ŷ���\n");
                set("unit", "��");
                set("value", 5000);
                set("armor_prop/armor", 30);
                set("armor_prop/personality", 5);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unwield_msg", "$N����ذ�$n��ͷ�ϳ���������\n");
                set("female_only", 1);
        }
        
}     

#include <ansi.h>
#include <armor.h> 
inherit NECK; 
void create()
{
        set_name(GRN"�޼���������"NOR, ({"jade", "yu pei"}) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��Ǭ������״������������������˸����᡻�֡�\n");
                set("unit", "��");
                set("value", 10000);
                set("armor_prop/armor", 2);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n���������ϡ�\n");
                set("unwield_msg", "$N����ذ�$n�������ϳ���������\n");
        }
        
}   

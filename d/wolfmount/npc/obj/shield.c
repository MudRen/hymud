#include <armor.h>
#include <ansi.h> 
inherit SHIELD; 
void create() {
        set_name(WHT"�����"NOR, ({ "jade shield","shield" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "��");
                set("value", 5000);
                set("long", "һ��Բ�ܣ�ɫ����ͣ��ǽ���񣬻�֮��Ȼ���������Ǳ����಻���ˡ�\n");
                set("armor_prop/armor", 80);
                set("armor_prop/parry", 15);
                set("experience",5000000);
        }
setup();
}  
int query_autoload() { return 1; } 

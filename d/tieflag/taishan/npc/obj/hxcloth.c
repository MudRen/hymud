//by xiaolang
#include <armor.h> 
#include <ansi.h>
inherit CLOTH; 
void create()
{
        set_name(BLU"ϴ�ķ��׵���������"NOR, ({ "bluecloth", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 80);
        set("value", 3000);
        set("long", "һ����ͨ���������ѣ��Ѿ�ϴ�ķ����ˡ�\n");
        }
        setup();
}       

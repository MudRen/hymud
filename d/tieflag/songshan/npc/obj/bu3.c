 // TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("˿��", ({ "choubu" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("for_create_cloth",1);
                set("base_armor",6);
                set("armor_prop/armor", 16);
                set("long","һ��ѩ�׵�˿�񲼣���͸�������һ���ƮƮ�ġ�\n");
                set("max_enchant",5);
                set("value",5000);
        }
        setup();
}       

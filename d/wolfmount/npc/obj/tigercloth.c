#include <armor.h>
inherit CLOTH;
#include <ansi.h> 
void create()
{
    set_name(HIY"��Ƥ���"NOR, ({"tiger cloak", "cloak"}));
    set_weight(15000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long","һ���ɻ�Ƥ���ƵĴ�멣�����ȥ��ʵ�������ݡ�\n");
        set("material", "cloth");
        set("unit", "��");
        set("value", 1000);
        set("armor_prop/armor", 60);
        set("male_only", 1);
        set("armor_prop/personality", 1);
    }
    
}     

//maozhan.c.ëձ
//date:1997.8.27
//by dan      

#include <armor.h> 
#include <ansi.h>
inherit CLOTH;      

void create()
{
    set_name(MAG"ëձ"NOR, ({ "mao zhan", "zhan" }) );
    set("long","����һ����ϸ��ë֯�ɵ�ëձ��\n");
    set_weight(5000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("material", "cloth");
        set("value",2000);
        set("armor_prop/armor", 5);
    }
    setup();
}


//baizhan.c.��ձ
//date:1997.8.27
//by dan  

#include <armor.h> 
#include <ansi.h>
inherit CLOTH; 

void create()
{
    set_name(YEL"��ձ"NOR, ({ "bai zhan", "zhan" }) );
    set("long","����һ���ô��׵�ϸ��ë֯�ɵİ�ëձ��\n");
    set_weight(3000);     
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("material", "cloth");
        set("value",5000);
        set("armor_prop/armor",15);
    }
    setup();
}


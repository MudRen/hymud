#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("����", ({ "cloth"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "vine");
                set("long", "һ��˿���Ļ����Ľ�����\n");
                set("value", 1000);
                set("armor_prop/armor", 20);
        }
        
} 

 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�߲�˿�д�", ({ "silk" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�����߲�˿�д���������������ֹ�ã��һ�����ǲ���֮Ʒ��\n");
                set("material", "cloth");
                set("realsilk",1);
                set("value", 1000);
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 5);
                set("armor_prop/spirituality",3);
        }
        
}

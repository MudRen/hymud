 // sword_long.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <weapon.h>
inherit SWORD; 
void create() {
        set_name("�ǽ�", ({ "bone sword" }) );
        set_weight(7000);
		set("maze_item",1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѳ�֪��ʲô��ͷ��ɵĽ���\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N�ó�һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������\n");
        }
        ::init_sword(25);
}     

 // dagger.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <weapon.h>
#include <ansi.h>
inherit DAGGER; 
void create() {
        set_name(HIY"�����"NOR, ({ "dagger" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���Ժ����ϵ���ɷ���ʮ�ߵĽ�ɫ�̽���\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N�Ӵ��������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        ::init_dagger(55);
}   

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        int pro;
        dam = (int) me->query_skill("dodge");
        victim->receive_damage("jing",dam/2);
        return HIY "$N����"+name()+HIY"�������裬$n"+HIY"����������������\n" NOR;
}  

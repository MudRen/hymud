//jian4.c.̫����
//date:1997.8.27
//by dan 

#include <weapon.h> 
#include <ansi.h>
inherit SWORD;   

void create()
{
        set_name(HIG"̫����"NOR, ({ "tai a jian", "jian" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"��ѽ�ͨ���峺͸����΢΢͸�����⣬��һ���Ϲ����С�\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", 
"ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        init_sword(58);
        setup();
}
 


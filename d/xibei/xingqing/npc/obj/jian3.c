// xuanquan.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��Ȫ��", ({ "xuanquan jian", "xuanquan", "jian" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"��ѽ�ͨ���峺͸����΢΢͸�����⣬��˵��������ʦ��\n"
                        
"�ĵ���֮����ÿ����Բ֮ҹ����Է���Х��\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", 
"ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }
        init_sword(58);
        setup();
}
 


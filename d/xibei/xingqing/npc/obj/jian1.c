#include <weapon.h>
//  standard sword.c(��͵�) edit by lin on March 3,  97
#include <ansi.h>
inherit SWORD;
//inherit F_SAVE;
//inherit F_AUTOLOAD;
void create()
{
        set_name("����", ({ "sword"}) );
        set_weight(1500);
        set("long","һ������ͨͨ���������������濪�У���ʵ����.\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 800);
                set("material", "iron");
        }
        init_sword(10);
        set("wield_msg", "$N���һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        setup();
}


// blade.c

#include <weapon.h>
inherit F_UNIQUE;

inherit WHIP;

void create()
{
        set_name("������", ({"fulong whip", "whip"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","һ����Լ���ߣ����������ɵĳ��ޣ����ǵز��������ı�������η��ǹ֮����ˮ���֣�\n");
                set("unit", "��");
                set("value", 1200);
		set("wield_msg", "ֻ����ž����һ���죬$N����������һ�����ɫ�ĳ��ޣ�\n");
		set("unwield_msg", "$N������$n�������䣮\n");
		set("weapon_prop/courage", 5);
        }
        init_whip(380);
        set("is_monitored",1);
        setup();
}


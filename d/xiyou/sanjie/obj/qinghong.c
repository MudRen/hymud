// qinghong.c ��罣

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��罣", ({"qinghong sword", "sword", "jian",
"qinghong"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��������ħ�ı�����\n");
                set("unit", "��");
		set("wield_msg",
"$n��ৡ��شӽ����е���������$N�����У����⻹أ��������ͣ��\n");
		set("unwield_msg",
"$N�����е�$n�������䣬��ɫ���������ˣ�\n");
                set("value", 100);
		set("weapon_prop/courage", 10);
        }
        init_sword(570);
        setup();
}

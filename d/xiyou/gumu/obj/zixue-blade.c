//��Ѫ��
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;
inherit F_UNIQUE;

inherit BLADE;
#include <ansi.h>
void create()
{
        set_name(MAG"��Ѫ��"NOR, ({"zixue kuangdao", "dao","blade"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ��ͨ����ɫ�ı�����\n");
                set("unit", "��");
                 set("unique", 1);
                set("value", 120);
                set("wield_msg", "$N��������һ����������������һ��������\n");
                set("unwield_msg", "$N���еı�������һ��������ʧ�ˡ�\n");
                set("weapon_prop/courage", 20);
                }
        init_blade(820);
        setup();
}


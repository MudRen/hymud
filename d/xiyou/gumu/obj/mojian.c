//����ħ��
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit F_UNIQUE;
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIG"����ħ��"NOR, ({"qingyu mojian", "sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ��ɢ������ɫ�����ı�����\n");
                set("unit", "��");
                set("value", 120);
               set("unique", 1);
                set("wield_msg", "$N���־���һ����ɫ����������������һ��������\n");
                set("unwield_msg", "$N���е���������һ����ɫ������ʧ�ˡ�\n");
                set("weapon_prop/courage", 20);
                }
        init_sword(820); // so high...mudring
        setup();
}


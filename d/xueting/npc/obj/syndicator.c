// woodsword.c
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("�����", ({ "syndicator" }));
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                
                set("long",
                        "����һ�ѳ�Լ�Ĵ��ذ�ף������þ�ϸ�ĵ��οճ�һ����ò\n"
                        "Ů�ӵ��������ص�����Ů�ӵı������������ͷ������ߵ�Ѫ\n"
                        "����ذ�׵ı���̣�ֻ������ֻ��ָ��ס��\n");
                set("unit", "��");
                set("value", 600);
                set("material", "steel");
                set("wield_msg", "$N��ˢ����һ���ӻ����ͳ�һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n���뻳�\n");
                set("weapon_prop/intelligence", 3);
        }
        init_dagger(35);
        setup();
}

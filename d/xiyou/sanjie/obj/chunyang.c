//���쳯����
//by junhyun@SK

#include <weapon.h>
//  inherit F_UNIQUE;

inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIR"���촿����"NOR, ({"chunyang jian", "sword","jian"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ��մ�������Ѫ�������ı�����ɢ����������η�ĺ�а֮�⣡\n");
                set("unit", "��");
                set("value", 1200);
                set("wield_msg",HIW "$N����һ�Σ������Ѷ���һ�����촿������\n"NOR);
                set("unwield_msg", "$N�������еĻ��쳯������\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_sword(720);
        setup();
}


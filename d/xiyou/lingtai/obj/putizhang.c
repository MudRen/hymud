#include <weapon.h>
inherit STAFF;
#include <ansi.h>

void create()
{
        set_name(HIG"������"NOR, ({"puti zhang","stick","bang"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("long","һ�ѵ���ɫ����������ֻ��壬����Щ������\n");
                set("unit", "��");
                set("value", 120);
                set("wield_msg",HIW "$N��ľ��������Ȼ����ӱ�������\n"NOR);
                set("unwield_msg",HIW "$N��ھ�,�����Ȼ�Ϊһ������,��������ʧ��!\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 
                set("weapon_prop/courage", 20);
        }
        init_staff(820);
        setup();
}


//������
//by wuyou

#include <weapon.h>
//  inherit F_UNIQUE;

inherit STAFF;
#include <ansi.h>
void create()
{
        set_name(HIB"������"NOR, ({"wind fork","fork","cha"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","�̲�����,����ɪɪ,���˿�ȥ���������ޱߵĴ�,�ƺ������������Ŷ��������ܣ�\n");
                set("unit", "��");
                set("value", 120);
                set("wield_msg",HIW "$N����һ������,һ������ɫ�ķɲ�������,�������У�\n"NOR);
                set("unwield_msg",HIW "$N����һ˦,���еķ����桰ಡ���һ�����ֶ���,�������...\n");
                set("no_sell","�����������ɣ��ⶫ���㶼������\n"); 
                set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n"); 

                set("weapon_prop/courage", 20);
                }
        init_staff(820);
        setup();
}

#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("���Ǵ�", ({ "flying hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������˨�ŵ�����\n");
                set("value", 400);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n��������������Ȼ���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        } 
        init_hammer(65);
}     

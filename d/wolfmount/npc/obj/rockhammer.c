 // hammer.c
#include <weapon.h> 
inherit HAMMER; 
void create()
{
    set_name("���˴�", ({ "war hammer","hammer" }) );
    set_weight(150000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ����Լһ�ٰ�ʮ��ľ޴���\n");
        set("value", 100);
        set("material", "iron");
        set("wield_msg", "$N�������ף�ŭ���л�Ȼ���һ��$n�����˵�������������С�\n");
        set("unwield_msg", "$N�������е�$n��\n");
    }
    
    ::init_hammer(160);
}  

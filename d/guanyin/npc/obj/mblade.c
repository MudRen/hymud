#include <weapon.h>
inherit BLADE; 
void create()
{
        set_name("��ȱ���º� ", ({ "destblade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������һ��ȱ�ڵ�������\n");
                set("value", 5000);
                set("rigidity", 2000);
                set("material", "steel");
        }
        init_blade(330);
}      

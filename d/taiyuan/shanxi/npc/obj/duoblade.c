#include <weapon.h>
#include <ansi.h>
inherit BLADE; 
void create()
{
        set_name(HIG"�䵶"NOR, ({ "duoblade" ,"blade"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���̵ĵ�������Ƕ�����μ�ֵ���ǵ����顣");
                set("value", 20000);
                set("material", "steel"); 
        set("wield_msg", "$N��������һ�ѱ��̵�$n�������С�\n");
        set("unwield_msg", "$N�����е�$n�������䡣\n");
        }
        ::init_blade(510);
}   

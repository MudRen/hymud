 // staff.c : Gun zi
#include <weapon.h>
#include <ansi.h>
inherit STAFF; 
void create()
{
        set_name("׽�����⹳", ({ "zhuo hun gou" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѽ����������⹳�������ƺ������Ż��أ�\n");
                set("value", 3000);
                set("material", "steel");
        }
        ::init_staff(50, TWO_HANDED);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->apply_condition("snake_poison",random(10)+10); 
        return HIR "$n�ƺ�Ⱦ����׽�����⹳�ϵĶ���\n"NOR;
}       

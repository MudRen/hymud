 // hammer.c
#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name("��ľ��", ({ "muqin" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������ɫ���㣬�����ڰ������������١�\n");
                set("value", 3);
                set("material", "iron");
        } 
        ::init_hammer(16);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dam;
        dam = (int) me->query("max_jing");
        victim->receive_damage("jing",dam/20);
        return MAG"��ľ����$N�������ߣ����Ҳ�ͣ�𶯵�������$nͷ�����ǣ�\n" NOR;
}   
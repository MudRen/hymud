 //TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIC"Բ���䵶"NOR, ({ "moonblade" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����״�����صĵ�������·��е�������\n");
                set("value", 400);
                set("material", "steel");
                set("wield_msg", "$N��$nͻȻ���ʣ��������û�п���$N�ε���\n");
                set("unwield_msg", "$N��$n�����ʡ�\n");
                set("for_modao",1);
        }
        ::init_blade(25);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint = 0;
		int bonus;
        if(random(damage_bonus) < 250 ) return 0;
		bonus = (int)me->query("combat_exp")/5000000;
		if(bonus < 1) bonus = 1;
        badint = me->query_skill("blade");
//      if(badint && !victim->query_temp("weapon")) 
//      && victim->query_skill_mapped("unarmed") == "dragonstrike")
//      message_vision( HIR "$N�˵���һ�����е�"+name()+ HIR "ͻȻ����$n��������\n"NOR,me,victim);
//        return badint;
        victim->receive_wound("qi",badint*bonus,me);
        return RED "$N�˵���һ�����е�"+name()+NOR RED "ͻȻ����$n"+NOR RED"��������\n"NOR; 
}  

 // sword.c
#include <ansi.h> 
#include <weapon.h> 
inherit SWORD; 
void create()
{
        set_name("跽�����", ({ "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        
"����һ����ľ��ɵĹŽ�����������һ����ζ���������������δ��������\n"
                        "�ģ�ֻ�н���������������ϡ���Ա��ϵ�׭�֣��� �� �� 
��\n");
                set("value", 18000);
                set("material", "wood");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
                set("weapon_prop/spirituality", 3);
                set("for_taoist",1);
        } 
        ::init_sword(155);
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage; 
        if( victim->is_ghost() ) {
                if( random(me->query("max_jing")) > 
(int)victim->query("jing")/2 ) {
                        damage = me->query_str();
                        victim->receive_wound("jing", damage);
                        me->receive_heal("jing", damage);
                        me->receive_heal("qi", damage);
                        me->receive_heal("jing", damage);
                        return HIY 
"���򽣷���һ�ɽ�ɫ�����������$N��ȫ��\n"NOR;
                }
                return random(me->query_str());
        }
}
       

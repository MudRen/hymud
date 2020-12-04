#include <ansi.h>
inherit BOSS;
void create()
{
        string *names = ({"��ë����","��ë����","��ë����"}); 
        set_name( names[random(sizeof(names))], ({ "wolf"}));
        set("vendetta_mark","wolf");
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 20);
        set("long", "����һֻ���̵Ķ��ǡ�\n");
      
        set("str", 40);
        set("cor", 100);
        set("cps", 22); 
        set("max_qi", 20000);
        set("max_jing", 25000);
        set("max_neili", 25000);
        set("attitude", "peaceful");
        set("chat_chance", 2);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("combat_exp", 1000000);
        set("bellicosity", 5 );
          set("bonus", random(100)+100);
        set_temp("apply/attack", 500);
        set_temp("apply/dodge", 400);
        set_temp("apply/parry", 400);
        set_temp("apply/unarmed_damage", 40);
        setup();
        carry_object(__DIR__"obj/wolf_skin");
} 
void init()
{
        object me, ob;

        ::init();
        if (! interactive(me = this_player()))
                return;
        
        if( !me->is_character() || me==this_object() || !me) return;
        if(me->query("vendetta/authority")) return;
        if(!userp(me)) return;
        
        remove_call_out("kill_ob");
        call_out("kill_ob", 0, me);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        victim->receive_damage("qi",300+random(300));
        victim->receive_wound("qi",200+random(200));
        message_combatd(HIW"\n$N"+HIW"������צ����$n"+HIW"��������һ��Ѫ���ܵ��˿ڣ�"NOR,me,victim);
        return;
}      

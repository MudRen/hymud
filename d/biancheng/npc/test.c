 // waiter.c
inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("����Ʒ", ({ "afa" }) );
        set("title", "С³��");
        set("gender", "����" );
        set("age", 35);
        set("long",
                "����ܰ����㿴���尢��������\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",5);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_fire");
        dam = (int) me->query("force");
        victim->receive_wound("qi",150);
        return HIR "���泤�����һ���ɺ�Ļ��棬�ǿ���$n��ȫ��\n" NOR;
}      

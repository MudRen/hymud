#include <ansi.h>

inherit "/p/migong/necropolis/necropolis_npc";
void do_bite();
void create()
{
        string *names = ({"Ѫ��ʬ"}); 
        // set_name( names[random(sizeof(names))], ({ "blood zombie","zombie"}));
        set_name( names[random(sizeof(names))], ({ "blood zombie" }));
        set("vendetta_mark","zombie");
        set("long", "����һ�����õĽ�ʬ��\n");
        set("title", HIB "(����)" NOR); 

        set("str", 50);
        set("con", 120);
        set("dex", 22); 
        set("int", 50);
        set("max_qi", 40000);
        set("max_jing", 45000);
        set("neili", 250000);
        set("max_neili", 250000);
        set("max_jingli", 50000);
        set("attitude", "peaceful");
        //set("shen_type", -1);      
        //set("chat_chance", 2);
        //set("chat_msg", ({
        //                "���ÿն����ۿ�����˸�ſ��µ�ӫ�⡣\n"
        //}) ); 

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (: do_bite() :),
        }) ); 

        set("combat_exp", 150000000);
        set("bellicosity", 5 );
        set("death_msg",RED"\n$N������һ̲Ѫˮ��\n\n"NOR);

        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        set_skill("parry", 60);        
        set_temp("apply/attack", 1500);
        set_temp("apply/parry", 500);
        set_temp("apply/unarmed_damage", 600);

        setup();
        //carry_object(__DIR__"obj/bone_finger");
} 

int is_undead() {
	return 1;
}

/*
int is_zombie() {
	return 1;
}
*/

void do_bite() {
	object *enemies,enemy;
	string msg;

	enemies = query_enemy();

	if(!enemies || sizeof(enemies)==0)
		return;
	if(!enemies || sizeof(enemies)==0)
		return;
	enemy = enemies[random(sizeof(enemies))];
	message_vision(RED"$N¶��ɭɭ�İ���������$n��"NOR,this_object(),enemy);

        message_vision(HIR"$Nҧס$n��������Ѫ��\n"NOR,this_object(),enemy);
        enemy->receive_damage("qi",1000+random(1000),this_object());
        this_object()->receive_heal("qi",1000+random(1000));
        this_object()->receive_curing("qi",500+random(500));
        if (! enemy->is_busy())
                enemy->start_busy(1);

	if (! this_object()->is_busy())
	        this_object()->start_busy(2);
}

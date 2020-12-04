#include <ansi.h>

inherit "/p/migong/necropolis/necropolis_npc";
void do_swing();
void create()
{
        string *names = ({"ʬɷ"}); 
        // set_name( names[random(sizeof(names))], ({ "power zombie","zombie"}));
        set_name( names[random(sizeof(names))], ({ "power zombie" }));
        set("vendetta_mark","zombie");
        set("long", "����һ�����õĽ�ʬ��\n");
        set("title", HIB "(����)" NOR); 

        set("str", 50);
        set("con", 120);
        set("dex", 50); 
        set("int", 50);
        set("max_qi", 80000);
        set("max_jing", 85000);
        set("neili", 350000);
        set("max_neili", 350000);
        set("max_jingli", 80000);
        set("attitude", "peaceful");
        //set("chat_chance", 2);
        //set("chat_msg", ({
        //                "���ÿն����ۿ�����˸�ſ��µ�ӫ�⡣\n"
        //}) ); 

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (: do_swing() :),
        }) ); 

        set("combat_exp", 150000000);
        set("bellicosity", 5 );
        set("death_msg",RED"\n$N������һ̲Ѫˮ��\n\n"NOR);

        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("parry", 120);    
        set_temp("apply/attack", 1500);
        set_temp("apply/parry", 1500);
        set_temp("apply/unarmed_damage", 1600);

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



void do_swing() {
	object *enemies,enemy;
	string msg;

	enemies = query_enemy();

	if(!enemies || sizeof(enemies)==0)
		return;

	msg = RED"$Nһ�����У����������ת����������\n"NOR;	
        message_vision(msg,this_object());
	add_temp("apply/damage",400);
	add_temp("apply/attack",400);
	foreach(enemy in enemies) {
		if(!enemy)
			return;
		msg = RED"һ��צӰϮ��$n��"NOR;
		message_vision(msg,this_object(), enemy);
		COMBAT_D->do_attack(this_object(),enemy); 
	}
	add_temp("apply/damage",-400);
	add_temp("apply/attack",-400);
        
        if (this_object()->is_busy())
	        this_object()->start_busy(2);
}

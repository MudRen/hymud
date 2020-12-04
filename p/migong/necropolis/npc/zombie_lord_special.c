#include <ansi.h>

inherit "/p/migong/necropolis/necropolis_npc";
void do_summon();
void create()
{
        string *names = ({"��ʬ��"}); 
        // set_name( names[random(sizeof(names))], ({ "lord zombie","zombie"}));
        set_name( names[random(sizeof(names))], ({ "lord zombie" }));
        set("vendetta_mark","zombie");
        set("long", "����һ�����õĽ�ʬ��\n");
        set("title", HIB "(����)" NOR); 

        set("str", 50);
        set("con", 120);
        set("dex", 50); 
        set("int", 50);
        set("max_qi", 250000);
        set("max_jing", 260000);
        set("neili", 550000);
        set("max_neili", 550000);
        set("max_jingli", 80000);
        set("attitude", "peaceful");
        set("chat_chance", 1);
        //set("chat_chance", 2);
        //set("chat_msg", ({
        //                "���ÿն����ۿ�����˸�ſ��µ�ӫ�⡣\n"
        //}) ); 

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: do_summon() :),
        }) ); 

        set("combat_exp", 300000000);
        set("bellicosity", 1000000 );
        set("death_msg",RED"\n$N������һ̲Ѫˮ��\n\n"NOR);

        set_skill("force", 220);
        set_skill("dodge", 220);
        set_skill("unarmed", 2120);
        set_skill("parry", 220);     
        set_temp("apply/attack", 1500);
        set_temp("apply/parry", 1500);
        set_temp("apply/unarmed_damage", 1800);

        setup();
        carry_object(__DIR__"obj/zombie_blood");
} 

int is_undead() {
	return 1;
}

/*
int is_zombie() {
	return 1;
}
*/



void do_summon() {
	object zombie,me,enemy,enemies;
	me = this_object();
	
	message_vision(HIM "\n$N�����ɺ�����Χ�Ľ�ʬӦ��������\n" NOR, me); 
	seteuid(getuid());   
	if(random(2))
		zombie = new(__DIR__"zombie_blood");
	else
		zombie = new(__DIR__"zombie_power");
	zombie->move(environment(me));
	enemies = me->query_enemy();
	foreach(enemy in enemies) {
			zombie->kill_ob(enemy);
			enemy->kill_ob(zombie);
	} 
  message_vision( "\n\n$N��ݺݵ�����������\n" , zombie);
        call_out("leave",10+random(10),zombie);
  start_busy(3);
}

void leave(object zombie){
        if (! zombie) return;
                message_vision("\n$N��ʧ�ˡ�\n",zombie);
		destruct(zombie);
}

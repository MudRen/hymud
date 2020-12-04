#include <ansi.h>

inherit "/p/migong/necropolis/necropolis_npc";
void do_transfer();
void create()
{
        string *names = ({"��ڤħ"}); 
        // set_name( names[random(sizeof(names))], ({ "ghost devil","ghost"}));
        set_name( names[random(sizeof(names))], ({ "ghost devil"}));
        set("vendetta_mark","ghost");
        set("long", "���Ǹ��������ֵ����顣\n");
        set("title", HIB "(����)" NOR); 

        set("str", 50);
        set("con", 120);
        set("dex", 22); 
        set("int", 50);
        set("max_qi", 80000);
        set("max_jing", 85000);
        set("neili", 450000);
        set("max_neili", 450000);
        set("max_jingli", 50000);
        set("attitude", "peaceful");
        //set("shen_type", -1);        
        //set("chat_chance", 2);
        //set("chat_msg", ({
        //               "���ÿն����ۿ�����˸�ſ��µ�ӫ�⡣\n"
        //}) ); 
        set("death_msg",BLU"\n$N��ʧ�����ˡ�\n\n"NOR);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	        (: do_transfer() :),
        }) ); 

        set("combat_exp", 200000000);
        set("bellicosity", 1000000 );

        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("parry", 120);                
        set_temp("apply/attack", 1000);
        set_temp("apply/parry", 500);
        set_temp("apply/unarmed_damage", 500);
        setup();
        carry_object(__DIR__"obj/ghost_fire");
} 

int is_undead() {
	return 1;
}

//int is_ghost() {
//	return 1;
//}


void do_transfer() {
	object *enemies,enemy,env;
	mixed yourexp,myexp,no_busy;
	mapping exits;
	string *keys,direction;
	enemies = query_enemy();

	if(!enemies || sizeof(enemies)==0)
		return;
	
	message_vision(HIM"\n$N�·�������ĵ������������...����...ڤ�����ٻ���... \n"NOR, this_object(),enemy); 
	myexp = query("combat_exp",1);
	foreach(enemy in enemies)  {
		if(!enemy)
			continue;
		yourexp = enemy->query("combat_exp",1);
		if( random(atoi(myexp,2))>yourexp)  {
						message_vision(HIM"\n$n��ǿ����������ƣ����ɼ�����$N��ȥ...... \n"NOR, this_object(),enemy); 
			enemy->receive_damage("jing",enemy->query("max_jing")/4,this_object());
			if(!enemy->is_busy())
			        enemy->start_busy(random(4));
			COMBAT_D->report_status(enemy);
		} else {
			message_vision(HIG"\n$n�־�ĺ������ⲻ����ģ� \n"NOR, this_object(),enemy); 
			message_vision(HIG"\n$n�ŵ�Ťͷ����! \n\n"NOR, this_object(),enemy); 
			env = environment(enemy);
			if(env) {
				exits = env->query("exits");
				if(exits) {
					keys = keys(exits);
					direction = keys[random(sizeof(keys))];
					enemy->move(exits[direction]);
				}
			}
			if(!enemy->is_busy())
			        enemy->start_busy(1);
			//("/cmds/std/go")->do_flee(enemy);
		}
	}
	if (! this_object()->is_busy())
	        this_object()->start_busy(2);	

}

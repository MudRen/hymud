#include <ansi.h>

inherit "/p/migong/necropolis/necropolis_npc";
void do_eye();
void create()
{
        string *names = ({"��ڤ֮��"}); 
        // set_name( names[random(sizeof(names))], ({ "ghost eye","ghost"}));
        set_name( names[random(sizeof(names))], ({ "ghost eye" }));
        set("vendetta_mark","ghost");
        set("long", "���Ǹ��������ֵ����顣\n");
        set("title", HIB "(����)" NOR); 

        set("str", 50);
        set("con", 120);
        set("dex", 50); 
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
                (: do_eye() :),
        }) ); 

        set("combat_exp", 150000000);
        set("bellicosity", 5 );
        
        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("parry", 120);                
        set_temp("apply/attack", 1000);
        set_temp("apply/parry", 500);
        set_temp("apply/unarmed_damage", 500);
        setup();
        //carry_object(__DIR__"obj/bone_finger");
} 

int is_undead() {
	return 1;
}

//int is_ghost() {
//	return 1;
//}


void do_eye() {
	object *enemies,enemy;
	mixed yourexp,myexp;
	enemies = query_enemy();

	if(!enemies || sizeof(enemies)==0)
		return;
	enemy = enemies[random(sizeof(enemies))];
	
	message_vision(HIR"\n$N���ֳ���$n��Ӱ�ӣ�$n���ɵ��������Լ���Ӱ��...... \n"NOR, this_object(),enemy); 
	
	myexp = query("combat_exp",1);
		yourexp = enemy->query("combat_exp",1);
		if( random(atoi(myexp,2))>yourexp)  {
	        message_vision(HIR"\nӰ��ͻȻ�ķ����ѣ�$N�����Լ������Ҳ�����ˣ� \n"NOR, enemy); 
		enemy->receive_damage("jing",enemy->query("jing")/2,this_object());
		COMBAT_D->report_status(enemy);
	} else 
                message_vision(HIC"\n����$NѸ���ջ���Ŀ�⣡ \n"NOR, enemy); 
	
	if (!this_object()->is_busy())
	        this_object()->start_busy(2);
}

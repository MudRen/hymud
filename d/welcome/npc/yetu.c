// yetu.c 野兔

inherit NPC;

void create()
{
	set_name("野兔", ({ "ye tu", "ye", "hare" }) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只好可爱的小野兔。\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1500);
	set("qi",300);
	set("eff_qi",300);
	set("max_qi",300);
//	set("shen_type", 0);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}

//v/oid die()
//{
//	object ob;
//	message_vision("$N凄惨的嚎了几声，死了。\n", this_object());
//	ob = new(__DIR__"turou");
//	ob->move(environment(this_object()));
//	destruct(this_object());
//}
	
void die()
{
int i,pot,exp;
	object killer;
	exp= random(12)+8;
	pot= exp*2/3;

	if(objectp(killer = query_temp("last_damage_from")))
if (killer)
{
if (killer->query_temp("usefx"))
killer->set_temp("nbjob8",1);
}
	::die();

return ;
}
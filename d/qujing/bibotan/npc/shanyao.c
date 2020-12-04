inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
        set_name("山妖", ({"shan yao", "yao"}));
        set("long", "一个凶神恶煞般的山妖。\n");
        set("age", 30);
        set("attitude", "herosim");
        set("gender", "男性");
	set("class", "yaomo");
        set("str", 30);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",800);
        set("max_jing", 800);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 15);
        set("combat_exp", 50000);
  set("combat_exp", 50000);


	set("eff_dx", -20000);
        set("nkgain", 200);

        set("neili", 200);
        set("max_neili", 200);
        set("neili",100);
        set("max_neili", 100);

	map_skill("parry", "wuhu-blade");
        setup();
 	initlvl((500+random(500)),52);
        carry_object("/d/obj/armor/shoupi")->wear();
	carry_object("/d/obj/weapon/blade/kandao")->wield();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 40, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
	
	command("look " + ob->query("id") );
	command("say 又白又胖，刚好让老子下酒！");
	command("chan " + ob->query("id") );
	kill_ob(ob);
	ob->fight_ob(this_object());

	return;
}

�
 inherit NPC;
void create()
{
        
        set_name("���", ({ "huofe", "huo","fe" }) );
        set("gender", "����" );
        set("age", 109);
        set("int", 30);
        set("long",
                "�����𣬵���ԭ�����Σ�\n"
                );
        set("class","lama");
        set("combat_exp", 1000000);
        set("score", 90000);
        set("reward_npc", 1);
        set("difficulty", 5);
           set("max_neili", 3500);
        set("neili", 3500);
        set("force_factor", 30);
	set("max_qi",2999);
        set("max_jing",2999);
	set("eff_qi",2999);
	set("qi",2999);
	set("eff_jing",2999);
	set("jing",2999);
       set_skill("unarmed", 50);
	set_skill("staff", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 80);
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 100);
	set_skill("cloudstaff", 100);
	set_skill("bolomiduo", 200);
	set_skill("buddhism", 200);
        set_skill("jin-gang", 250);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");
        set("agi",25);
        set("int",30);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who, object ob)
{
        if( ob->value() >= 1000000)
        {
message_vision("$N��$n˵������лʩ����\n",
this_object(),who);
/*
        who->add("potential",(int) ob->value()/3000000);
        log_file("HUOFO",sprintf("%s %s %d\n",ctime(time()),who->query("id"),
        (int) ob->value()/3000000));
*/
                return 1;
        }
        return 0;
}       

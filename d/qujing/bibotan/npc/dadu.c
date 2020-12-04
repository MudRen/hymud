inherit NPC;

void create()
{
        set_name("大肚虾婆", ({"xia po", "po"}));
        set("long", "一个挺着肚子走来走去的老虾婆。\n");
        set("age", 50);
        set("attitude", "peaceful");
        set("gender", "女性");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_qi",500);
        set("max_jing", 500);
        set("combat_exp", 5000);
  set("combat_exp", 10000);

	set("eff_dx", -2000);
	set("nkgain", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("neili", 60);
        set("max_neili", 50);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 20);
        set_skill("force", 20);
        set_skill("spells", 20);
        set_skill("dodge", 20);
	set_skill("hammer", 20);
	set("chat_chance", 10);
	set("chat_msg", ({	
	"大肚虾婆挺了挺肚子。\n",
	(: random_move :)
}));
        setup();
	add_money("silver", random(2)+1);
        carry_object("/d/obj/cloth/skirt")->wear();
}

�
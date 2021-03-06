// tufei1.c
//by dicky

inherit NPC;

void create()
{
        set_name("土匪头目", ({ "tufei tou","bandit","fei" }) );
        set("gender", "男性");
        set("age", 30);
        set("long",
                "这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");
        set("combat_exp", 150000);
        set("shen_type", -1);
        set("attitude", "killer");
        set("apply/attack", 20);
        set("apply/defense", 20);
      	set("chat_chance", 2);
      	set("chat_msg", ({
          "土匪一声大喊: 此山是我开，此树是我栽，若要从此过，留下买路财 !\n",
      }) );

        set("max_sen",1500);
        set("max_qi", 1500);
        set("qi", 1500);

	set("max_jing", 1500);
	set("max_jing", 1500);
	set("neili", 150);
	set("max_neili", 150);
	set("force_factor", 15);

	set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/hujia")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
        add_money("silver", 40);
}
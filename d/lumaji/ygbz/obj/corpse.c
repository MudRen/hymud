// tufeitou.c

inherit NPC;

void create()
{
	set_name("���۽�ʬ", ({ "flash corpse","corpse leader","corpse" }) );
	set("gender", "����");
	set("age", 45+random(10));
   //         set("str",999);
            set("per", 10);
	set("long",
		"��һ������������ˣ�̫�����ˣ�����������η��\n");
	set("combat_exp", 280000+random(9000000));

        set("shen_type", -1);
	set("attitude", "aggressive");

         set("force_factor",2+random(10000));
         set("max_qi",8000+random(59900));
         set("max_jing",8000+random(59900));
         set("max_sen",8000+random(59900));
        set("max_neili",8000+random(59900));
        set("max_mana",300+random(59900));
        set_temp("apply/attack", 200+random(200));
        set_temp("apply/defense", 200+random(200));
        set_temp("apply/armor", 200+random(300));
        set_temp("apply/damage", 200+random(200));

	set("chat_chance", 5);
	set("chat_msg", ({
		"��ʬ�ٺٵعֽ���: ���±���!\n",
	}) );

	set_skill("strike", 380+random(50));
	set_skill("unarmed", 350+random(50));
	set_skill("parry", 350+random(50));
	set_skill("dodge", 350+random(50));
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike",320);
	set_skill("hand",320);
	set_skill("training",380);
	set_skill("staff", 250);
	set_skill("hamagong", 380);
	set_skill("chanchu-bufa", 380);
	set_skill("shexing-diaoshou", 380);
	set_skill("lingshe-zhangfa", 380);
	set_skill("hamashengong", 380);
	set_skill("xiyu-tiezheng", 380);
set_skill("shentuo-zhang", 380);
	map_skill("strike", "hamashengong");
	map_skill("force", "hamashengong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "hamashengong");
	map_skill("hand", "xiyu-tiezheng");
	map_skill("parry", "hamagong");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamashengong");


       set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: command("zhaoshe") :),
                (: perform_action, "strike.hama" :),                
               (: perform_action, "strike.puji" :),                
	              (: perform_action, "strike.tui" :),                
		          (: perform_action, "strike.zhen " :),                
                (: perform_action, "hand.shewu" :),                
             
        }) );

	setup();
//       carry_object("d/city/npc/obj/gangjian")->wield();
       carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 1);
}


void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}
inherit NPC;

void create()
{
        set_name("�Ҷ�", ({ "jia ding", "jia", "ding"}));
        set("gender", "����" );
        set("age", 20);
        set("long", "һ����ʮ��������꣬���̼ұ��ڵ��\n");
        set("shen_type", 1);
        set("combat_exp", 2000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
        set("attitude", "peaceful");
  set("max_qi",3500+800);
  set("max_jing",3500+800);
  set("max_sen",3500+800);
  set("max_neili",3500+800);
  set("max_mana",3500+800);
  set("eff_neili",3500+800);
  set("neili",3500+800);
        set("per", 1);
        set("age", 22);

       set("jiali" , 50);
        set("shen", -5000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 1000000+random(250000));
                 set_skill("claw", 190+random(30));

set_skill("hunyuan-yiqi", 190+random(30));

set_skill("yijinjing", 190+random(30));

set_skill("force", 190+random(30));
set_skill("blade", 190+random(30));

set_skill("parry", 190+random(30));

set_skill("dodge", 190+random(30));

set_skill("xiuluo-dao", 190+random(30));

set_skill("shaolin-shenfa", 190+random(30));

set_skill("longzhua-gong", 190+random(30));

  
        map_skill("blade", "xiuluo-dao");
  
      map_skill("parry", "xiuluao-dao");

 map_skill("force", "hunyuan-yiqi");

 map_skill("dodge", "shaolin-shenfa");
 
map_skill("claw"  , "longzhua-gong");
prepare_skill("claw", "longzhua-gong");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "blade.sanjue" :),
	
      (: perform_action, "claw.sanzhua" :),
	
      (: exert_function, "recover" :),
 }) );
            set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
 
          set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);

        setup();
         carry_object("/d/migong/obj/blade")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(!userp(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

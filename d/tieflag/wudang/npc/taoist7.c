 inherit NPC;
int kill_him();
void smart_fight(); 
void create()
{
        object armor;
        set_name("过长逊", ({ "guo changxun" }) );
        set("gender", "男性");
        set("age", 39);
        set("long",
                "武当派掌门弟子，着一身藏青色的道袍。\n"
        );
        
        set("inquiry", ([
            "头颅骨" : (: kill_him :),
             "武当老掌门" : (: kill_him :),
              "老掌门" : (: kill_him :),
        ]));
        
        set("attitude","friendly");
        set("combat_exp", 4500000);
        set("score", 200);
        set("class", "wudang"); 
        set("neili",2000);
        set("max_neili",2000);
        set("force_factor",100);
        set("str",40);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40); 

        
        set("no_busy",8);
        
        create_family("武当派", 58, "弟子"); 
       set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
        
        setup(); 
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/skinmask2");
        armor=new("/clone/misc/cloth");
        armor->set_name("藏青色的道袍",({"cloth"}) );
        armor->move(this_object());
        armor->wear(); 
} 
int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="武当派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 武当派不和别派的人过招。");
        return 0;
} 
int kill_him()
{
        object me;
        me = this_player();
        if (!me->query("m_success/尚方宝剑")||!me->query("m_success/头颅骨")    )       {
           command("heng");
                command("say 老掌门是去年这个时候仙逝的。\n");
                return 1;
        }       
        command("say 看来你知道得真不少！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        this_object()->set("have_mask",1);        
        return 1;
}
 
void die(){
        object *inv, ob, killer;
        int i;
        if(objectp(killer=query_temp("last_damage_from") ))
        if (killer->query("m_success/头颅骨")&& this_object()->query("have_mask")
                && !killer->query("marks/老刀把子")) {
                ::die();
                return;
                }
        inv = all_inventory(this_object());
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("name")== "面具") {
                        destruct(ob);
                }
        }
        ::die();
}  
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie2");
                return;
        }
   return;
}  

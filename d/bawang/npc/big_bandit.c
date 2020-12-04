 inherit NPC;
void call_for_help(); 
void create() 
{ 
        set_name("大喽罗", ({ "da louluo","louluo" }) ); 
        set("gender", "男性"); 
        set("age", 36); 
        set("long", 
                "一个饿得肚子看着寨门的饿虎岗强盗。。\n"); 
        set("combat_exp", 560000); 
        set("score", 80); 
        set("max_qi",300000); 
        set("qi",300000); 
        set("max_jing",100000); 
        set("jing",100000); 
        set("max_neili",100000); 
        set("neili",100000); 
        set("str",60); 
        set("cor",40); 
        set("con", 30); 
        set("attitude", "friendly"); 
        set("chat_chance", 2);
        set("chat_msg", ({
                "\n大喽罗撇撇嘴骂道：“这世道强盗真他妈难做，早知道还不如改行当要饭的。”\n", 
                "\n大喽罗嘴里不停地地咒骂著。\n", 
                 
        }) ); 
        set_skill("blade", 100); 
        set_skill("unarmed",100); 
        set_skill("parry", 100); 
        set_skill("dodge", 100); 
        set_skill("demon-blade",80); 
        map_skill("blade","demon-blade"); 
        
          set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );
 

        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(380));
                map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        setup(); 
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 5); 
} 
 
int accept_fight(object me) 
{ 
        command("say 到饿虎岗撒野？"); 
        command("kao"); 
        kill_ob(me); 
        return 1; 
} 
 
int accept_object(object me, object obj) 
{ 
        if(obj->query("id")=="meat") 
        { 
                me->set_temp("yuehu",1); 
                say( "大喽罗双眼放光，放下家伙，饿虎扑食般冲过来大嚼大啃起来。\n"); 
                return 1; 
        }  
        else { 
                command("shake"); 
                return 0; 
        } 
        return 0; 
}     

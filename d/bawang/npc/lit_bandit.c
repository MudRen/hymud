 inherit NPC;
void call_for_help(); 
 
void create() 
{ 
        set_name("С���", ({ "xiao louluo","louluo" }) ); 
        set("gender", "����"); 
        set("age", 26); 
        set("long", 
                "һ�����ö��ӿ���կ�ŵĶ�����ǿ������\n"); 
        set("combat_exp", 420000); 
        set("score", 80); 
        set("max_qi",300000); 
        set("qi",300000); 
        set("max_jing",100000); 
        set("jing",100000); 
        set("max_neili",100000); 
        set("neili",100000); 
        set("cor",30); 
        set("str",60); 
        set("con", 30); 
        set("attitude", "friendly"); 
        set("chat_chance", 2);
        set("chat_msg", ({
                "\nС���ƲƲ���������������ǿ����������������֪����������е�Ҫ���ġ���\n", 
                "\nС������ﲻͣ�ص���������\n", 
                 
        }) ); 
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
        command("say ����������Ұ��"); 
        command("kao"); 
        kill_ob(me); 
        return 1; 
} 
 
int accept_object(object me, object obj) 
{ 
        if(obj->query("id")=="meat") 
        { 
                me->set_temp("yuehu",1); 
                say( "С���˫�۷Ź⣬���¼һ������ʳ������������������\n"); 
                return 1; 
        } 
        else  
        { 
                command("shake"); 
                return 0; 
        } 
        return 0; 
}

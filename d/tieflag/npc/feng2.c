 // feng.c
inherit NPC;
string lishi_kill(object);
void create()
{
    set_name("�����",({"feng jiuyou","feng"}));
    set("long","������»꣬��������\n");
    set("nickname","��������");
    set("gender","����");
    set("age",42);
    set("int",22);
    set("cor",30);
    set("per",30);
    set("cps",20);
    set("jing",1000);
    set("max_jing",1000);
    set("eff_gin",1000);
    set("max_qi",1000);
    set("eff_qi",1000);
    set("qi",1000);  
    set("max_sen",1000);
    set("jing",1000);    
    set("eff_sen",1000);
    set("combat_exp",400000);  
    set_skill("nine-moon-claw",100);
    set_skill("force",100);
    set_skill("demon-force",150);
    set_skill("unarmed",100);
    set_skill("parry",150);
    set_skill("dodge",150);
    set("neili",10000);
    set("max_neili",10000);
    set("force_factor",200);
    map_skill("force","demon-force");
    map_skill("unarmed","nine-moon-claw");
    set("attitude", "heroism");
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
         (: exert_function, "mihun" :),
         (: lishi_kill(this_object()) :),
    })  );
    
    
    setup();
    carry_object("/clone/misc/cloth")->wear();   
    add_money("coin", 30);
}
string lishi_kill(object feng)
{
        int i;
        object *enemy;
        object lishi;
        seteuid(getuid());
        lishi = present("li shi",environment());
    if (!objectp(lishi)) return "";
        
        message_vision("$N��ȣ�������ʿ���ڣ���\n", this_object() );
        enemy = feng->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        lishi->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(lishi);
                }
        }
}       

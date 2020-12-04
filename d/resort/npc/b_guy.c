 inherit NPC;
void create()
{
        set_name("���۹�", ({ "oldguy" }) );
        set("class","legend");
        set("gender", "����" );
        set("age", 65);
        set("str", 46);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27); 
        set("attitude", "peaceful"); 
        set("force_factor", 10);
        set("max_atman", 300);
        set("atman", 300);
        set("max_neili", 800);
        set("force", 800);
        set("max_mana", 300);
        set("mana", 300); 
        set("long",     "���۹��������壬ʲôҲ����\n");  
        set("combat_exp", 999999); 
        set_skill("unarmed", 120);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70); 
        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 80);
        set_skill("fall-steps", 10); 
        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");
        map_skill("force","qidaoforce"); 
        set("chat_chance", 1);
        set("chat_msg", ({
               (: exert_function, "juqi" :),
        }) );     
        /*set("chat_c  nc _co  at , 3  ;         set  ch t_m  _c mba  ,  {
                (: perform_action, "unarmed.meihai" :),
   }) ); */
        setup(); 
        carry_object(__DIR__"obj/bqi")->wield();
        carry_object(__DIR__"obj/wcloth")->wear();
} 
void init()
{
        ::init();
        set_temp("qidaoforce_juqi",1);
}             

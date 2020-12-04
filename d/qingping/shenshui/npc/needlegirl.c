 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("�廨��Ů��", ({ "sewing girl" }) );
        set("gender", "Ů��");
        set("age", 25);
        set("long",
"һ����ˮ������Ů,��������������ǰ�廨��\n"
); 
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
        set("difficulty", 2); 
        
        set("combat_exp", 3000000);        
        set("int", 30);
        set("cps", 30);
        set("spi", 30); 
        set("force", 1000);
        set("max_neili",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
        switch (random(5)) {
                case 0: set("resistance/sen",30);
                        break;
                case 1: set("resistance/gin",30);
                        break;
                default: set("resistance/kee",30);
                }
        
            set_skill("unarmed", 250);
        set_skill("throwing", 285);
        set_skill("force", 250);
        set_skill("parry", 267);
        set_skill("dodge", 269);
        set_skill("literate", 250);

        set_skill("nine-moon-steps", 268);
        set_skill("nine-moon-claw", 235+random(30));
        set_skill("nine-moon-force", 260);
        set_skill("nine-moon-sword", 270); 
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbu" :),
                (: perform_action, "unarmed.suicidal" :),
                
        }) ); 
        
        setup(); 
        add_money("gold", random(1));
        carry_object(__DIR__"obj/n_stone")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 

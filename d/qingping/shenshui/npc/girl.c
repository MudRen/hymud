 // thousand_hand.c
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("��Ů" , ({ "girl", "shi nu" }) );
        set("long", "һλʮ�����Ѿͷ��\n");
        set("attitude", "friendly");
        set("class","shenshui");
        set("max_jing", 500);
        set("max_qi", 500);
        set("max_jing", 500);
        set_skill("unarmed",10);
        set_skill("nine-moon-claw",10);
        map_skill("unarmed","nine-moon-claw");
        set("age", 15);
        set("gender", "Ů��" );
        set("combat_exp", 5000);
        set_skill("dodge", 50+random(100));
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.suicidal" :),
        }) );   
        setup();
        carry_object("/clone/misc/cloth")->wear();
}  

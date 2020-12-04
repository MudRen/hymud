 // post_officer.c
inherit NPC; 
string send_mail();
string receive_mail(); 
void create()
{
        set_name("王风", ({ "officer", "post officer" }) );
        set("title", "风云绎驿长");
        set("gender", "男性" );
        set("age", 43);
        set("long",
                "王风担任风云驿的驿长已经有几年了，人很好，\n"
                "居民对王风的风评相当不错，常常会来到驿站跟他聊天。\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
                "驿站" : "是啊... 这里就是风云绎，你要寄信或租马车吗？",
       ]));
        set_skill("literate", 70);
        set_skill("unarmed", 400);
        setup();
        add_money("coin", 70);
        carry_object("/clone/misc/cloth")->wear();
} 

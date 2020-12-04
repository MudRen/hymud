 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("空光", ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",random(10)+ 32);
        set("long", "这是少林寺出外化缘的和尚，奉方丈之命来化解武林人士和少林的纠纷。\n");
        create_family("少林寺", 23, "弟子");
        set("combat_exp", random(10000)+10000);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
                "空光唱了个肥诺道：＂施主捐点香火钱吧！＂\n",
        }) );
     
        set_skill("unarmed", 5+random(40));
        set_skill("dodge",90);
        set_skill("force",20); 
        set("neili",100);
        set("max_neili",100);
        set("force_factor",2);
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/bowl");
} 
int accept_object(object who, object ob)
{
        int num;
        num=who->query("vendetta/shaolin");
        if( ob->value() >= 300000
                ||(ob->value() >= 100000 && num<10)) {
                        command( "say 善哉善哉，放下屠刀，回头是岸...");
                        command( "say 贫僧会为施主每日焚香一柱，诵经三卷。\n");
                        who->set("vendetta/shaolin", 0);
                        who->remove_all_killer();
                        return 1;
                } else {
                        command("say 施主罪孽深重，这点怕是。。。\n");
                        return 0;
                }
        return 0;
}      

//guan2.c.����Ժ��Ա
//date:1997.8.27                            
//by dan  

#include <ansi.h>
inherit NPC;

void create()
{
    set_name(RED"��Ա"NOR, ({ "guanyuan" }) );
    set("title","���Ĺ���Ժ");
    set("gender", "����" );
    set("combat_exp", 100000);
    set("max_qi", 400);
    set("max_sen", 300);


        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
        }) );

    set("attitude", "friendly");
    set("env/attack", 78); 

    set("talk_limit/combat_exp",10000);
    set("talk_msg",({
"�����Ǵ��������е�������������ʲô?\n",
        }) );

    setup();
    carry_object(__DIR__"obj/cloth3")->wear();
    carry_object(__DIR__"obj/jian3")->wield();
}
        

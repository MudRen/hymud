//NPC: /d/lingshedao/npc/huiyue.c
//Creat by Yjss on Sep.1999
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("����ʹ", ({"hui yue", "hui",}));
        set("long",
        "��Ů��һͷ�ڷ����ͻ������죬�����Ӽ�����������ɫ.\n"
        );
        set("nickname",MAG"��˹�����̻ܽ���ʹ��" NOR);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("age", 30);
        set("shen_type",-1);
        set("per", 25);
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 30);
set_temp("no_kill",1);
        set("max_qi", 27000);
        set("max_jing", 27200);
        set("neili", 27000);
        set("max_neili", 27000);
        set("jiali", 50);
        set("combat_exp", 7400000);
        set("score",20000);

        set_skill("force", 380);
        set_skill("dodge", 380);
        set_skill("lingfa", 380);
        set_skill("parry", 380);
        set_skill("qiankun-danuoyi", 390);
        set_skill("shenghuo-shengong", 380);
        set_skill("shenghuo-ling",385);
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qiankun-danuoyi");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("sword", "shenghuo-ling");

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: perform_action, "sword.lian" :),                
                (: perform_action, "sword.can" :),                
                (: perform_action, "sword.hua" :),                                                              
                (: perform_action, "dodge.yi" :),                                
        }) );
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",2500);
	set_temp("apply/damage",2500);
       
        setup();
        carry_object("/d/mingjiao/obj/baipao")->wear();
        carry_object(__DIR__"obj/shenghuo-ling")->wield();
//        carry_object("/clone/book/shenghuo-ling")->wield();
        
}

void init()
{
        object ob=this_player();
        ::init();
        if(interactive(ob) && ob->query("party/party_name")== HIG "����" NOR)
        message_vision(HIR"����ʹֱ�����Ŀ���$N.\n"NOR,ob);
}



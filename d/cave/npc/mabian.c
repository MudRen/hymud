#include <ansi.h>
inherit NPC; 
void create()
{
    set_name("���", ({"ma bian","ma"}) );
        set("gender", "����" );
        set("nickname", RED"�����"NOR);
        set("title", "������ �̿�");
        set("long", "�������ݣ������˾��Ǹ����ӣ������е����Ҳ������������\n");
        set("attitude", "friendly");
        set("age", 35);
        set("cor", 25);
        set("cps", 25);
        set("combat_exp", 1500000);
        set("class","yinshi");
        set("force", 2000);
            set("reward_npc", 1);
            set("difficulty", 2);
        set("max_neili", 2000);
        set("force_factor", 60);
        set_temp("apply/armor", 100); 
        
        set_skill("whip", 150);
        set_skill("thunderwhip", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
        set_skill("fengyu-piaoxiang",200);
        set_skill("luoriquan",200);
        set_skill("unarmed",200);
        
        map_skill("move","fengyu-piaoxiang");
        map_skill("unarmed","luoriquan");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("whip", "thunderwhip");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("dodge.zonghengsihai") :),    
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "���˦��˦���г��ޣ���ڽ�������㡣\n",
        }) ); 
        setup();
        carry_object(__DIR__"obj/horsewhip")->wield();
        carry_object("/clone/misc/cloth")->wear();
        if (!random(5)) carry_object(__DIR__"obj/stone_1");
                else add_money("gold", random(4));
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() )
                return;
        if (!ob->query("vendetta/authority")){
            message_vision("$N�ٺٵ�����������˽��������ĵ�ͷ���������ɣ�\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
}  

#include <ansi.h>
inherit NPC;
int answer_robery();
int answer_di();
int answer_yang();  
void create()
{
        set_name("СҶ��", ({ "xiao yezi","yezi" }) );
        set("long",
                "СҶ�ӿ�����ֻ��ʮ����������ӣ�ü��Ŀ�㣬��������ϲ�������ӡ�\n");
        set("title", "�Ҹ���ͯ");
        set("attitude", "friendly");
        set("class", "wolfmount");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("age",15);
        set("str", 60);
        set("cor", 40);
        set("agi", 80); 
        set("combat_exp", 500000+random(3500000)); 
        set_skill("dagger",200);
        set_skill("parry",200);
        set_skill("dodge",200);
        set("chat_chance_combat", 60);
        
/*
        set("inquiry", ([
                "���ڰ�" : (: answer_robery :),
                "robery" : (: answer_robery :),
                "���" : (: answer_yang :),
                "yang" : (: answer_yang :),
                "yang zheng" : (: answer_yang :),
                "������" : (: answer_di :),
                "di" : (: answer_di :),
                "di qinglin" : (: answer_di :),
        ]));
*/ 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/bishou")->wield();
} 
void init()
{
        if( !query_heart_beat(this_object()) ) set_heart_beat(1);
        ::init();
} 
void heart_beat()
{       object dagger;
        
        dagger=present("dagger",this_object());
        if(objectp(dagger))
        {
        if(!this_object()->is_fighting())
        {
                if (dagger->query("equipped"))
                        this_object()->ccommand("unwield dagger");
        }
        else if (!dagger->query("equipped"))
                        this_object()->ccommand("wield dagger");
        }
        ::heart_beat();
}  

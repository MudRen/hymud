inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave();
void create()
{
    set_name( "����Ϫ" , ({ "master yu",  "master" }) );
    set("gender", "Ů��");
    set("title", "�ɹ��� ����");
    set("nickname", HIC"�չ��ľ�"NOR);
    set("age", 46);
    set("long", "һ��С���ֵ����֣�\n");
        set("reward_npc", 1);
        set("difficulty", 2); 
    set("combat_exp", 10000000);
    set("score", 50000); 
    set("class", "mei"); 
    set("str", 30);
    set("int", 30);
    set("cor", 20);
    set("cps", 30);
    set("spi", 30); 
    set("neili", 2000);
    set("max_neili", 2000);
    set("force_factor", 60); 
    set("atman", 1500);
    set("max_atman", 1500); 
    set("mana", 3000);
    set("max_mana", 3000);
    set("inquiry", ([
         "leave" : (: leave :),
        ]) ); 
    set("apprentice_available", 5);
    create_family("�ɹ���", 1, "����");
    set("rank_nogen",1);
    set("ranks",({"�ӹ�","��ͷ","���","ʦ��","��ʦ",WHT"����"NOR,WHT"ʥ��"NOR,HIW"����"NOR}));
    set_skill("literate", 140);
    set_skill("force", 200);
    set_skill("spells", 280);
    set_skill("move", 200);
    set_skill("unarmed", 150);
    set_skill("xianglong-zhang",160);
    set_skill("sword", 200);
    set_skill("lonely-sword", 220);
    set_skill("iron-cloth", 180);
    set_skill("parry", 160);
    set_skill("dodge", 200);

    set_skill("liuquan-steps", 160); 

    map_skill("unarmed", "xianglong-zhang");
    map_skill("sword", "lonely-sword");
    map_skill("parry", "qiuzhi-sword");
    map_skill("dodge", "liuquan-steps");  
    map_skill("move", "liuquan-steps");  
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :),
        }) );
        setup();
    set_temp("apply/dodge", 200);
    set_temp("apply/armor", 30); 
	set_temp("xuanxinaomiao",1);
    setup(); 
        carry_object("/clone/misc/cloth")->wear();
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mei");
        add("apprentice_availavble", -1);
} 

int leave() {
   if (this_player()->query("class")!="mei") return 0;
        message_vision(CYN"$N̾���������ɹȣ��������ˣ������İ�������֦��ʽ�ľ�������򲻵��ˡ�\n"NOR, this_object(),this_player());
        return 1;
}  
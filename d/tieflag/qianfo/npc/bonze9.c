 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void smart_fight(); 
void create()
{
        set_name("����", ({ "yunlin" }) );
        set("gender", "����" );
        set("class", "bonze");
        set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 29);
        set("int", 25);
        set("fle",200);
        set("long", "�����˹��������������������ֱ���ʦ��\n");
        set("combat_exp", 6000000);
        set("attitude", "friendly");
        
        set("resistance/kee",10);
        set("resistance/sen",10);
        
        set("max_neili", 1500);
        set("neili", 1500);
        set("force_factor",60);
        
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
                
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
            set_skill("parry", 120);



              
        set("chat_chance", 1);
        set("chat_msg", ({
                "����˵�������������\n",
        }) );
        set("inquiry", ([
                "����" : "�����ں�԰��\n",
                "master" : "�����ں�԰��\n",
        ]));
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
        carry_object(__DIR__"obj/shoe2")->wear();
}
int accept_fight(object me)
{
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
} 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()) {
                who->cast_spell("zombie-bolt");
                return;
        }
        if (random(3)>1) who->perform_action("unarmed.qianshouqianbian");
        return;
}  

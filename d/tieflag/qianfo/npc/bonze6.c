 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_qin();
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("�ƿ�", ({ "yunkong" }) );
        set("gender", "����" );
        set("class", "bonze");
        set("title","�˹��������ֱ���ʦ");
        set("age", random(40)+20);
        set("cor", 24);
        set("cps", 60);
        set("int", 25);
        set("long", "�����˹��������������������ֱ���ʦ\n");
        set("combat_exp", 4500000);
        set("attitude", "friendly");
        
        set("max_neili", 1000);
        set("neili", 1000);
        set("force_factor",50);
        set("max_atman",1500);
        set("atman",1500);
        set("mana",1500);
        set("max_mana",1500);
        
        set("resistance/kee",50);
        set("resistance/gin",50);
        set("resistance/sen",50); 
                 

        

        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);

        set_skill("dodge",200);
        


              
        set("chat_chance", 1);
        set("chat_msg", ({
                "�ƿ�˵��������ѧ������\n",
        }) );
        set("inquiry", ([
                "����" : (: give_qin :),
                "jigu" : (: give_qin :),
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
int give_qin()
{
        object obj;
if( !query("given"))
        {
command("say ��ѷ������ȥ���ɣ���\n");
obj = new(__DIR__"obj/fegu");
obj->move(this_player());
set("given",1);
        }
else
command("say �ҵķ���������ˣ�\n");
        return 1;
} 
void reset()
{
delete("given");
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

 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
    set_name("��������", ({ "master di", "master"}) );
    set("nickname", HIW "�ض����"NOR);
    set("gender", "����" );
        set("reward_npc", 1);
        set("difficulty", 2);
    set("age", 63);
    set("per", 3);
    set("agi",25);
    set("int",30);
    set("attitude","friendly");
    set("max_neili", 7500);
    set("force", 7500);
    set("force_factor", 30);
    set("long",
        "������������������еĵ�λ�ǽ�������ʱ���˵ģ�"
        "��������ͳ������������еĵض档\n");
    create_family("�������", 3, "����");
    set("rank_nogen",1);
    set("ranks",({"��ͽ","������","����","��̳��","̳��",
                      "������","����","����","�󻤷�",
                      "����","����","������"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.dimo" :),
            (: perform_action, "dodge.lianhuanbabu" :),
            (: perform_action, "unarmed.dimo" :),
            (: exert_function, "mihun" :)
            }) );
    set("combat_exp", 1200000);
    set("score", 200000); 
    set_skill("move", 100);
    set_skill("parry",100);
    set_skill("dodge", 100);
    set_skill("force", 100);
    set_skill("literate", 100);
    set_skill("blade", 100);
    set_skill("unarmed",100);
    set_skill("demon-steps",100);
    set_skill("demon-strike",100);
    set_skill("demon-blade",100);
    set_skill("demon-force",100);
    
    map_skill("parry", "demon-blade");
    map_skill("blade", "demon-blade");
    map_skill("dodge", "demon-steps");
    map_skill("force", "demon-force");
    map_skill("unarmed", "demon-strike");
    setup();
    carry_object(__DIR__"obj/duoyi2")->wear(); 
} 
void attempt_apprentice(object me)
{
        command("say �������������֣���Ҫ�����ˡ�����");
        return ;
    if(me->query("family/family_name") == "�������")
    {
        command("say ������������̵��ӣ���˭ѧ��һ����\n");
        return;
    }
    command("smile");
    command("say ���Ŭ��������һ�鲻��֮�ģ�\n");
    command("recruit " + me->query("id") );
} 
void recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "bandit");
}   


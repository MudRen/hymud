 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("�׻�", ({ "bai huan", "bai"}) );
        set("gender", "����" );
        set("age",22);
        set("long", "һ���嵶�Ļ�ɽ�ɵ��ӡ�\n");
        create_family("��ɽ��", 6, "����");
        set("combat_exp", random(500000)+500000);
        set("attitude", "friendly");
        set_skill("blade", 60+random(10));
        set_skill("qiusheng-blade",random(50)+30);
        set_skill("move",60);
        set_skill("force",20);
        set_skill("dodge",100);
        set_skill("liuquan-steps",40+random(40));
        set_skill("parry",50);
        map_skill("blade", "qiusheng-blade");
        map_skill("parry","qiusheng-blade");
        map_skill("dodge","liuquan-steps");
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"˵������ɱ�����أ�\n",
        }) );
        set("chat_chance_combat", 30);
        set("neili",500);
        set("chat_msg_combat", ({
                (: perform_action, "blade.jingsheng" :),
        }) );
        set("max_neili",500);
        set("force_factor",2);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
}    

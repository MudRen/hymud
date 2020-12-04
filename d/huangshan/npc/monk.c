 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("�չ�", ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(10)+ 32);
        set("long", "���������³��⻯Ե�ĺ��У����֮��������������ʿ�����ֵľ��ס�\n");
        create_family("������", 23, "����");
        set("combat_exp", random(10000)+10000);
        set("attitude", "friendly");
        set("chat_chance", 2);
        set("chat_msg", ({
                "�չ⳪�˸���ŵ������ʩ��������Ǯ�ɣ���\n",
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
                        command( "say �������գ�������������ͷ�ǰ�...");
                        command( "say ƶɮ��Ϊʩ��ÿ�շ���һ�����о�����\n");
                        who->set("vendetta/shaolin", 0);
                        who->remove_all_killer();
                        return 1;
                } else {
                        command("say ʩ���������أ�������ǡ�����\n");
                        return 0;
                }
        return 0;
}      

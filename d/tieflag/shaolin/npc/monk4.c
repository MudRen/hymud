 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"��","��","��","ȥ","��","��","��","��","��","��","��","λ"});
        set_name("Բ"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("class","shaolin");
        set("age",random(20)+ 32);
        create_family("������", 22, "����");
        set("long", "���Ƕ����µĺ���\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", random(100000)+100000);
        set("attitude", "friendly");
        set("cps",80);
        set("neili",500);
        set("max_neili",500);
        set("force_factor",15);
        
        set_skill("blade", 60+random(100));
        set_skill("dodge", 60+random(60));
        set_skill("shaolin-shenfa",60);
        set_skill("jingang-quan",60);
        set_skill("xiuluo-dao",random(100)+50);
        set_skill("move",80);
        set_skill("force",200);
        map_skill("unarmed","jingang-quan");
        map_skill("dodge","shaolin-shenfa");        
        map_skill("blade", "xiuluo-dao");
        
/*      set("chat_chance", 2);
        set("chat_msg", ({
                name()+"˵������˵���������˴�ľ�������ɽȥ�ˣ�\n",
        }) );*/
        
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
//         name()+"Ц�����ڶ����´���ǰ��Ұ��\n",
                (: perform_action, "blade.yipianlianxin-npc" :),
        }) );
        setup();
        carry_object(__DIR__"obj/monk22_cloth")->wear();
        carry_object(__DIR__"obj/jiblade")->wield();
} 
int accept_object(object who, object ob)
{
                if( (int)ob->value() >= 50000 ) {
                        say( name()+"���˵����е�"+ob->name()+"��Ц������������������������\n");
                        say( name()+"˳�ֽ�"+ob->name()+"�����˻��С�\n");
                        who->set_temp("shaolin", 1);
                        return 1;
                } else {
                        command("shake");
                        return 0;
                }
        return 0;
}      

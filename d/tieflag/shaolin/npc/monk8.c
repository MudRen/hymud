 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        string *name = ({"��","��","��","��","��","��","Ӱ","��","��","��","��","��"});
        set_name("��"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "����" );
        set("age",random(20)+ 32);
        set("cor",random(20)+20);
        set("class","shaolin");
        create_family("������", 19, "����");
        set("long", "���Ƕ����µĺ���\n");
        set("vendetta_mark","shaolin");
        set("combat_exp", 800000);
        set("attitude", "friendly");
        set("cps",80);
        set("neili",550);
        set("max_neili",550);
        set("force_factor",20);
        
        set_skill("blade", 160);
        set_skill("dodge", 160);
        set_skill("shaolin-shenfa",150);
        set_skill("jingang-quan",160);
        set_skill("xiuluo-dao",150);
        set_skill("move",180);
        set_skill("force",200);
        map_skill("unarmed","jingang-quan");
        map_skill("dodge","shaolin-shenfa");        
        map_skill("blade", "xiuluo-dao");
         
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.yipianlianxin-npc" :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/monk21_cloth")->wear();
   carry_object(__DIR__"obj/jiblade")->wield();
}   

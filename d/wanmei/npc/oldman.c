 inherit NPC;
void create()
{
        set_name("������˪������", ({ "oldman", "old man", "man" }) );
        set("gender", "����");
        set("age", 74);
        set("long",
"����һ��������˪�����ˣ�����˫Ŀ����̫��Ѩ�߸�¡��\n"
               );  
        set("attitude", "peaceful");
        set("combat_exp", 2000000);
        set("reward_npc", 1);
        set("difficulty", 2);
        set("chat_chance", 1);
        set("chat_msg", ({
                "������˪������������ԶԶ��һ���������̸е�͸����������\n",
        }) );
        set("force", 1000);
        set("max_neili", 1000);
        set("force_factor", 60); 
        
        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("parry", 100);
        set_skill("dodge", 200);
        set_skill("move", 150);
        set_skill("doomforce", 50);
        set_skill("doomstrike", 110);
        set_skill("doomsteps", 110);
        
        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("dodge", "doomsteps"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.hantian" :),
        }) ); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

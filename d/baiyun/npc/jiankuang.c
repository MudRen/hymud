 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("����" , ({ "jian kuang","jian" }) );
    set("long", "�򽣶���Ϊ������\n");
        set("attitude", "friendly");
    set("age", 62);
        set("gender", "����" );
        create_family("���Ƴ�",1, "����");
    set("per",4);
            set("neili",15000);
        set("max_neili",15000);
        set("max_qi",15000);
        set("max_jing",15000);
        set("jing",15000);
        set("qi",15000);
    set("combat_exp", 3000000);
    set_skill("dodge", 200);
    set_skill("feixian-steps", 500);
    set_skill("feixian-sword", 500);
    set_skill("sword", 200);
    set_skill("unarmed", 100);

    map_skill("dodge","feixian-steps");
    map_skill("sword","feixian-sword");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}    

 // XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("��ʵ" , ({ "song shi","song" }) );
    set("nickname",HIY"���ʵ"NOR);
    set("long", "էһ��ȥ���⺺�ӳ��³��㣬üĿ�ֺ�������ϸ�����������˾�������ʵ�Ǹ�\n����֮�ˡ�\n");
        set("attitude", "friendly");
    set("age", 32);
        set("gender", "����" );
        create_family("���Ƴ�",1, "����");
    set("per",40);
    set("combat_exp", 6000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ʵ���ź��ӳ������Σ���Ȼ˫üһ��������һ�ţ��������˿�����\n",
        "��ʵ��ü΢�壬��̾һ������һ�ֽ����н٣����й�����г������ε��ƽ⣿\n",
        }) );
    set_skill("move", 150);

        set_skill("parry", 180);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 180);
        set_skill("sword", 240);
        set_skill("unarmed",100);
        set_skill("music",220);
        set_skill("feixian-steps",520);
        set_skill("feixian-sword",500);

        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("parry", "feixian-sword");

        map_skill("move","feixian-steps"); 
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );        
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}      

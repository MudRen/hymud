 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKER;
string ask_me(object who); 
void create()

{
    set_name("��ū" , ({ "swords slave","slave" }) );
    set("nickname",CYN"ǧ�ذ��ƿ�����"NOR);
    set("long", "�����Ƶ�Ϊ��֪��ʱ�����������û��֪�����������ϣ�Ҳû��֪������Ҷ\n�³ǵĹ�ϵ��ֻ֪������û�����������ڽ��ַ����������ƺ�ֻ�Ǿ�������\n������ɨ��ڣ���ո�һ�գ��긴һ�ꡣ\n");
    set("attitude", "friendly");
    set("age", 123);
    set("no_busy", 8);
        set("gender", "����" );
        create_family("���Ƴ�",1, "��ڣ�ػ���");
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ū���ű�������������ز����Ž����е�ÿһ�ѽ���\n",
        }) );
    set("per",10);
    set("class", "baiyun");
    set("combat_exp", 30000000);
    set_skill("dodge", 200);
    set_skill("feixian-steps", 500);
    set_skill("feixian-sword", 500);
    set_skill("sword", 200);
        set("neili",15000);
        set("max_neili",15000);
        set("max_qi",15000);
        set("max_jing",15000);
        set("jing",15000);
        set("qi",15000);
    map_skill("sword","feixian-sword");
    map_skill("dodge","feixian-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}    

void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}

int accept_fight(object me)
{
        command("heng");
        kill_ob(me);
        return 1;
}
       

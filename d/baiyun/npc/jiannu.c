 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKER;
string ask_me(object who); 
void create()

{
    set_name("剑奴" , ({ "swords slave","slave" }) );
    set("nickname",CYN"千载白云空悠悠"NOR);
    set("long", "当白云岛为人知晓时，他就在这里，没人知道他究竟多老，也没人知道他和叶\n孤城的关系，只知道从来没有旁门中人在剑林放肆。而他似乎只是静静的在\n这里清扫剑冢，日复一日，年复一年。\n");
    set("attitude", "friendly");
    set("age", 123);
    set("no_busy", 8);
        set("gender", "男性" );
        create_family("白云城",1, "剑冢守护人");
        set("chat_chance", 1);
        set("chat_msg", ({
        "剑奴驮着背，慢慢地轻轻地擦拭着剑林中的每一把剑。\n",
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
       

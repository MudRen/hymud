
// banker.c

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("���Ͽ�", ({ "banker" }) );;
        set("title", "Ǯׯ�ϰ�");
        set("gender", "����" );
        set("age", 26);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",
                
"���Ͽ��Ǹ��������൱˹�ĵ������ˣ�������ʱ�����Щ�Ĳ����ɵ�\n"
                
"���ӣ���Զ�ǵľ�������Ͽ¶������е�����Ī��ĸо���Ϊʲ����\n"
                
"����������Ϊһ�Ҵ�Ǯׯ���ϰ壬������һ��ϡ��Źֵ��书����\n"
                
"�����Ͽ��ƺ������񵭣�������Щ���ߵķ�ǣ�ֻҪ���˲�ȥ������\n"
                "��Ҳ������ȥ�������ˡ�\n");

        set("combat_exp", 200000);
        set("attitude", "friendly");
//        set("pursuer", 1);
        set("env/wimpy", 70);

        set("max_atman", 1000);         set("atman", 1000);             
set("atman_factor", 3);
        set("max_force", 1000);         set("force", 1000);             
set("force_factor", 3);
        set("max_mana", 1000);          set("mana", 1000);              
set("mana_factor", 3);

        set("chat_chance", 15 );
//        set("chat_msg", ({
//                (: random_move :),
//                (: exert_function, "powerfade" :),
//        }) );

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                CYN 
"���Ͽ���Ц��Ц�������㣬���ϵ���������Ź֣���֪������Щʲ�᣿\n" NOR,
                CYN 
"���Ͽµ���Ӱ����һ�£��ƺ��������ϸ�����Ѩ����һ�£�����Ҳ������Ĵ����\n" 
NOR,
                CYN 
"���Ͽ������Ȼ���������������������������Լ����£������޹ء�\n" NOR,
                CYN "���Ͽº�Ȼ�ǺǺǵ�Ц��������ȴ��֪����ЦЩʲ��....\n" 
NOR,
                (: perform_action, "sword.counterattack" :),
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "feeblebolt" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);

        
        setup();
        
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

        add_money("silver", 100);
}

int accept_fight(object me)
{
        command("say ��... Ҫ������ɣ����ǽ�����û��˼��");
        command("grin");
        kill_ob(me);
        return 1;
}
 

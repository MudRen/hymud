// mu.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;




void create()
{
        seteuid(getuid());
        set_name("ľ����", ({ "mu lingzi", "mu","lingzi" }) );
        set("class","taoist");
        set("gender", "����" );
        set("age", 50);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 25);
        set("ker", 24);
        set("kar", 30);
        set("max_force", 1500);
        set("force", 1500);
        set("force_factor", 3);

        set("rank_info/respect", "������");

        set("long",
    "ľ���Ӻ�����棬һ�������޵��г�֮�ˣ�����Щ�ɷ����֮�ࡣ\n");

        create_family("�����", 1,"������");
        set("positive_score",30000);
        set("combat_exp", 1000000);
        set("social_exp", 200000);

   set("combat_exp", 9000000);
        set("str", 55);
        set("max_qi",35000);
        set("max_jing",35000);
        set("max_sen",35000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("atman", 10000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);





        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("strike",380);
	set_skill("literate",380);	
	set_skill("cuff",380);	
	set_skill("changquan",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
set_skill("ill-quan",380);
set_skill("luoriquan",380);
set_skill("qinnashou",380);
	set_skill("array",500);
	set_skill("taoism", 500);
set_skill("shizi-zhan",380);
set_skill("dahong-quan",380);
set_skill("qishang-cuff",380);
set_skill("kongling-jian",380);
set_skill("luofeng",380);
set_skill("taiyi",500);
set_skill("sanqing-jian",380);
set_skill("kongdong-xinfa",380);

        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);

        map_skill("unarmed","qishang-cuff");
        map_skill("sword","sanqing-jian");
        map_skill("force","kongdong-xinfa");
        map_skill("dodge","luofeng");
        map_skill("parry","qishang-cuff");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "roar" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.huan" :),
                (: perform_action, "sword.jianmang" :),
                (: perform_action, "sword.sanlianji" :),	
                (: perform_action, "sword.wanxiang" :),	
    (: perform_action, "dodge.bagua" :),	                	
                (: perform_action, "parry.hunpofeiyang" :),
                (: perform_action, "parry.qishang" :),
            (: exert_function, "zhenhuo" :),
            (: exert_function, "dingshen" :),
            (: exert_function, "sanqing" :),
            (: exert_function, "wuxing" :),			

		(: command("unwield changjian") :),
		(: command("wield changjian") :),

        }) );
	
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
    set("env/attack", 75);
    set("force_factor", 20);

    setup();
carry_object("/clone/weapon/changjian")->wield();
    carry_object(__DIR__"obj/cloth1")->wear();
}


void attempt_apprentice(object ob)
{
         //Hydra 19980507 for ��ʦ
        if( ob->query("hydra/��ʦ/�����") )
        {
            message_vision(CYN"$N��$n˵������������뿪ʦ�ţ���ô�ֻ���"
"���أ���\n"NOR,this_object(),ob);
            return 0;
        }
        if( (int)ob->query("PKS") > 10 ) 
        {
                command("hmm");
                command("say ������Ѫ��Ũ�أ���������õ���\n");
                return;
        }
        if ( ob->query("gender") == "����" )
        {
                command("heihei");
                command("say ����һ���˸�֮�ˣ���������õ���\n");
                return;
        }
        command("en");
        say("ľ����Ц��������λ"+RANK_D->query_respect(ob)+"���Ǹ�����֮��ѽ��\n"
            "�������ܷ������������ͥ��\n");
        command("recruit "+ob->query("id") );
        ob->delete("master");
        ob->set("class","taoist");
        ob->set_family("title","��ɽ�����");
}




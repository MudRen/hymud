// mu.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;




void create()
{
        seteuid(getuid());
        set_name("����֮", ({ "master chang", "chang" }) );
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

        set("rank_info/respect", "�������");

        set("long",
    "������Ϻ�����棬һ�������޵��г�֮�ˣ�����Щ�ɷ����֮�ࡣ\n");

        create_family("�����", 3,"����");
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
        set_skill("literate",280);
        set_skill("unarmed",280);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",280);
	set_skill("strike",280);
	set_skill("literate",280);	
	set_skill("cuff",280);	
	set_skill("changquan",280);
        set_skill("luohua-jian",280);
        set_skill("sword",280);
set_skill("ill-quan",280);
set_skill("luoriquan",280);
set_skill("qinnashou",280);
	set_skill("array",200);
	set_skill("taoism", 200);
set_skill("shizi-zhan",280);
set_skill("dahong-quan",280);
set_skill("qishang-cuff",280);
set_skill("kongling-jian",280);
set_skill("luofeng",280);
set_skill("kongdong-xinfa",280);

        //set_skill("doomsword",280);
        //set_skill("chilian-shenzhang",280);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",280);

        map_skill("unarmed","qishang-cuff");
        map_skill("sword","kongling-jian");
        map_skill("force","kongdong-xinfa");
        map_skill("dodge","luofeng");
        map_skill("parry","qishang-cuff");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "roar" :),
                (: exert_function, "shield" :),
                (: exert_function, "powerup" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.feixue" :),
                (: perform_action, "sword.juedi" :),	
                (: perform_action, "sword.lian" :),	
                (: perform_action, "sword.sanhuan" :),	                	
                (: perform_action, "sword.sui" :),	                	
                (: perform_action, "parry.hunpofeiyang" :),
                (: perform_action, "parry.qishang" :),
(: perform_action, "parry.qishang" :),
(: perform_action, "parry.qishang" :),
(: perform_action, "parry.youyouhunduan" :),		             
(: perform_action, "parry.youyouhunduan" :),		             

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
        say("����λ"+RANK_D->query_respect(ob)+"���Ǹ�����֮��ѽ��\n"
            "�������ܷ������������ͥ��\n");
        command("recruit "+ob->query("id") );
        ob->delete("master");
        ob->set("class","taoist");
        //ob->set_family("title","��ɽ�����");
}




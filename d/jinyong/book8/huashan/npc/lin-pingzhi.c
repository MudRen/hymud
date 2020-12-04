// lin-pingzhi.c

inherit NPC;
#include <ansi.h>;
void yueappear(object who);

void create()
{
        set_name("��ƽ֮", ({ "lin pingzhi","lin","pingzhi"}));
        set("gender", "����");
        set("age", 18);
        set("long",
                "��ƽ֮������Ⱥ��С��һ�����ӣ�Ҳ�����Ķ���������\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 30);
        set("int", 24);
        set("dex", 35);

        set("max_qi",150000);
        set("max_jing",150000);
        set("neili", 150000);
        set("max_neili", 150000);
        set("jiali", 100);

        set("combat_exp", 10000000);
        set("shen_type", -1);
        set("score", 200000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.cimu" :),
                (: perform_action, "sword.huanying" :),
                (: perform_action, "sword.sanlianci" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );
        


        set_skill("unarmed", 500);
        set_skill("sword", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("literate", 500);
        set_skill("pixie-jian",380);
        //set_skill("huashan-sword", 500);
        set_skill("pixie-jian", 380);
        set_skill("kuihua-xinfa", 380);
        set_skill("huashan-ken", 500);
        set_skill("feiyan-huixiang", 500);

        map_skill("sword", "pixie-jian");
        map_skill("parry", "pixie-jian");
        map_skill("force", "kuihua-xinfa");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");

        create_family("��ɽ��", 14, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void unconcious()
{
	die();
}
void die()
{
	object where = environment(this_object());
	object yue = present("yue lingshan",where);
	message_vision("$N˵������ϧ�Ҵ��δ����ʦ�㣬ԭ�������飡\n" NOR,this_object());
	if(yue)
	{
		message_vision("$N�޵��� С����!��\n",yue);
	}
	::die();
}


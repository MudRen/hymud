inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����һ", ({ "shang tianyi","dizi"}));
	set("gender", "����");
	set("age", 23);
       set("title","�㵴����");
       set("nickname","���Ľ�");
       set("food",250);
       set("water",250);
       set("chat_chance", 6);
	set("chat_msg", ({
		"��,����˵�������⸽����ʧ��,�����Ҳ���!\n",
	}));
set_skill("luoyan-jianfa",280);
	set("mingwang", 2000);
       set_skill("literate",150);
       set_skill("unarmed", 160);
	set_skill("sword", 160);
	set_skill("parry", 160);
        set("shen_type",1);
	set_skill("dodge", 160);
       set_skill("force", 160);
set_skill("cuff", 120);
set("combat_exp", 10000000);
set_skill("jueqing-bian",280);
set_skill("chilian-shenzhang",280);
set_skill("tiexian-quan",280);
set_skill("kongshoudao",280);
set_skill("doomstrike",280);
set_skill("fy-sword",380);
set_skill("bloodystrike",280);
set_skill("meihua-shou",280);
       set_skill("nei-bagua",180);
       set_skill("wai-bagua",180);
       set_skill("bagua-bu",180);

                set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",15000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("combat_exp", 10000000); 
        set_skill("yiqiforce",280);
        map_skill("unarmed","tiexian-quan");
        map_skill("sword","fy-sword");
        map_skill("force","yiqiforce");
        map_skill("parry","yiqiforce");
        map_skill("dodge","bagua-bu");
   create_family("�㵴��",2,"����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
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

        command("recruit "+ob->query("id") );

}
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����а", ({ "hua wuxie","girl", "dizi" }));
	set("age", 22);
	set("gender", "Ů��");
	set("attitude", "peaceful");
	set("str", 34);
	set("per", 26);
       set("title","�㵴����");
       set("nickname","���Ľ�");
set("combat_exp", 1000000);
	set_skill("literate",150);
	set_skill("unarmed", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("sword", 160);
	set_skill("force", 160);
set_skill("yiqiforce",380);
set_skill("luoriquan",380);
set_skill("luoyan-jianfa",280);
set_skill("kuangfeng-blade",380);
set_skill("qinnashou",380);
set_skill("cuff", 120);
set_skill("doomsword",380);
       set_skill("nei-bagua",180);
       set_skill("wai-bagua",180);
       set_skill("bagua-bu",180);

  set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",15000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("combat_exp", 10000000); 
        set_skill("taixuan-gong",280);
        map_skill("unarmed","luoriquan");
        map_skill("sword","doomsword");
        map_skill("force","yiqiforce");
        map_skill("parry","yiqiforce");
        map_skill("dodge","bagua-bu");

create_family("�㵴��",2,"����");
    set("chat_chance", 7);
	set("chat_msg", ({
		"��������,��Ҳ���޿��κ�!\n",
		
	}));
	setup();
       add_money("silver",60);
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
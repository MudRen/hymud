inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("л��", ({ "xie lin","girl", "dizi" }));
	set("age", 16);
	set("gender", "Ů��");
	set("attitude", "peaceful");
       set("title","�㵴Сʦ��");
	set("str", 34);
	set("dex", 36);
	set("combat_exp", 10000);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("force", 60);
set_skill("thunderwhip",380);
set_skill("cloudstaff",380);
set_skill("deisword",380);
set_skill("shortsong-blade",380);
set_skill("pangu-hammer",380);
set_skill("ill-quan",280);
        set("shen_type",1);
                set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",15000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("combat_exp", 10000000); 
        set_skill("yiqiforce",280);
        map_skill("unarmed","ill-quan");
        map_skill("sword","deisword");
        map_skill("force","yiqiforce");
        map_skill("parry","yiqiforce");
set_skill("luoyan-jianfa",280);
   create_family("�㵴��",3,"����");
	set("inquiry", ([
		"��" : "����ʦ��������,��......",
		"flower" : "����ʦ��������,��......",
		]) );	
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",5);
	carry_object(__DIR__"obj/hongmeigui");
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
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "tie qiaosan", "tie"}) );
set("title","�㵴����");
        set("gender", "����");
set("nickname","���콣");
	set("age", 46);
	set("str", 30);
	set("cor", 30);
	set("cps", 33);
 	set("int", 30);
	
	set("shen_type", 4);

	set("max_force", 5000);
	set("force", 5000);
	set("force_factor", 50);
set_skill("luoyan-jianfa",280);
        set("attitude", "peaceful");
        set("combat_exp", 10000000);
       set_skill("literate",150);
       set_skill("unarmed", 120);
       set_skill("cuff", 120);
	set_skill("sword", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
       set_skill("force", 120);
 
 set_skill("pofeng-strike",380);
set_skill("yunwu-strike",380);
set_skill("bai-quan",380);
set_skill("blood-sword",380);
set_skill("bat-blade",380);
set_skill("yiqiforce",280);
        set_skill("nei-bagua",180);
       set_skill("wai-bagua",180);
       set_skill("bagua-bu",180);

        set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",15000);
        set("neili", 10000);
        set("max_neili", 10000);
                set("max_qi",5000);
        set("max_jing",5000);
        set("max_sen",15000);
        set("neili", 10000);
        set("max_neili", 10000);
        set_skill("yiqiforce",280);
        map_skill("unarmed","bai-quan");
        map_skill("sword","blood-sword");
        map_skill("force","yiqiforce");
        map_skill("parry","yiqiforce");
        map_skill("dodge","bagua-bu");
create_family("�㵴��",2,"����");
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);
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

inherit NPC;

void create()
{
   set_name("����",({ "dao zei","dao","zei" }) );
        set("gender", "����" );
        set("age", 42);
   set("long", "����һ�������ڽ����ĵ��������ձ������Ĳ�ͷͨ����\n");
       
   set("combat_exp",100000);
   set("str", 28);
   set("per", 20);
   set("attitude", "friendly");
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set_skill("force",80);
   set("max_force",300);
   set("force",300);
   set("jiali",20);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void die()
{
	object ob;object here;
	ob=this_object()->query_temp("last_damage_from");
	if(ob->query_temp("butou_job/4"))
		ob->set_temp("butou_job_ok",1);
	return ::die();
}
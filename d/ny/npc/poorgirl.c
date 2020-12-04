
// girl.c

#include <ansi.h>
inherit NPC;
void create()
{
	string *name =({"��","��","��","��","Ǯ","��","��","��","��","��"});
        set_name(name[random(sizeof(name))]+"��", ({ "poor girl","girl" }) );
          set("shen_type",1);
        set("gender", "Ů��" );
        set("age", 15);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);

        set("attitude", "friendly");

        set("long",     "һ����ͨ��ũ��Ů�����ı��ϲ��Ÿ�����( sign )��\n");

        set("combat_exp", 1000);

        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
	(:command("say �ѵ��㲻������Ǵ����") :),
	 }) );

        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set_skill("literate", 20);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        return 0;
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say( "СŮ��˵������λ" + RANK_D->query_respect(ob)
				+ "�����������Ұɡ�����\n");
	ob->set("marks/ɱŮ",0);
}
void die()
{	int i;
	object ob,room,killer;
	if(objectp(killer= query_temp("last_damage_from")))
      {
		killer->set("marks/ɱŮ",1);
                killer->add("shen",-1000);
                }
	else 	{::die();
		 return ;}
	room=environment(this_object());
	tell_room(room,HIC "ͻȻ��������������������������������\n");
	tell_room(room,"����һ������"+killer->query("name")+"�ȵ���\n");
	tell_room(room,HIR"�󵨿�ͽ�������Т˳������Ů��Ҳ���Ź���̫�����ˣ���  ����ɱ����\n"NOR);
	tell_object(killer,HIR"������Ǵ�ˣ���������\n"NOR);
	for(i=0;i<=5;i++){
		ob=new("/obj/npc/heaven_soldier");
		ob->move(room);
		ob->kill_ob(killer);
		ob->invocation(killer);
			}
	::die();
}


#include <ansi.h>
inherit NPC;

string ask_liwu();

void create()
{
        set_name("����", ({ "hua bo","hua" }) );
 // set("title", HIM "��ʦ���˼��˰���" NOR);
	set("gender", "����" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "����һ�����ɵ����ߣ��������а�ʮ���꣬�����ϴ峤��ͽ�ܣ�
�����Ҫ���壬����������ask hua about ���壩��
\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);

	set_skill("unarmed", 1500);
	set_skill("blade", 1500);
	set_skill("parry", 1500);
	set_skill("dodge", 1500);
	set("inquiry" , ([
             "out" : (: ask_liwu :),
             "����" : (: ask_liwu :),
	]));

	setup();
	carry_object("clone/cloth/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {

			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		
	}


}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

			say( HIG"��������˵������λС�ֵܣ����Ҫ��������"+HIR+"ask hua about ����\n"NOR);


}


string ask_liwu()
{
  object me=this_player();
  int exp_bound,qn_bound,neili;

  if(!me->query_temp("isout"))
  {
   return "��ȥ���ϴ峤����к��� ask lao about ����!";
  }
 me->move("/d/city/kedian");
  return "��ѡ����ȥ���";
}

//feifei.c
inherit NPC;
void greeting(object);
void init();
void create()
{
	set_name("����", ({ "shou shou","shou" }) );
	set("gender", "����" );
	set("age", 35);
	set("long", "һ������С�ĳ�ʦ����ֻ���۾���ͣ��գ���š�\n");
	set("shen_type", -1);
	set("combat_exp", 40000);
	set("str", 20);
	set("dex", 22);
	set("con", 20);
	set("int", 21);
	set("attitude", "friendly");
	create_family("�������", 3, "����");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",10);
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
	object obn;
	if( !ob || environment(ob) != environment() ) return;
	if(((string)ob->query("family/family_name")=="�������")&&(random(3)==1))
	{say("����Ц������˵������λ" + RANK_D->query_respect(ob)
	     + "�����˰ɣ����ò͡�\n");
	if ( present("cake", ob) )
	{
		say("�㲻�Ѿ��гԵ����� ������ʲô��\n");
		return;
	}
	if ( present("jiang", ob) )
	{
		say("�㲻�Ѿ��гԵ����� ������ʲô��\n");
		return;
	}
	
	if ( present("jiuhu", ob) )
	{
		say("�㲻�Ѿ��гԵ����� ������ʲô��\n");
		return;
	}
	if ( present("niurou", ob) )
	{
		say("�㲻�Ѿ��гԵ����� ������ʲô��\n");
		return;
	}		
if (random(3)==0)
{
	     obn=new(__DIR__"obj/cake");
	     obn->move(ob);
	     obn=new(__DIR__"obj/doujiang");
	     obn->move(ob);
}
else
{
	     obn=new("/d/city/npc/obj/sniurou");
	     obn->move(ob);
	     obn->set("value",0);
	     obn=new("/d/city/npc/obj/sjiudai");
	     obn->move(ob);
obn->set("value",0);	
}
	     	   }
	else 
	     say("����С��һգ��Ц������˵������λ" + RANK_D->query_respect(ob)
	     + "��Ҫ��ʲô��??��\n");
	   return;
}
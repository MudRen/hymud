// furen.c
inherit NPC;
#include <ansi.h>
int ask_me2();
void create()
{
	set_name("ׯ����", ({ "san furen", "san","furen"}));
	set("title", "ׯ����������" );
	set("nickname", HIW "δ����" NOR);
	set("long",  "\nֻ����ԼĪ��ʮ�������,ȫ������,��ʩ֬��,��ɫ�԰�.\n");
	set("gender", "Ů��");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 5400);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50000);

	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("unarmed", 220);
	set_skill("sword", 220);
	set_skill("taiji-jian", 220);
	set_skill("tiyunzong",220);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "tiaji-jian");
	map_skill("sword", "tiaji-jian");

	set_temp("apply/attack", 35);
	set_temp("apply/attack", 35);
	set_temp("apply/damage", 35);
        set("inquiry", ([
		"����" : "�������ҼҵĴ���ˡ�",
		"�½���" :  (: ask_me2 :),
		"��֮��" :"��һ��Ҫ���������������",
		"����" :  "��������ɲ�һ��,�������ҵĺ�Ѿ��˫����",
		"˫��" :  "��СѾͷ�����Ҷ���,����Ҳ���׵���",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	object ob; 
	ob = this_player();

	if( interactive(ob) && !is_fighting() ) 
	say( "ׯ����˵�����ܾ�û��������,\n��λ" + RANK_D->query_respect(ob)
				+ "����֪�����๫��������?\n");
}

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("id") == "wu zhi rong") 
	{
	i=(int)this_player()->query("weiwang");
        if(i>=50&&i<70)
	{
	i=i+10;
	this_player()->set("weiwang",i);
	message_vision(HIC "\n$N�Ľ�����������ˣ�\n" NOR,me);
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(i));
	write(HIC "\nׯ���˴�ϲ��������,����!�벻����Ҳ�н���!!!\n");
        ob->die();
	}
         if(this_player()->query("weiwang")>=70)
	 {
	 write(HIC "\nׯ����˵������λ" + RANK_D->query_respect(ob)+",��˴�����,���ʵ��֪����Ϊ��.\n");
	 write(HIC "�����Ͷ���һ������,������ȴ����.\n");
	 }
        }		
	if ( (string)ob->query("name") == "��ʷ����") 
	{
	 write(HIC "\nׯ����˵������λ" + RANK_D->query_respect(ob)+",��л��.\n");
	 write(HIC "��,��Ҫ�ܰ����ҵ���֮���⹷���ͺ���.\n");
        }		
	if ( (string)ob->query("name") == "ׯ�ʳ�") 
	{
	 write(HIC "\nׯ����˵������λ" + RANK_D->query_respect(ob)+",��л��.\n");
	 write(HIC "��,��Ҫ�ܰ����ҵ���֮���⹷���ͺ���.\n");
        }		
 return 1;
}

int ask_me2()
{
	int i;
        object fang;
	object who = this_player();
	object where = environment(who);
	
		  	if(((int)who->query("jinyong/book7")!=1))
	{
		message_vision("$N��$n˵���� ����˳��ܶ�������?\n",this_object(),who);
		return 1;	
	}

		  	if(!(int)who->query_temp("book721"))
	{
		message_vision("$N��$n˵���� ����˳��ܶ�������?\n",this_object(),who);
		return 1;	
	}


		  	if((int)who->query_temp("book722")<=5)
	{
		message_vision("$N��$n˵���� ����ҶԸ����Ҽҵ�������������?\n",this_object(),who);
		return 1;	
	}

		  	if(!(int)who->query_temp("book723"))
	{
		message_vision("$N��$n˵���� ����ҶԸ����Ҽҵ�����������?\n",this_object(),who);
		return 1;	
	}
	
        if( who->is_fighting())
        {
		message_vision("$N��$n˵���� �������˵�ɣ�\n",this_object(),who);
		return 1;	
	}
	

		
		
  
 

if(((int)who->query("jinyong/book7")==1))
{
	
	i = 400+random(800);
	who->set("jinyong/book7",2);
	who->add("combat_exp",i+10880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+10880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();	
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� ��л ���Ҹ�������ﻵ�ˡ�\n",this_object(),who);
	message_vision("$N��$n˵���� ����ׯ�ʳǱ�ץ�� �ܰ��Ҿȳ�����?\n",this_object(),who);
	message_vision("$N��$n˵���� ���ݻ��� ��Ϊ��������?\n",this_object(),who);

}
	//call_out("destroying", 0); 
	//this_object()->kill_ob(who);
	return 1;
}
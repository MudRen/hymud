// azi.c ����

inherit NPC;
inherit F_MASTER;


int ask_me();
void create()
{
	set_name("����", ({ "azi" }));
	set("nickname", "������Сʦ��");
	set("long", 
		"�����Ƕ�������Ӱ��ϡ�\n"
		"������������������������͸��һ��а����\n");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_qi", 5300);
	set("max_jing", 5300);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 10);
	set("combat_exp", 150000);
	set("score", 10000);

	set_skill("force", 140);
//	set_skill("huagong-dafa", 25);
	set_skill("dodge", 130);
	set_skill("zhaixinggong", 140);
	set_skill("strike", 130);
	set_skill("chousui-zhang", 240);
	set_skill("claw", 130);
	set_skill("sanyin-wugongzhao", 220);
	set_skill("parry", 120);
	set_skill("poison", 120);
	set_skill("staff", 120);
	set_skill("tianshan-zhang", 180);
	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "tianshan-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	        set("inquiry", ([
                "����" : (: ask_me :),
        ]) );
	create_family("������", 2, "����");

	setup();
	carry_object("/d/xingxiu/obj/xxqingxin-san");
	carry_object("/d/xingxiu/obj/xxqingxin-san");
}

void attempt_apprentice(object ob)
{
	command("say �ðɣ��Ҿ��������ˡ�");
	command("recruit " + ob->query("id"));
}


int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);


	  	if(!who->query_temp("killtlbb101"))
	{
		message_vision("$N��$n˵���� ��������˵��Щ�¡�\n",this_object(),who);
		 
		return 1;	
	}


	  	if(((int)who->query("jinyong/book4")!=9))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}	


	
	who->set_temp("killtlbb10",1);
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� ������������ǵĻʹ������ˣ���������˺ܶ����ָ��֡�\n",this_object(),who);
                   
	return 1;
}
// Last Modified by Sir on May. 22 2001
// yi.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <command.h>
#include "hengshan.h";
string ask_for_join();
string ask_me();
void create()
{
	set_name("����ʦ̫", ({ "dingyi shitai", "shitai", "dingyi" }) );
	set("long", 
	"���Ǻ�ɽ�ɵĶ���ʦ̫���Ը���ͣ�Ϊ����ֱ���н���������ü֮�硣\n"
	"�����о������䣬���ް����̬��\n");
	set("gender", "Ů��");
	set("class", "bonze");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("inquiry",([
		"���"  : (: ask_for_join :),
		"����"  : (: ask_for_join :),
		"join"  : (: ask_for_join :),
		"�ؼ�"  : (: ask_me :),
		"�ַ���Ҫ" : (: ask_me :),
		"����"  : "��ɽ���ӣ����ܻ��ס�",
	]));
	set("env/wimpy", 60);	
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "whip.lei" :),
		(: perform_action, "whip.wang" :),	
		(: perform_action, "whip.wyly" :),
	(: perform_action, "dodge.lingxu" :),					
(: exert_function, "shield" :),
(: exert_function, "powerup" :),	
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
	}));


	set("max_qi", 24000);
	set("max_jing", 22000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 7500000);
	set("score", 1000);
	set("book_count", 1);
	
	set_skill("unarmed", 200);
	set_skill("sword", 280);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("strike", 180);
	set_skill("hand", 150);
	set_skill("buddhism", 250);
	set_skill("baiyun-xinfa",380);	
	set_skill("hengshan-jian", 350);
	set_skill("chuanyun-shou",350);
	set_skill("tianchang-zhang",350); 
	set_skill("lingxu-bu", 350);
	set_skill("literate", 100);
	set_skill("whip",320); 
	set_skill("rousi-whip",388); 
	set_skill("canxin-jian",188); 
	
	map_skill("force","baiyun-xinfa");
	//map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	//map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");
	map_skill("whip", "rousi-whip");
	map_skill("parry", "rousi-whip");
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	create_family("��ɽ��", 13, "����");
	setup();

	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
	string name, new_name;

	if ((string)ob->query("class")!="bonze" )
	{
		command ("say �����ӷ�ƶ�᲻���׼ҵ��ӡ�");
		return;
	}
	
	if ((int)ob->query_skill("baiyun-xinfa",1) < 90 )
	{
		command("say ��ı����ڹ��ķ������,�������Ը�������书��");
		return;
	}
	if ((int)ob->query("shen")<100000) 
	{
		command( "say �����ܶ�Ϊ����֮�٣����ܳ����²���\n");
		return;
	}

	command("say �����ӷ����գ����գ��ðɣ��Ҿ��������ˡ�");
	command("say ϣ������Ŭ�����ƣ��ö��������Թ���Һ�ɽ�ɡ�");
	command("recruit " + ob->query("id"));
	name = ob->query("name");
	new_name = "��" + name[2..3];
	command("say �ӽ��Ժ���ķ�������" + new_name + "��");	
	ob->set("name", new_name);
}

string ask_me()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="��ɽ��")
		return RANK_D->query_respect(this_player()) +
		"�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count") < 1)
		return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new("/clone/book/basic_hand_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ��ַ���Ҫ����\n");
	return "�ðɣ��Ȿ���ַ���Ҫ�����û�ȥ�ú����С�";
}
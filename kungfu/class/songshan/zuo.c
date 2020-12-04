// zuo.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string ask_book();
string ask_book1();
void create()
{
	int i=random(2);
	set_name("������", ({ "zuo lengchan", "zuo" }) );
	set("title", HIR"������������"HIY"��ɽ�ɵ�ʮ������"NOR);
	set("gender", "����");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 22400);
	set("max_neili", 22400);
	set("jiali", 230);
	set("max_qi",22000);
	set("max_jing",21200);
	set("combat_exp", 8000000);
	set("shen", -200000);
	set("book_count", 1);
	set("book_count1", 1);

	set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);

	set_skill("construction", 380);
	set_skill("painting", 380);


	        set_skill("songshan-sword", 380);
        set_skill("songshan-jian", 380);
        set_skill("songshan-qigong", 380);
        set_skill("dodge", 290);
        set_skill("zhongyuefeng", 380);
        set_skill("strike", 290);
        //set_skill("songyang-zhang", 380);
        set_skill("hanbing-zhenqi", 380);
        set_skill("parry", 290);
        set_skill("sword", 290);
        set_skill("songshan-jian", 380);
        //set_skill("songyang-zhang", 380);
        //set_skill("songyang-shou", 380);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 380);
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_skill("songshan-sword", 380);
	set_skill("songyang-strike", 380);
	set_skill("poyun-hand", 380);
	set_skill("hanbing-zhenqi", 388);
	set_skill("fuguanglueying", 380);

set_skill("taoism", 388);
set_skill("club", 388);
set_skill("wuyue-spear", 388);
	set_skill("luoyan-jian", 200);
	set_skill("shiba-pan", 200);
	set_skill("songshan-jian", 200);
	set_skill("liuhe-dao", 200);
	set_skill("hengshan-jian", 200);


	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	if (i==0)
	{
	map_skill("sword", "songshan-sword");
map_skill("parry", "songshan-sword");
}
else
	{
		map_skill("club", "wuyue-spear");
map_skill("parry", "wuyue-spear");
	}
	
	
	map_skill("dodge", "zhongyuefeng");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");

	set("no_get",1);
	set("chat_chance_combat", 99);
	set("chat_msg_combat", ({
		(: command("haha") :),
//		(: command("unwield sword") :),
//		(: command("wield sword") :),
(: perform_action, "club.buhui" :),
(: perform_action, "club.fengchan" :),
(: perform_action, "club.qianghun" :),		
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "strike.junji" :),	
		(: perform_action, "hand.chanyun" :),
    (: perform_action, "dodge.feng" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),	
			(: exert_function, "fenglei" :),	
	}) );
	set("inquiry",([
		"�ؼ�"	     : (: ask_book :),
		"����"	     : (: ask_book :),
		"����������" : (: ask_book :),
		"����"	     : (: ask_book1 :),
		"��ɽ����"   : (: ask_book1 :),
	]));

	create_family("��ɽ��", 13, "����");
	setup();
if (i==0)
{
carry_object(__DIR__"kuojian")->wield();
}
else
{
	carry_object(__DIR__"clubok")->wield();
}		
	carry_object(__DIR__"obj/yellow-cloth")->wear();
		carry_object(__DIR__"obj/book");
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	command("say ����Ϊ������������������������������ɽһ�ɡ�");
	command("recruit " + ob->query("id"));
}

string ask_book()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="��ɽ��")
		return RANK_D->query_respect(this_player()) +
		"�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count") < 1) return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count", -1);
	ob = new(__DIR__"songyang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ���������������\n");
	return "�ðɣ��Ȿ�����������ס����û�ȥ�ú����С�";
}

string ask_book1()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="��ɽ��")
		return RANK_D->query_respect(this_player()) +
		"�뱾�ɺ��޹ϸ����ɵ��书�伮�ɲ��ܽ����㡣";
	if (query("book_count1") < 1) return "�������ˣ����ɵ��ؼ����ڴ˴���";
	add("book_count1", -1);
	ob = new(__DIR__"sword_book4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ���ɽ��������\n");
	return "�ðɣ��Ȿ����ɽ���ס����û�ȥ�ú����С�";
}

// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int auto_perform();
int ask_youming();
int ask_guizhao();

void create()
{
	set_name("����ˮ", ({ "li qiushui", "li", "qiushui" }));
	set("long",
	    "�����Ű�ɫ����������������ȣ��������˿�׳��Ʋ��������ݡ�\n");
	set("title", "���Ĺ���̫��");
	set("gender", "Ů��");
	set("per", 13);
	set("age", 80);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 30);
set("per", 30);
	set("max_qi", 39000);
	set("max_jing", 39200);
	set("neili", 57500);
	set("max_neili", 57500);
	set("jiali", 100);
        set("level", 60);
	set("combat_exp", 5500000);

	set_skill("force", 350);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("hand",350);
	set_skill("strike", 350);
	set_skill("sword",350);
	set_skill("blade",350);
	set_skill("literate",100);
	set_skill("martial-cognize",350);
	set_skill("claw",380);

	set_skill("youming-guizhao",380);
	set_skill("zhemei-shou",350);
	set_skill("liuyang-zhang",350);
	set_skill("tianyu-qijian",350);
	set_skill("yueying-wubu",350);
	set_skill("bahuang-gong", 350);
	set_skill("lingboweibu", 350);
set("pubmaster",1);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "youming-guizhao");
	map_skill("sword", "tianyu-qijian");
	map_skill("claw", "youming-guizhao");

	prepare_skill("claw", "youming-guizhao");
       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                	(: exert_function, "shield" :),
                	(: exert_function, "dunzun" :),	
                        (: perform_action, "claw.guizhao" :),
                (: perform_action, "claw.youming" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),
                (: perform_action, "dodge.break" :),
                (: perform_action, "dodge.lingbo" :),                
        }));
	set("inquiry", ([
		"��ڤ��צ" : (: ask_youming :),
		"�����צ" : (: ask_guizhao :),
	]));

	create_family("���չ�", 1, "����");

	set("master_ob",4);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	object ob = this_player();

	::init();
	if (ob->query_skill("beiming-shengong") && ob->query("id") != "xiaoyao zi" || 
		ob->query_skill("lingbo-weibu") && ob->query("id") != "xiaoyao zi" ) 
	{
		message_vision(HIY "$NͻȻ��$n�ȵ�������������ɣ�\n"NOR, this_object(), ob );
		kill_ob(ob);
        }
}

int ask_youming()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "���չ�"  && ob->query("family/family_name") != "��ң��")
        	 {
                command("sneer");
                command("say ʦ��ȴ��֪����������ڤ��צ�������չػ�֮ͯʱҪ�����ܵ��ͷ��");
                return 1;
        }
        
        if (ob->query("family/master_name") == "��ɽͯ��") {
                command("say ʦ��������͵ѧ�ҵ���ڤ��צ���Ǿ������ʶ��ʶ��");
                kill_ob(ob);
                return 1;
        }     
        if (ob->query("can_learn/li/youming-guizhao")) {
                command("say �Ҳ����Ѿ���ʼ������ô��");
                return 1;
        }
        if (ob->query_skill("claw", 1) < 99) {
                command("say Ҫʹ���������书��Ҫ�����צ�����㻹�Ƕ���ϰ��ϰ��˵�ɡ�");
                return 1;
        }
        
        command("say �ã��Ҿͽ������ס���ڤ��צ�����������ҶԸ��Ǹ����ˣ�\n");
        ob->set_temp("can_learn/li/youming-guizhao", 1);
        return 1;
}

int ask_guizhao()
{
        object ob = this_player();
        
        if (ob->query("family/family_name") != "���չ�") {
                command("sneer");
                command("say ʦ��ȴ��֪����������ڤ��צ�������չػ�֮ͯʱҪ�����ܵ��ͷ��");
                return 1;
        }
        if (ob->query("family/master_name") == "��ɽͯ��") {
                command("say ʦ��������͵ѧ�ҵ���ڤ��צ���Ǿ������ʶ��ʶ��");
                kill_ob(ob);
                return 1;
        }     
        if (!ob->query("can_learn/li/youming-guizhao")) {
                command("say ˭������͵ѧ���书�ģ�");
                return 1;
        }
        if (ob->query_skill("claw", 1) < 180) {
                command("say Ҫʹ�������ľ�����Ҫ�����צ�����㻹�Ƕ���ϰ��ϰ��˵�ɡ�");
                return 1;
        }
        if (ob->query_skill("youming-guizhao", 1) < 180) {
                command("say Ҫʹ�������ľ�����Ҫ�����צ�����㻹�Ƕ���ϰ��ϰ����ڤ��צ����˵�ɡ�");
                return 1;
        }

        command("say �ã��Ҿͽ���һʽ�������צ�����������ҶԸ��Ǹ����ˣ�\n");
        //ob->set("can_perform/youming-guizhao/guizhao", 1);
        tell_object(ob, "��ѧ���������צ��\n");
        return 1;
}

int recognize_apprentice(object ob, string skill)
{

        if (ob->query("family/family_name") != "���չ�"  && ob->query("family/family_name") != "��ң��")
        {
                //command("bite");
                command("say ������������ѧ�����ҵ��书");
                return 0;
        }
        if (! ob->query_temp("can_learn/li/youming-guizhao"))
        {
                command("say �Ҵ�Ӧ����������");
                return 0;
        }     


        return 1;
}
void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") == "���չ�")
{

        command("say �Ҿ�������ɣ���һ��Ҫ����ɱ���Ǹ����ˡ�");
        command("recruit " + ob->query("id"));
}
} 
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	
  	if (!who) return;


  	if(who->query_temp("lingjiujobkill") && !query("iskillok1"))
	{
      message_vision(HIR"$N˵���������� ������ˣ���Ҫ����.....\n" NOR,this_object());
      message_vision(HIR"$Nҧ����⣬�³�һ����Ѫ...�־��������ˡ�\n" NOR,this_object());
	who->start_busy(6);
	this_object()->set("qi", 59000);
	this_object()->set("eff_qi", 59000);
	this_object()->set("max_qi", 59000);
	this_object()->set("jing", 59200);
	this_object()->set("max_jing", 59200);
	this_object()->set("neili", 57500);
	this_object()->set("max_neili", 57500);
     this_object()->set("iskillok1",1);
     set("iskillok1",1);	
     this_object()->kill_ob(who);
     who->kill_ob(this_object());
	return;
	}
  	if(((int)who->query("jinyong/book4")>=8) || !who->query_temp("lingjiujobkill"))
	{
//::die();	
	}
        else if(who) {
        	message_vision(RED"$N˵���������� ������ˣ���Ҫ����.....\n"NOR NOR,this_object());
		i = 500+random(2000);
		who->set("jinyong/book4",8);
		who->add("combat_exp",i+25000);
		who->add("potential",i*25);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+25000)+"�㾭��"+
		           chinese_number(i*45)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
        }
	::die();
}
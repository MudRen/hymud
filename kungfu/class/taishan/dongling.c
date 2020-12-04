// Last Modified by winder on Aug. 25 2001
// tianmen.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	 int i=random(2);
	set_name("�������", ({ "dongling daoren", "daoren", "dongling" }) );
	set("gender", "����");
	set("title", HIG"̩ɽ�ɵ�ʮһ������"NOR);
	set("class", "taoist");
	set("age", 85);
	set("attitude", "peaceful");
	set("str", 36);
	set("con", 30);
	set("dex", 30);
	set("int", 38);

	set("neili", 50000);
	set("max_neili", 50000);
	set("max_qi", 28000);
	set("max_jing", 28000);
	set("combat_exp", 9000000);
	set("shen_type", 1);

	set_skill("strike", 250);
	set_skill("kuaihuo-strike", 380);
	set_skill("sword", 380);
	set_skill("taishan-sword", 380);
	set_skill("shiba-pan", 380);
	set_skill("force", 250);
	set_skill("panshi-shengong", 390);
	set_skill("parry", 250);
	set_skill("taoism", 380);
	set_skill("blade", 380);	
set_skill("aohan-liujue", 388);	
set_skill("yujianshu", 388);		
	set_skill("dodge", 250);
	set_skill("fengshenjue", 390);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
if (i==0)
{
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
}

else
{
	map_skill("blade", "aohan-liujue");
	map_skill("parry", "aohan-liujue");
	
}	
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 99);
	set("chat_msg_combat", ({
		(: perform_action, "blade.baoxue" :),
		(: perform_action, "blade.bingxue" :),
		(: perform_action, "sword.txyx" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.huan" :),
		(: perform_action, "sword.jue" :),
		(: perform_action, "dodge.fengshen" :),	
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "shield" :),
		(: exert_function, "powerup" :),
		(: exert_function, "invocation" :),
		(: exert_function, "taijitu" :),
	}) );

	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",500);
	
	create_family("̩ɽ��", 11, "��ʦ");
	setup();

if (i==0)
{
	carry_object(__DIR__"houjian")->wield();
}
else
{
	carry_object("/clone/weapon/gangdao")->wield();	
}	
	carry_object(__DIR__"daopao")->wear();
	}





void attempt_apprentice(object ob)
{
	if((int)ob->query("shen")<550000)
	command("say ��̩ɽ�ɵ��Ӷ�����������֮����"+RANK_D->query_respect(ob)+"�����Ĳ�������");
	else
		if((int)ob->query_skill("panshi-shengong",1) < 300)
			command("say ��ı����ķ����ö����ϰ��");
	else
		if((int)ob->query_skill("taishan-sword",1) < 300)
			command("say ���̩ɽ�������ö����ϰ��");
		else
		{
			command("say �ð������Ҿ�������ɡ�");
			command("recruit " + ob->query("id") );
		}
}


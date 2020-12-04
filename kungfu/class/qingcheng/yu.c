// yu.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	int i=random(2);
	set_name("��׺�", ({ "yu canghai", "yu", "canghai" }));
	set("gender", "����");
	set("age", 52);
	set("long", "�����ΰ�С�������������أ�ٲȻһ�ɴ���ʦ����\n");
	set("class", "taoist");
	set("combat_exp", 8000000);
	set("class", "taoist");
	set("shen_type", -1);
	set("max_neili", 22500);
	set("neili", 22500);
	set("max_jing", 21500);
	set("max_qi", 22500);
	set("jiali", 250);
	set("apprentice_available", 3);
  set_skill("taoism",380);
  set_skill("hammer",380);
  set_skill("frht-hammer",380);
	set_skill("sword", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike", 250);
	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("hammer", 250);
	set_skill("throwing", 350);
	set_skill("literate", 100);
//	set_skill("qingzi9da", 150);
	set_skill("qingzi9da", 380);
	set_skill("liuhe-dao", 380);
//	set_skill("chengzi18po", 150);
	set_skill("chengzi18po", 380);
	set_skill("pixie-sword", 250);
	set_skill("songfeng-jian", 380);
	set_skill("chuanhua", 380);
	set_skill("wuying-leg", 380);
	set_skill("cuixin-strike", 380);
	set_skill("qingming-xuangong", 380);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	

if (i==0)
{
	map_skill("sword", "songfeng-jian");
	map_skill("parry", "songfeng-jian");
}

else
{
	map_skill("hammer", "frht-hammer");
	map_skill("parry", "frht-hammer");

}			
	
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");

	set("no_get",1);
	set("chat_chance_combat", 99);
	set("chat_msg_combat", ({		
    (: perform_action, "dodge.chuan" :),
    (: perform_action, "hammer.san" :),
 	  (: perform_action, "hammer.rimu" :),
 	  (: perform_action, "hammer.riluo" :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.dieying" :),
		(: perform_action, "strike.cuixin" :),
		(: perform_action, "unarmed.fanti" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shield" :),
		(: exert_function, "dingshen" :),
    (: exert_function, "fenshen" :),
	}) );
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	create_family("�����", 5, "����");
	setup();
if (i==0)
{
	carry_object("/clone/weapon/changjian")->wield();
}
else
{
	carry_object(__DIR__"whammer")->wield();
}		
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object(__DIR__"key");
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say ������һ��һ������");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say �ϵ������Ѿ������������ӣ���������ͽ�ˡ�");
	}
}

void do_recruit(object ob)
{
	if( (int)ob->query("int") < 20 )
		command("say ��������԰������������ҿ�"+RANK_D->query_respect(ob)+"���ʺ���ѧ������");
	else {
		command("say �ã��ܺá�");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	add("apprentice_availavble", -1);
}

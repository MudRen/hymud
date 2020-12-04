// dazongshi.c ����ʦ

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("����ʦ", ({ "da zongshi", "zongshi" }));
	set("long","�����ǽ����Ĵ���ʦ����ֻ����������ս�����ܻ�ý�������ʵ���͵�λ�ĳ��ϡ�\n");
	set("gender", "����");
	set("age", 40);
	set("class", "taoist");
	set("attitude", "friendly");
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("no_get",1);

	set("max_qi", 36000);
	set("max_jing", 33000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jingli", 100);
	set("max_jingli", 10000);
	set("tili", 100);
	set("jiali", 100);
	set("food", 400);
	set("water", 400);
	set("combat_exp", 9000000);
	set("score", 500000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
	set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 580);
	set_skill("dodge", 550);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 500);
	set_skill("taiji-quan", 580);
	set_skill("parry", 500);
	set_skill("sword", 500);
	set_skill("taiji-jian", 580);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 580);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
set("count",1);
	set_temp("apply/attack",250);
	set_temp("apply/defense",250);
	set_temp("apply/armor",500);
	set_temp("apply/damage",500);
	set("inquiry", ([
		"��ɱ" : (: ask_me :),
		"����" : (: ask_me :),
		"ɱ��" : (: ask_me :),
		"��ս" : (: ask_me :),
		"Ʒ��" : (: ask_me :),
		"�书" : (: ask_me :),
	]));
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
string ask_me()
{
	object me = this_player(), ob = this_object();

	if ( me->query("combat_exp") < 500000)
		return "����ľ���չ�����ʮ���������Ұɡ�";
	ob->set("killer/id", me->query("id"));
	ob->set("killer/time", time());
	set("eff_qi", 36000);
	set("eff_jing", 33000);
	set("qi", 36000);
	set("jing", 33000);
	set("food", 400);
	set("water", 400);
	set("neili", 55000);
	set("jiali", 100);
	command("yun powerup");
	set("neili", 55000);
	set("jiali", 100);
	return "�ðɣ��Ǿ����ɡ�";
}
void die()
{
	object *me, ob = this_object(); //,mm = this_player();
	int i, sc, new_killer;

//	sc = mm->query("score");
	me = all_inventory(environment(ob));
	for (i = 0; i < sizeof(me); i ++)
		if( me[i]->query("id") == ob->query("killer/id") )
		{
			sc = me[i]->query("score");
			new_killer = 12345/(time() - ob->query("killer/time"));
			if (me[i]->query("KILLER") >= new_killer )
			{
				tell_object(me[i],HIR"\n����ʦ����ǰ�����㣺��û�н���������һ�ˡ���\n"NOR);
			        if(me[i]->quert("zongshi_winner")<3)  me[i]->add("score", -5000);
			}
			else
			{
				tell_object(me[i],HIR"\n����ʦ����ǰ�����㣺���ã��ã��ã�û�а�����һ�ˡ���\n"NOR);
				message("channel:chat", HIM"�����ġ�ĳ�ˣ�"+me[i]->query("name")+chinese_number(time()-ob->query("killer/time"))+"���д�ɱ����ʦ�ɹ���\n"NOR, users());
				me[i]->set("KILLER", new_killer);
				me[i]->add("zongshi_winner", 1);
			        if(me[i]->quert("zongshi_winner")<3)  me[i]->add("score", 10000);
			}
		}
	::die();
}


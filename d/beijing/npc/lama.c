// lama.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����", ({"lama"}));
	set("long", "����һ���ߴ�������۴�׳��������Բ���ƺ�����������ʿ��\n");
	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "bonze");

	set("age", 20+random(30));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiaji", 50+random(50));
	set("combat_exp", 350000);
	set("score", 1);

  set_skill("lamaism", 150);
        set_skill("literate", 80);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("blade", 180);
        set_skill("sword", 120);
        set_skill("dodge", 180);
        set_skill("longxiang", 180);
        set_skill("shenkong-xing", 180);
        set_skill("hand", 180);
        set_skill("cuff", 180);
        set_skill("yujiamu-quan", 180);
        set_skill("dashou-yin", 180);
        set_skill("mingwang-jian", 120);
        set_skill("xue-dao", 180);
        set_skill("xiangmo-chu", 180);
        set_skill("magic", 180);
        set_skill("kwan-yin-spells", 180);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");
	set("chat_chance_combat", 39);  
	set("chat_msg_combat", ({
(: perform_action, "blade.resurrect" :),
(: perform_action, "blade.chi" :),
(: perform_action, "blade.shi" :),
(: perform_action, "blade.xue" :),
(: perform_action, "blade.ying" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );


	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
	object me = this_object();

	if(ob->query_temp("hastrystab")==6) return;	
	if (interactive(ob) && !environment(ob)->query("no_fight"))
	{
		if( !ob->query_temp("warned2") )
		{
			if(ob->query_temp("hastrystab")) 
				command("say �������ˣ����Ȼ�������ֵܣ�");
			else
				command( "say ����˭����Ȼ���ƻ���ү�ĺ��£���������ǲ��ǣ���");
			ob->set_temp("warned2", 1);
		}
		else
		{
			if(ob->query_temp("hastrystab")) 
				command(" say ��...��...һ��Ҫɱ�����ⱳ��ͱ�˵Ľ������࣡");
			else
				command(" say ����һﲻҪ�ܣ��÷�ү�������㣡����\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}

}

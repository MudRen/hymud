// hong.c
inherit NPC;

#include <ansi.h>
void fighting(object who);
void create()
{
	set_name("������", ({ "hong renxiong", "hong", "renxiong" }));
	set("gender", "����");
	set("nickname", HIC"�������"NOR);
	set("age", 25);
	set("long", "�����ǡ�Ӣ�ۺ��ܣ�������㡹֮һ���书ҲԶ��ͬ�š�\n");

	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 60);
	
	set("combat_exp", 3000000);
	set("shen_type", -1);

	set_skill("sword", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("unarmed", 150);
	set_skill("force", 150);
	set_skill("pixie-sword", 150);
	set_skill("songfeng-jian", 150);
	set_skill("chuanhua", 150);
	set_skill("wuying-leg", 150);
	set_skill("cuixin-strike", 150);
	set_skill("qingming-xuangong", 150);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	map_skill("parry", "bixie-sword");
	map_skill("sword", "songfeng-jian");
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");
	
		set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.dieying" :),	
		(: perform_action, "unarmed.fanti" :),	
		(: perform_action, "strike.cuixin" :),	
	      }) );
	
	create_family("�����", 6, "����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
        object ob = this_player();

        ::init();
        if( interactive(ob) && !is_fighting() ) {
		remove_call_out("fighting");
		call_out("fighting", 1, ob);
        }
}

void fighting(object who)
{
	object where = environment(who);
	object hong = this_object();
	object linghu = present("linghu chong",where);
        if( !who || environment(who) != environment() ) return;
	if(linghu) 
	{
		hong->fight_ob(linghu);
		linghu->fight_ob(hong);
		add_action("do_quanjia", "quanjia");
	}
}

int do_quanjia()
{
	object who = this_player();
	object where = environment(who);
	object hong = this_object();
	object linghu = present("linghu chong",where);
	
	if(who->query("jinyong/book8")) return 0;

	if(hong && linghu) 
	{
		if(hong->is_fighting(linghu) && linghu->is_fighting(hong))
		{	
			message_vision("$N���һ��������λ����ס�֣���\n", who);
			linghu->remove_all_enemy();
			hong->remove_all_enemy();
			message_vision("����ֹͣ�˴򶷣��ع�ͷ������$N��\n", who);
			if (who && interactive(who)) 
				call_out ("killhong", 1, who);  
			return 1;
		}
		else
		{
			tell_object(who,"����û�˴�ܣ���Ȱʲô�ܣ�");
			return 1;
		}
	}
	else
	{
		tell_object(who,"����û�˴�ܣ���Ȱʲô�ܣ�");
		return 1;
	}	
}

void killhong(object who)
{
	object where = environment(who);
	object hong = present("hong renxiong",where);
	if(hong) 
	{
		if(!hong->is_fighting())
		{	
			message_vision("$N��ݺݵĶ�$n˵���� �Ҿ����������֮һ��$N����λ"+ RANK_D->query_respect(who) +"��Ĳ��ͷ��ˣ�����������ɵ��£�\n",hong,who);
			hong->set("qi", 10000);
			hong->set("max_qi", 10000);
			hong->set("jing", 10000);
			hong->set("max_jing", 10000);
			hong->set("neili", 10000);
			hong->kill_ob(who);
		}
	}
}
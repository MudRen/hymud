// shisong.c ʷ��

inherit NPC;
//inherit F_SKILL;
#include <ansi.h>
void create()
{
	set_name("ʷ��", ({ "shi song", "shi", "song" }));
	set("gender", "����");
	set("title", "������");
	set("age", 35);
	set("str", 25);
	set("dex", 20);
	set("long", "����һ����׳���ӣ�����ģ��������Χһ�����ޡ�\n");
	set("combat_exp", 45000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("startroom","/d/city/dujiangqiao");

set_skill("unarmed", 290);
	set_skill("force", 280);
	set_skill("dodge", 200);
	set_skill("whip",230);
	set_skill("chilian-shenzhang",300);
	set_skill("jueqing-bian",300);
	set_skill("taiji-shengong",150);
	map_skill("force", "taiji-shengong");
	map_skill("whip", "jueqing-bian");
	map_skill("strike", "chilian-shenzhang");
	map_skill("parry", "chilian-shenzhang");
	map_skill("force", "taiji-shengong");
        prepare_skill("strike","chilian-shenzhang");

	set("jiali",50);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "whip.sanwu" :),
        }) );

	set("combat_exp", 895000);

	set("qi", 11500);
	set("jing", 11000);
	set("max_qi", 11500);
	set("max_jing", 11000);
	set("neili", 35000);
	set("max_neili", 35000);


	set("jiali", 5);
	set("chat_chance", 15);
	set("chat_msg", ({
		"ʷ��һ���������ޣ�˵��:���º�����ʷ�ɣ������ٱ����\n"
		"������ػᷴ����\n" ,
		"ʷ�ɴ��: ���ˣ����ˣ�ͨͨ�������£� \n",
		"ʷ��˵��: ���ٱ��������£��书���������ڱ�������һȭ\n"
		"����һͷ��ţ����ƾ��Ҳ������ٱ����֣�\n" ,
		(: random_move :)
	}) );
	setup();
	carry_object("/clone/armor/junfu")->wear();
	carry_object("/d/beijing/obj/hlbian")->wield();
	add_money("silver",3);
}

void init()
{
	object me, ob;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) && !environment(ob)->query("no_fight") &&
		(ob->query("combat_exp") > 10000) &&
		( ob->query("party/party_name") == HIR "��ػ�" NOR ))
	{
		command("say �������ػᷴ�����������ɣ�����\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}

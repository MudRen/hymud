// shanfei.c

inherit NPC;

int is_paiyun() { return 1;}

void create()
{
	set_name("ɽ��", ({ "shan fei" }) );
	set("long", "����һλ�����ײ�֮����ɽ�ˡ�\n");

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_sen", 1000);
	set("max_neili",2500);
	set("neili",2500);
	set("force_factor",50);
	set("str", 30);
	set("cor", 30);
	set("kar", 35);
	set("combat_exp", 900000);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :),
	}) );

	set_skill("club", 100);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("unarmed", 150);

	setup();

	carry_object(__DIR__"obj/armor")->wear();
	carry_object(__DIR__"obj/spear")->wield();
}

int accept_kill(object me)
{
	object *obs;

	if(!environment())
		return 0;

	say("ɽ�˺ݺݵ�˵����ү������û�����⣬�춼�������ˣ�\n");

	obs = filter_array(all_inventory(environment()) - ({this_object()}),(: $1->is_paiyun() :));

	if(sizeof(obs))
		obs->kill_ob(me);
	return 1;
}

int accept_fight(object me)
{
	object *obs;

	if(!environment())
		return 0;

	say("ɽ�˺ݺݵ�˵����ү������û�����⣬�춼�������ˣ�\n");

	obs = filter_array(all_inventory(environment()) - ({this_object()}),(: $1->is_paiyun() :));

	if(sizeof(obs))
		obs->kill_ob(me);
	kill_ob(me);
	return 1;
}

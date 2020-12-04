// huananhu.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
	set_name("���ϻ�", ({ "huanan hu", "tiger","hu" }) );
	set("race", "Ұ��");
	set("age", 20);
	set("long", @LONG
һֻ�ý������ͻ�����ΰ���ˡ�


    ("`-''-/").___..--''"`-.
     `@_ @ )   `-.  (  *  ).`-.__.`)
     (_Y_.)'  ._   )  `._ `. ``-..-'
      _..`--'_..-_/  /--'_.' ,'
    (il),-''  (li),'  ((!.-'


LONG);
	set("attitude", "aggressive");
	set("shen_type", -1);
	set("combat_exp", 300000);
	set("neili",8000);
	set("jiali",1000);
	set("max_neili",8000);
  	set("jingli",5000);
	set("max_jingli",5000);
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���" }) );
	set("verbs", ({ "bite", "claw" }) );
	        set("dex",20+random(100));

	set_skill("parry",30+random(300));
set_skill("unarmed",30+random(300));
	set("max_neili",900+random(8550));
	set("max_jing",900+random(8550));
		set("max_qi",900+random(8550));
	set_skill("dodge",30+random(300));
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 300);
	set_temp("apply/armor", 100);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"�ϻ��ڿ�Ѳ���ŵ�����������ҳ���\n",
		"�ϻ����쳤Х������ɽ�ȣ���Ҷ��׹��\n",
	}) );
}

void init()
{	
	object ob; 

	ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (ob->query_dex()<20 && !this_object()->query_temp("owner"))
	{
		message_vision( "ֻ������һ���硣
ֻ�������������˵�һ���죬����һֻ�����׶�������
�Ǵ���ֶ����ֿʣ�����ֻצ�ڵ����԰�һ������������һ�ˣ��Ӱ����ߥ��������\n",ob);
		message_vision("$N��һ��û�ж㿪��Ϊ���������˹�ȥ��\n\n",ob);
		ob->receive_wound("qi",20);
		ob->start_busy(2);
		this_object()->kill_ob(ob);
	}
}

void die()
{
	object ob, corpse;
	message_vision("$N�������춯�ص�һ����Х����ص��ڵ��ϣ����ˣ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	//ob = new("/clone/medicine/vegetable/hugu");
	//ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
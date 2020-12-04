#include <ansi.h>

inherit BOSS;
int boss_attack();
int boss_attack2();
int hurting();
int hurting1();
int hurting2();
int boss_hurting();
int boss_hurt();
int boss_init();
int boss_removedam();

void create()
{
	set_name( HIY "Ӣ��" NOR, ({ "ying zhao", "shenshou", "boss" }) );
	set("long", HIY "���������л��ƣ���������������"
		"�ų�������ۿ���԰���񣬵�������������������ֻ���޶��ѡ�\n\n" NOR);
set("nickname",HIR"�Ϲ�����"NOR);	
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 3000);
	set("no_get", 1);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set("dex",400);
	set("con",400);
	set("int",400);
	set("str",400);
	
	set("combat_exp", 100000000);
	set("level", 18);
		set("qi", 3500000);
		set("max_qi", 3500000);
		set("jing", 3500000);
		set("max_jing", 3500000);
		set("neili", 3000000);
		set("max_neili", 3000000);
		set("jiali", 20000);
	
	set_skill("dodge", 1200);
	set_skill("force", 1200);
	set_skill("unarmed", 1200);
	set_skill("dragon",1250);
	set_skill("spells",1250);
	set_skill("magic-old",1250);
	map_skill("unarmed", "dragon");
	set("vendetta/authority",1);
	map_skill("dodge", "dragon");
	map_skill("spells", "magic-old");
	      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.penhuo" :),
		(: perform_action, "unarmed.tuwu" :),
		(: perform_action, "unarmed.yaoyao" :),
			(: boss_attack2 :),
			(: boss_attack2 :),
			(: boss_attack2 :),

	}));
			set_temp("bossdamage",0);
	set_temp("apply/dodge", 200);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 6600);
	set_temp("apply/armor", 6600);
	set_temp("apply/defence",200);
	
	// ��Ʒ����
	set("bonus", random(15000)+15000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"RI&10"   :   8000,
		"GE&5"   :  8000,
		"KS&3"   :   8000,
		"BL&3"   :  8000,
		"RI&60"   :   5000,
		"GE&6"   :  5000,
		"JD&7"   :  5000,
		"YC&4"   :  5000,
		"WG&4"   :  5000,
		"KS&7"   :  2600,
		"BL&8"   :  2600,
		"YW&5"   :  2600,
		"YA&5"   :  2600,
		"TW&300"   :  2000,
		"TA&300"   :  2000,
	  "TZ&0"   :  1600,	
		"TZ&1"   :  1300,		
	]));
	
	setup();
	carry_object("/clone/money/gold")->set_amount(random(500)+100);
}


void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(2);
this_object()->delete_temp("boss_attack2");
        call_out("hunting",0);
	message_vision(HIB "$N" HIG "��Ϊ��������Ϊʳ����������Ϊ�˿����������ŵı����������ˣ��� \n" NOR, this_object());

        }
this_object()->delete_temp("boss_attack2");
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}


int boss_init()
{	
	message_vision(HIB "$N" HIG "��Ϊ��������Ϊʳ����������Ϊ�˿����������ŵı����������ˣ��� \n" NOR, this_object());
		//remove_call_out("boss_hurting");
		//call_out("boss_hurting", 3); // ÿ������һ��
		//remove_call_out("boss_attack");
		//call_out("boss_attack", 10); // ս��10���ʩ�����⼼��
//return 1;
}

int boss_attack2()
{	
if (!this_object()->query_temp("boss_attack2"))
{
message_vision(HIB "$N" HIR "����ս����̬,�Ӷ�˫��������գ��� \n" NOR, this_object());
//	remove_call_out("boss_hurt");
//call_out("boss_hurt", 3,this_object());
		remove_call_out("boss_hurting");
		call_out("boss_hurting", 3); // ÿ������һ��
		remove_call_out("boss_attack");
		call_out("boss_attack", 6); // ս��10���ʩ�����⼼��
this_object()->set_temp("boss_attack2",1);
}
	return 1;
}

int boss_hurting()
{

	if( ((int)this_object()->query("eff_qi") < (int)this_object()->query("max_qi") / 5 )||((int)this_object()->query("eff_jing") < (int)this_object()->query("max_jing") / 5 ))
	{
		//����20%��Ѫ���߾�����ʱ���
		remove_call_out("hurting2");
		call_out("hurting2", 0, this_object());
	}

	remove_call_out("boss_hurting");
	call_out("boss_hurting", 3, this_object()); // ÿ������һ��



	return 1;
}

int boss_attack()
{	
	message_vision(HIY "$N" HIY "�Ӷ�˫��������գ����������дʣ���������������� \n" NOR, this_object());
	remove_call_out("boss_hurt");
	call_out("boss_hurt", 3,this_object());
	return 1;
}

int boss_hurt()
{
	if (this_object()->is_busy()) 
	{
		//busyʱʩ������һ�ּ���

		remove_call_out("hurting1");
		call_out("hurting1", 0, this_object()); 
	}
	else
	{
		remove_call_out("hurting");
		call_out("hurting", 0,this_object());
	}
	return 1;
}

int hurting()
{
	int dam, dam1,i , num;
	object *inv;
	
	message_vision(HIY "ͻȻ�����������ת�羰ͻ�䣬����Ҳ�����˱仯"
		"����ʹ����վ��վ���ȣ���ʹʹ��ǧ��׹��Ҳ�о��챻�����ߡ�\n" NOR,
	this_object());
	
	inv = all_inventory(environment(this_object()));        
	
	num = sizeof(inv);       
	if (num < 1) num = 1;
	if (num > 5) num = 5;
	
	dam = 19000 / num;
	if (this_object()->query_temp("bossdamage")==1)
	{
		dam = dam * 2;//�⻷���ھ��˺��ӱ�
	}

	set_temp("bossdamage",1);//���к����˺��⻷���´��˺��ӱ���
	remove_call_out("boss_removedam");
	call_out("boss_removedam", 40, this_object()); 

	for (i=sizeof(inv)-1; i>=0; i--)
	{
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
		{                        
			dam1 = dam - inv[i]->query_temp("apply/reduce_damage");
			if (dam1 <0) dam1 = 0;
			inv[i]->apply_condition("new_poison3", 3);
			inv[i]->receive_damage("qi", dam1); //�����Ǽ��˵Ļ����˺����Ҳ��3000���������£�������˺��������ܣ�
			inv[i]->receive_damage("jing", dam1/3);  //�����Ǽ��˵Ļ����˺����Ҳ��1000���������£�������˺��������ܣ�����Ҫ����Ѫ��������Դ����
			inv[i]->receive_wound("qi", dam1);
			inv[i]->receive_wound("jing", dam1/3);
			COMBAT_D->report_status(inv[i], 1);
		}
	}
	//30������ʩ�����⼼��
	remove_call_out("boss_attack");
	call_out("boss_attack", 20, this_object()); 
	
	return 1;
}

int boss_removedam()
{
	set_temp("bossdamage",0);
}

int hurting1()
{
	int i , num,busy_time,busy_time1;
	object *inv;
	
	message_vision(HIR "��ʱ����������ܲ�������������ư�ô����������"
		"�����У�Ӣ��ͻȻ��һ���ɫ�⻷���֣���ĺ���ʲô�����������\n" NOR,
	this_object());
	
	inv = all_inventory(environment(this_object()));        
	
	num = sizeof(inv);       
	busy_time = 10 / num;//��ӵ���Խ�࣬busyԽ��
	
	for (i=sizeof(inv)-1; i>=0; i--)
	{
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
		{                        
			busy_time1 = busy_time -  inv[i]->query_temp("apply/reduce_busy");
			if (busy_time1>0) inv[i]->start_busy(busy_time);
		}
	}
	
	message_vision(HIB "$N" HIB "�������£����ϵĹ⻷�ƺ��ָֻ���������ս�������� \n" NOR, this_object());
	//�ָ�%2��״̬
        this_object()->receive_curing("qi", this_object()->query("max_qi")/100);
        this_object()->receive_curing("jing", this_object()->query("max_jing")/100);

	//30������ʩ�����⼼��
	remove_call_out("boss_attack");
	call_out("boss_attack", 30, this_object()); 
	
	return 1;
}

int hurting2()
{
	int i , num;
	object *inv;
	
	inv = all_inventory(environment(this_object()));        
	//this_object()->delete_temp("boss_hurting");
	message_vision(HIY "$N" HIY "�𽥿�ʼ���ͷ��ˣ�����������������Լ���������һ��һ����ʧ���� \n" NOR, this_object());
	//��ģʽ��ÿ�����10%
	for (i=sizeof(inv)-1; i>=0; i--)
	{
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
		{                       
			inv[i]->apply_condition("new_poison3", 3);
			inv[i]->receive_damage("qi", inv[i]->query("max_qi")/10); 
			inv[i]->receive_damage("jing", inv[i]->query("max_jing")/10);  
			inv[i]->receive_wound("qi", inv[i]->query("max_qi")/10);
			inv[i]->receive_wound("jing", inv[i]->query("max_jing")/10);	
			//�й⻷�˺��ӱ���
			if (this_object()->query_temp("bossdamage")==1)
			{
				inv[i]->receive_damage("qi", inv[i]->query("max_qi")/10); 
				inv[i]->receive_damage("jing", inv[i]->query("max_jing")/10);  
				inv[i]->receive_wound("qi", inv[i]->query("max_qi")/10);
				inv[i]->receive_wound("jing", inv[i]->query("max_jing")/10);	
			}
		}
	}	
	return 1;
}

int hit_ob(object me, object ob, int damage)
{
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
        ob->apply_condition("new_poison3", 3);
        tell_object(ob, HIR "����ñ����еĵط�����һ��⻪��\n" NOR );
}
}

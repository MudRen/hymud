#include <ansi.h>
inherit BOSS;

int boss_init(object me);
int boss_zhaohuan(object me);
int boss_attack2();

void create()
{
        set_name( HIY"����" NOR, ({ "qiong qi", "qiongqi" }) );
        set("long", HIY "��˵���������Ķ������Ĵ�С��ţ�������󻢡����д��
        ��ëƤ�����г������Ľ����󹷣�������Ϊ����\n\n" NOR);

        set("race", "Ұ��");
        set("gender", "����");
        set("age", 10000);
        set("no_get", 1);
        set("shen_type", 0);
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
	set("dex",400);
	set("con",400);
	set("int",400);
	set("str",400);
		set("nickname",HIR"�Ϲ�����"NOR);
	set("combat_exp", 100000000);
	set("level", 18);
		set("qi", 3800000);
		set("max_qi", 3800000);
		set("jing", 3800000);
		set("max_jing", 3800000);
		set("neili", 3000000);
		set("max_neili", 3000000);
		set("jiali", 20000);
	set("vendetta/authority",1);
	
	set_skill("dodge", 1200);
	set_skill("force", 1200);
	set_skill("unarmed", 1200);
	set_skill("dragon",1250);
	set_skill("spells",1250);
	set_skill("magic-old",1250);
	map_skill("unarmed", "dragon");
	
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
	set_temp("apply/dodge", 200);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 6600);
	set_temp("apply/armor", 6600);
	set_temp("apply/defence",200);
	
	// ��Ʒ����
	set("bonus", random(18000)+18000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"RI&10"   :   8000,
		"GE&5"   :  8000,
		"KS&3"   :   8000,
		"BL&3"   :  8000,
		"RI&60"   :   5000,
		"GE&6"   :  6000,
		"JD&7"   :  6000,
		"YC&4"   :  6000,
		"WG&4"   :  6000,
		"KS&7"   :  3600,
		"BL&8"   :  3600,
		"YW&5"   :  3600,
		"YA&5"   :  3600,
		"TW&300"   :  3000,
		"TA&300"   :  3000,
		"TZ&0"   :  2600,
		"TZ&1"   :  2300,		
	]));
	
	setup();
	carry_object("/clone/money/gold")->set_amount(500);
}



void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(2);
this_object()->delete_temp("boss_attack2");
        call_out("hunting",0);
	message_vision(HIB "$N" HIG "ŭ�𣺶�˵�����������Ķ��񣬵��������ܷ�����ƶ�ô���� \n" NOR, this_object());

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


int boss_attack2()
{	
if (!this_object()->query_temp("boss_attack2"))
{
message_vision(HIR "$N" HIR "һ�������ƶ��Ƿǣ�׼��ս���ɣ����� \n" NOR, this_object());
		remove_call_out("boss_zhaohuan"); //5����ٻ�С��
		call_out("boss_zhaohuan", 5);
this_object()->set_temp("boss_attack2",1);
}
	return 1;
}

int boss_init(object me)
{	
	message_vision(HIB "$N" HIG "ŭ�𣺶�˵�����������Ķ��񣬵��������ܷ�����ƶ�ô���� \n" NOR, this_object());
	remove_call_out("kill_ob");
	call_out("kill_ob", 0, me);
}

int boss_zhaohuan(object me)
{
	object obj1,obj2;
	int dam, dam1,i , num;
	object *inv;
	message_vision(HIB "$N" HIG "��Хһ�������ɣ���������������ɣ��� \n" NOR, this_object());
	message_vision(HIY "ͻȻ�������ܲ����������磬�Ʋ����ƺ��������������޻�����"
		"����ô�ʱͻȻ������������о��챻���̽����С�\n" NOR,
	this_object());
	
	inv = all_inventory(environment(this_object()));        

	num = sizeof(inv);       
	if (num < 1) num = 1;
	if (num > 5) num = 5;
	
	dam = 16000 / num;
	if(objectp(present("shenshou hufa", environment(this_object()))))
	{
		dam = dam * 2;//�л������ھ��˺��ӱ�
	}
	for (i=sizeof(inv)-1; i>=0; i--)
	{
		if (living(inv[i]) && inv[i] != this_object() && inv[i]->is_fighting(this_object()))
		{                        
			dam1 = dam - inv[i]->query_temp("apply/reduce_damage");
			if (dam1 <0) dam1 = 0;
			inv[i]->apply_condition("new_poison6", 5);
			inv[i]->receive_damage("qi", dam1); //�����Ǽ��˵Ļ����˺����Ҳ��2000���������£�������˺��������ܣ�
			inv[i]->receive_damage("jing", dam1/2);  //�����Ǽ��˵Ļ����˺����Ҳ��1000���������£�������˺��������ܣ�����Ҫ����Ѫ��������Դ����
			inv[i]->receive_wound("qi", dam1);
			inv[i]->receive_wound("jing", dam1/2);
			COMBAT_D->report_status(inv[i], 1);
		}
	}
	if (!present("shenshou hufa 1", environment(this_object())))
{
	obj1 = new(__DIR__"beast1");
	obj1->move(environment(this_object()));
	obj1->kill_ob(me);
}
	if (!present("shenshou hufa 2", environment(this_object())))
{
	obj2 = new(__DIR__"beast1");
	obj2->move(environment(this_object()));
	obj2->kill_ob(me);
}	
	remove_call_out("boss_zhaohuan"); //60����ٻ�С��
	call_out("boss_zhaohuan", 60, me);
}

varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{

        if (ob->query("shen",1)==0) return 0;
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
        ob->apply_condition("new_poison6", 3);
        return HIY"$N���ñ�����ĵط�����һ���⻪��"NOR;
}

		
		if (ob->query("shen",1)> 0) //���к��˻�Ѫ�����л��˷����˺�
		{		              
	        me->receive_curing("qi", ob->query("max_qi")/30);
	        me->receive_curing("jing", ob->query("max_jing")/30);
	  ob->apply_condition("new_poison6", 5);
	        return HIY"$N��Ц����Ҫ�����Ѫ����$nֻ����Ѫ������Ҫ�����ȥ����$N�����ָֻ��˵�������"NOR;
	    }
		else
		{	
	        me->receive_damage("qi", random(8888)+100);
	        me->receive_wound("qi", random(8888)+100);
		      me->receive_damage("qi", random(8888)+100);
	        me->receive_wound("jing", random(8888)+100);
 	        return HIY"$N����ȫ����������һ����ʹ��Ѫ�����������Խ��Խ������"NOR;
		}
}

mixed ob_hit(object me, object victim, int damage, int damage_bonus, int factor)
{
        string result;
        if (victim->query("shen",1)==0) return damage;
	if (victim->query("shen",1)> 0) //�������ӹ��������˼��ٹ���
	{
		damage_bonus+=damage/3;
		result = HIG"$Nһ�����У�$n��ʹŭ���Ƿ��ƶ�����ֵܷ����ô��\n"NOR;                      
	}
	else
	{	
		damage_bonus-=damage/3;
		result = HIG"$n��Ц������ͬ����������̫����$Nֻ���ô󲿷ֵĹ����������ˣ�\n"NOR;                      
	}
        message_vision(result,me,victim);
        return damage;
}


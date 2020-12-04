// wolfdog.c
#include <ansi.h>
inherit NPC;

mapping *data=({
(["name":"Ұ��ţ",	"id":"xizang mob",	"mw":-1,	]),
(["name":"Ұ����",	"id":"xizang mob",	"mw":-1,	]),
(["name":"��Ұ¿",	"id":"xizang mob",	"mw":-1,	]),
(["name":"����",	"id":"xizang mob",	"mw":-1,	]),
(["name":"����",	"id":"xizang mob",	"mw":-1,	]),
(["name":"�ز�",	"id":"xizang mob",	"mw":-1,	]),
(["name":"������",	"id":"xizang mob",	"mw":-1,	]),
(["name":"ѩ��",	"id":"xizang mob",	"mw":-1,	]),
(["name":"���",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"��",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"��ԭ����",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"��βҶ��",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"�ܺ�",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"⨺�",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"����",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"ë��¹",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"�����",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"Ұţ",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"��Ǯ��",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"�Ʊ�",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"����",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"Ұè",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"������",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"��¹",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"���",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"�״�¹",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"С��è",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"����",	"id":"xizang mob",	"mw":-1,	]),		
(["name":"�ز�",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"������",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"ѩ��",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"Ұ��ţ",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"Ұ����",	"id":"xizang mob",	"mw":-1,	]),							
(["name":"����",	"id":"xizang mob",	"mw":-1,	]),												
(["name":"��ѩ��",	"id":"xizang mob",	"mw":-1,	]),												
(["name":"�ھ���",	"id":"xizang mob",	"mw":-1,	]),												
(["name":"��ͷ��",	"id":"xizang mob",	"mw":-1,	]),												
(["name":"��ԭ����",	"id":"xizang mob",	"mw":-1,	]),																
		
});


void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ�������е�"+query("name")+"��\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���" }) );
	set("verbs", ({ "bite", "claw" }) );


        set("dex",20+random(100));

	set_skill("parry",30+random(300));
set_skill("unarmed",30+random(300));
	set("max_neili",900+random(8550));
	set("max_jing",900+random(8550));
		set("max_qi",900+random(8550));
	set_skill("dodge",30+random(300));

	set("combat_exp", 10000+random(8000000));
//	set("shen_type", -1);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
	}) );
		
        set_temp("apply/attack", 10+random(380));
        set_temp("apply/defense",10+random(380));
        set_temp("apply/armor", 10+random(380));
        set_temp("apply/damage", 10+random(380));

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}

void die()
{
int i,pot,exp;
	object killer;
	object ob;
	//message_vision("$N�Һ�һ�������ˣ�\n", this_object());	
	exp= random(15)+2;
	pot= exp/2+1;
	if(objectp(killer = query_temp("last_damage_from")))
{

if (userp(killer))
{
 	tell_object(killer,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);

if (random(3)==0)
{
	ob = new(__DIR__"goupi");
	ob->move(killer);
	message_vision("$n��$N���ϵõ���Ƥë��\n", this_object(),killer);

}

	ob = new(__DIR__"gourou");
	ob->move(killer);
	message_vision("$n��$N���ϵõ������⣡\n", this_object(),killer);
}	
killer->start_busy(5);
	//destruct(this_object());
}


	::die();

return ;
}


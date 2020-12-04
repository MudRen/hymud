// wolfdog.c
#include <ansi.h>
inherit NPC;

mapping *data=({
(["name":"Ұ��ţ",	"id":"forest mob",	"mw":-1,	]),
(["name":"Ұ����",	"id":"forest mob",	"mw":-1,	]),
(["name":"��Ұ¿",	"id":"forest mob",	"mw":-1,	]),
(["name":"����",	"id":"forest mob",	"mw":-1,	]),
(["name":"����",	"id":"forest mob",	"mw":-1,	]),
(["name":"�ز�",	"id":"forest mob",	"mw":-1,	]),
(["name":"������",	"id":"forest mob",	"mw":-1,	]),
(["name":"ѩ��",	"id":"forest mob",	"mw":-1,	]),
(["name":"���",	"id":"forest mob",	"mw":-1,	]),		
(["name":"��",	"id":"forest mob",	"mw":-1,	]),		
(["name":"��ԭ����",	"id":"forest mob",	"mw":-1,	]),		
(["name":"��βҶ��",	"id":"forest mob",	"mw":-1,	]),		
(["name":"�ܺ�",	"id":"forest mob",	"mw":-1,	]),		
(["name":"⨺�",	"id":"forest mob",	"mw":-1,	]),		
(["name":"����",	"id":"forest mob",	"mw":-1,	]),							
(["name":"ë��¹",	"id":"forest mob",	"mw":-1,	]),		
(["name":"�����",	"id":"forest mob",	"mw":-1,	]),		
(["name":"Ұţ",	"id":"forest mob",	"mw":-1,	]),		
(["name":"��Ǯ��",	"id":"forest mob",	"mw":-1,	]),		
(["name":"�Ʊ�",	"id":"forest mob",	"mw":-1,	]),		
(["name":"����",	"id":"forest mob",	"mw":-1,	]),		
(["name":"Ұè",	"id":"forest mob",	"mw":-1,	]),							
(["name":"������",	"id":"forest mob",	"mw":-1,	]),		
(["name":"��¹",	"id":"forest mob",	"mw":-1,	]),		
(["name":"���",	"id":"forest mob",	"mw":-1,	]),		
(["name":"�״�¹",	"id":"forest mob",	"mw":-1,	]),		
(["name":"С��è",	"id":"forest mob",	"mw":-1,	]),		
(["name":"����",	"id":"forest mob",	"mw":-1,	]),		
(["name":"�ز�",	"id":"forest mob",	"mw":-1,	]),							
(["name":"������",	"id":"forest mob",	"mw":-1,	]),							
(["name":"ѩ��",	"id":"forest mob",	"mw":-1,	]),							
(["name":"Ұ��ţ",	"id":"forest mob",	"mw":-1,	]),							
(["name":"Ұ����",	"id":"forest mob",	"mw":-1,	]),							
(["name":"����",	"id":"forest mob",	"mw":-1,	]),												
(["name":"��ѩ��",	"id":"forest mob",	"mw":-1,	]),												
(["name":"�ھ���",	"id":"forest mob",	"mw":-1,	]),												
(["name":"��ͷ��",	"id":"forest mob",	"mw":-1,	]),												
(["name":"��ԭ����",	"id":"forest mob",	"mw":-1,	]),																
		
});


void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ����֮ɭ���е�"+query("name")+"��\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���" }) );
	set("verbs", ({ "bite", "claw" }) );


        set("dex",30+random(100));
  set("vendetta/authority",1);
	set_skill("parry",80+random(300));
set_skill("unarmed",80+random(300));
	set("max_neili",900+random(8550));
	set("max_jing",900+random(8550));
		set("max_qi",900+random(8550));
	set_skill("dodge",80+random(300));

	set("combat_exp", 20000+random(8000000));
//	set("shen_type", -1);

//	set("chat_chance", 6);
//	set("chat_msg", ({
//		(: this_object(), "random_move" :),
//	}) );
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
	}) );
		
        set_temp("apply/attack", 20+random(380));
        set_temp("apply/defense",20+random(380));
        set_temp("apply/armor", 20+random(380));
        set_temp("apply/damage", 20+random(380));

	setup();
}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
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

void die()
{
int i,pot,exp;
	object killer;
	object ob;
	//message_vision("$N�Һ�һ�������ˣ�\n", this_object());	
	exp= random(15)+1;
	pot= exp/3;
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


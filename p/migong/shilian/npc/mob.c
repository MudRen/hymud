// wolfdog.c
#include <ansi.h>
inherit NPC;

mapping *data=({
(["name":"Ò°êóÅ£",	"id":"forest mob",	"mw":-1,	]),
(["name":"Ò°ÁçÑò",	"id":"forest mob",	"mw":-1,	]),
(["name":"²ØÒ°Â¿",	"id":"forest mob",	"mw":-1,	]),
(["name":"ÑÒÑò",	"id":"forest mob",	"mw":-1,	]),
(["name":"ÅÌÑò",	"id":"forest mob",	"mw":-1,	]),
(["name":"²Ø²ò",	"id":"forest mob",	"mw":-1,	]),
(["name":"²ØÂíÐÜ",	"id":"forest mob",	"mw":-1,	]),
(["name":"Ñ©±ª",	"id":"forest mob",	"mw":-1,	]),
(["name":"â¦áû",	"id":"forest mob",	"mw":-1,	]),		
(["name":"ÀÇ",	"id":"forest mob",	"mw":-1,	]),		
(["name":"¸ßÔ­ÊóÍÃ",	"id":"forest mob",	"mw":-1,	]),		
(["name":"³¤Î²Ò¶ºï",	"id":"forest mob",	"mw":-1,	]),		
(["name":"ÐÜºï",	"id":"forest mob",	"mw":-1,	]),		
(["name":"â¨ºï",	"id":"forest mob",	"mw":-1,	]),		
(["name":"÷ä×Ó",	"id":"forest mob",	"mw":-1,	]),							
(["name":"Ã«¹ÚÂ¹",	"id":"forest mob",	"mw":-1,	]),		
(["name":"ºì°ßÁç",	"id":"forest mob",	"mw":-1,	]),		
(["name":"Ò°Å£",	"id":"forest mob",	"mw":-1,	]),		
(["name":"½ðÇ®±ª",	"id":"forest mob",	"mw":-1,	]),		
(["name":"ÔÆ±ª",	"id":"forest mob",	"mw":-1,	]),		
(["name":"ºÚÐÜ",	"id":"forest mob",	"mw":-1,	]),		
(["name":"Ò°Ã¨",	"id":"forest mob",	"mw":-1,	]),							
(["name":"¹û×ÓÀê",	"id":"forest mob",	"mw":-1,	]),		
(["name":"ÂíÂ¹",	"id":"forest mob",	"mw":-1,	]),		
(["name":"â¯×Ó",	"id":"forest mob",	"mw":-1,	]),		
(["name":"°×´½Â¹",	"id":"forest mob",	"mw":-1,	]),		
(["name":"Ð¡ÐÜÃ¨",	"id":"forest mob",	"mw":-1,	]),		
(["name":"ÑÒÑò",	"id":"forest mob",	"mw":-1,	]),		
(["name":"²Ø²ò",	"id":"forest mob",	"mw":-1,	]),							
(["name":"²ØÂíÐÜ",	"id":"forest mob",	"mw":-1,	]),							
(["name":"Ñ©±ª",	"id":"forest mob",	"mw":-1,	]),							
(["name":"Ò°êóÅ£",	"id":"forest mob",	"mw":-1,	]),							
(["name":"Ò°ÁçÑò",	"id":"forest mob",	"mw":-1,	]),							
(["name":"²ØÂí¼¦",	"id":"forest mob",	"mw":-1,	]),												
(["name":"²ØÑ©¼¦",	"id":"forest mob",	"mw":-1,	]),												
(["name":"ºÚ¾±º×",	"id":"forest mob",	"mw":-1,	]),												
(["name":"°ßÍ·Ñã",	"id":"forest mob",	"mw":-1,	]),												
(["name":"¸ßÔ­ÊóÍÃ",	"id":"forest mob",	"mw":-1,	]),																
		
});


void create()
{
	mapping npc;

	npc=data[random(sizeof(data))];
	set_name(npc["name"],({ npc["id"] }));
	set("race", "Ò°ÊÞ");
	set("age", 4);
	set("long", "Ò»Ö»ÊÔÁ¶Ö®É­ÌØÓÐµÄ"+query("name")+"¡£\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "ºó½Å" }) );
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
	//message_vision("$N²Òº¿Ò»Éù£¬ËÀÁË£¡\n", this_object());	
	exp= random(15)+1;
	pot= exp/3;
	if(objectp(killer = query_temp("last_damage_from")))
{

if (userp(killer))
{
 	tell_object(killer,"Äã±»½±ÀøÁË\n"+chinese_number(exp)+"µãÊµÕ½¾­Ñé\n"
		+chinese_number(pot)+"µãÇ±ÄÜ\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);

if (random(3)==0)
{
	ob = new(__DIR__"goupi");
	ob->move(killer);
	message_vision("$n´Ó$NÉíÉÏµÃµ½ÁËÆ¤Ã«£¡\n", this_object(),killer);

}

	ob = new(__DIR__"gourou");
	ob->move(killer);
	message_vision("$n´Ó$NÉíÉÏµÃµ½ÁËÏÊÈâ£¡\n", this_object(),killer);
}	
killer->start_busy(5);
	//destruct(this_object());
}


	::die();

return ;
}


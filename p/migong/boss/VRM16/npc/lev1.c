#include <ansi.h>
inherit BOSS;
mapping *data=({
(["id":"mon ster","title":"ħ������","name":"�ȳ�",]),
(["id":"mon ster","title":"ħ������","name":"��֩��",]),
(["id":"mon ster","title":"ħ������","name":"ʷ��ķ",]),
(["id":"mon ster","title":"ħ������","name":"Ы��",]),
(["id":"mon ster","title":"ħ������","name":"�۾�����",]),
(["id":"mon ster","title":"ħ������","name":"ʳ�˻�",]),
(["id":"mon ster","title":"ħ������","name":"����",]),
(["id":"mon ster","title":"ħ������","name":"��Ѫ����",]),
(["id":"mon ster","title":"ħ������","name":"ħ��",]),
(["id":"mon ster","title":"ħ������","name":"�Ŵ���",]),
(["id":"mon ster","title":"ħ������","name":"����֮Ȯ",]),
(["id":"mon ster","title":"ħ������","name":"���",]),
(["id":"mon ster","title":"ħ������","name":"�ǹ�",]),
(["id":"mon ster","title":"ħ������","name":"��Ǯ��",]),
(["id":"mon ster","title":"ħ������","name":"ɱ�˷�",]),
(["id":"mon ster","title":"ħ������","name":"����",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
set_name(order[random(13)]+npc["name"]+NOR,({ npc["id"] }));    
	set("magicgift",2);
	set("magicset",1);
          set("race", "Ұ��");
       set("long",
"һֻ���µ�ħ�����\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "��֫" }) );
        set("verbs", ({ "bite", "claw" }) );
	       set("max_qi",500+random(500));
	set("combat_exp",18000000+random(8000000));
        set_skill("force",400+random(200));
	set_skill("unarmed",800+random(200));
	set_skill("sword",800+random(200));
	set_skill("club",800+random(200));
	set_skill("whip",800+random(200));
	set_skill("throwing",800+random(200));
	set_skill("parry",800+random(200));
	set_skill("dodge",800+random(200));
 set_skill("dragon", 800+random(200));
  map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
        set("no_get",1);
b=55000+random(36000);
a=56000+random(35000);
d=50+random(60);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);

        set("neili",a);
        set("max_neili",a);
       
    set("age", 15);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",3500);
	set_temp("apply/damage",3400);
     set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
           }) );
 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.yaoyao" :),
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
 }) );
 	set("bonus", random(580)+580);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&480"   :  200,
	      "TA&480"   :  200,
	]));
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



int hit_ob(object me, object ob, int damage)
{


  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/2)
{
ob->apply_condition("new_poison3", 8); 
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n" NOR );
}
}

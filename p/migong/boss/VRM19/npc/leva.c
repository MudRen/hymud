#include <ansi.h>
inherit BOSS;
mapping *data=({
(["id":"magic wiz","title":"魔法师行会","name":"魔法仰慕者",]),
(["id":"magic wiz","title":"魔法师行会","name":"魔法学院新生",]),
(["id":"magic wiz","title":"魔法师行会","name":"魔法学院高材生",]),
(["id":"magic wiz","title":"魔法师行会","name":"魔法师学徒",]),
(["id":"magic wiz","title":"魔法师行会","name":"菜鸟魔法使",]),
(["id":"magic wiz","title":"魔法师行会","name":"高阶魔法使",]),
(["id":"magic wiz","title":"魔法师行会","name":"灰衣魔法使",]),
(["id":"magic wiz","title":"魔法师行会","name":"初级魔道士",]),
(["id":"magic wiz","title":"魔法师行会","name":"高级魔道士",]),
(["id":"magic wiz","title":"魔法师行会","name":"魔导士",]),
(["id":"magic wiz","title":"魔法师行会","name":"大魔导士",]),
(["id":"magic wiz","title":"魔法师行会","name":"银魔导士",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
set_name(order[random(13)]+npc["name"]+NOR,({ npc["id"] }));    
set("nickname",(npc["title"]));
	set("magicgift",1+random(6));
	set("zhuanbest",1);
	set("magicset",1);
       set("long",
"一只可怕的魔法师。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",15000+random(500));
	set("combat_exp",25000000+random(8000000));
        set_skill("force",900+random(300));
	set_skill("unarmed",900+random(300));
	set_skill("sword",900+random(300));
	set_skill("club",900+random(300));
	set_skill("whip",900+random(300));
	set_skill("throwing",900+random(300));
	set_skill("parry",900+random(300));
      set_skill("magic-dark", 900+random(300));
      set_skill("magic-light", 900+random(300));
      set_skill("magic-earth", 900+random(300));
      set_skill("magic-ice", 900+random(300));
      set_skill("magic-water", 900+random(300));
      set_skill("magic-fire", 900+random(300));
      set_skill("magic-unarmed", 900+random(300));
      set_skill("magic-sword", 900+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
        set("no_get",1);
b=105000+random(96000);
a=106000+random(95000);
d=80+random(60);
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
	set_temp("apply/armor",4500);
	set_temp("apply/damage",4400);
     set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
           }) );
if (random(2)==0)
{
     map_skill("spells", "magic-fire");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.light" :),
               (: perform_action, "spells.fireball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.immolation" :),
               (: perform_action, "spells.firebolt" :),
               (: perform_action, "spells.meteor" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.incinerate" :),                                                            
        }) );
}
else 
{
     map_skill("spells", "magic-water");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.zeroring" :),                                                            
        }) );
}
 	set("bonus", random(680)+780);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   380,
	      "TW&480"   :  280,
	      "TA&480"   :  280,
	])); 

   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
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
        if(userp(ob[i]) && ob[i]->query("shen")> -200000
        && ob[i]->query("shen")< 200000) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}


int hit_ob(object me, object ob, int damage)
{
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
ob->apply_condition("new_poison6", 10); 
        tell_object(ob, HIG "你觉得被打中的地方闪过一阵光华！\n" NOR );
}
}


#include <ansi.h>
inherit BOSS;
mapping *data=({
(["id":"devil corps","title":"魔族军团","name":"初级魔剑士",]),
(["id":"devil corps","title":"魔族军团","name":"高级魔剑士",]),
(["id":"devil corps","title":"魔族军团","name":"见习魔剑使",]),
(["id":"devil corps","title":"魔族军团","name":"先锋魔剑使",]),
(["id":"devil corps","title":"魔族军团","name":"魔剑使指挥官",]),
(["id":"devil corps","title":"魔族军团","name":"副魔族长",]),
(["id":"devil corps","title":"魔族军团","name":"恶魔法师",]),
(["id":"devil corps","title":"魔族军团","name":"死灵法师",]),
(["id":"devil corps","title":"魔族军团","name":"正魔族长",]),
(["id":"devil corps","title":"魔族军团","name":"魔团长",]),
(["id":"devil corps","title":"魔族军团","name":"大魔团长",]),
(["id":"devil corps","title":"魔族军团","name":"魔军司令目",]),
(["id":"devil corps","title":"魔族军团","name":"魔军最高统率",]),
(["id":"devil corps","title":"魔族军团","name":"魔神王子",]),
(["id":"devil corps","title":"魔族军团","name":"魔神王",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
set_name(order[random(13)]+npc["name"]+NOR,({ npc["id"] }));    
set("nickname",(HIB+npc["title"])+NOR);
	set("magicgift",1+random(6));
	set("zhuanbest",1);
	set("magicset",1);
       set("long",
"一位魔族军团的战士。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",48000000+random(8000000));
         set_skill("force",1550+random(300));
	set_skill("unarmed",1550+random(300));
	set_skill("sword",1550+random(300));
	set_skill("club",1550+random(300));
	set_skill("whip",1550+random(300));
	set_skill("throwing",1550+random(300));
	set_skill("parry",1550+random(300));
      set_skill("magic-dark", 1500+random(300));
      set_skill("magic-light", 1500+random(300));
      set_skill("magic-earth", 1500+random(300));
      set_skill("magic-ice", 1500+random(300));
      set_skill("magic-water", 1500+random(300));
      set_skill("magic-fire", 1500+random(300));
      set_skill("magic-unarmed", 1550+random(300));
      set_skill("magic-sword", 1550+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
      map_skill("spells", "magic-dark");
        set("no_get",1);
	set_skill("force",1550+random(300));
	set_skill("huntian-qigong",1550+random(300));
	map_skill("force", "huntian-qigong");
b=94600+random(86000);
a=97600+random(85000);
d=105+random(60);
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

set("shen",-100000);
        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",250);
	set_temp("apply/defense",250);
	set_temp("apply/armor",3500);
	set_temp("apply/damage",3400);
     set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
           }) );
if (random(2)==0)
{
     map_skill("spells", "magic-dark");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
              (: perform_action, "spells.nuclea" :),
               (: perform_action, "spells.darkstorm" :),
               (: perform_action, "spells.darkwind" :),
               (: perform_action, "spells.darkmetor" :),
               (: perform_action, "spells.darkforce" :),
               (: perform_action, "spells.dragon" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.castigate" :),                                                              
        }) );
}
else 
{
     map_skill("spells", "magic-earth");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.stab" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.Attach" :),
               (: perform_action, "spells.missile" :),
               (: perform_action, "spells.quake" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.Dintfield" :),                                                             
        }) );
        }

if (random(18)==0)
{
set("nickname",HIY"武功高超"NOR);
        set_skill("spells",1200+random(1000));
        set_skill("force",1200+random(1000));
	set_skill("unarmed",1200+random(1000));
	set_skill("sword",1200+random(1000));
	set_skill("club",1200+random(1000));
	set_skill("whip",1200+random(1000));
	set_skill("throwing",1200+random(1000));
	set_skill("parry",1200+random(1000));
}
else
if (random(18)==0)
{
set("nickname",MAG"魔法强大"NOR);
      set_skill("magic-unarmed", 1850+random(1300));
      set_skill("magic-sword", 1850+random(1300));
      set_skill("magic-ice", 1850+random(1200));
      set_skill("magic-water", 1850+random(1200));
      set_skill("magic-fire", 1850+random(1200));
      set_skill("magic-earth", 1850+random(1200));
      set_skill("magic-light", 1850+random(1200));
      set_skill("magic-dark", 1850+random(1200));
}
else
if (random(18)==0)
{
set("nickname",HIB"经验丰富"NOR);
set("combat_exp",190000000+random(58000000));
}
else
if (random(18)==0)
{
set("nickname",HIR"强大不死"NOR);
set("dex",300);
        set("jing",3900000);
        set("max_jing",3900000);
        set("eff_jing",3900000);
        set("qi",3900000);
        set("max_qi",3900000);
        set("eff_qi",3900000);
        set("neili",3900000);
        set("max_neili",3900000);
}
else
if (random(18)==0)
{
set("nickname",HIC"超级加强"NOR);
d=188+random(188);
set("str",d);
set("dex",50+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(18)==0)
{
set("dex",300);
        set("jing",2800000);
        set("max_jing",2800000);
        set("eff_jing",2800000);
        set("qi",2800000);
        set("max_qi",2800000);
        set("eff_qi",2800000);
        set("neili",2800000);
        set("max_neili",2800000);
      set_skill("magic-unarmed", 1850+random(800));
      set_skill("magic-sword", 1850+random(800));
      set_skill("magic-ice", 1850+random(800));
      set_skill("magic-water", 1850+random(800));
      set_skill("magic-fire", 1850+random(800));
      set_skill("magic-earth", 1850+random(800));
      set_skill("magic-light", 1850+random(800));
      set_skill("magic-dark", 1850+random(800));
        set_skill("spells",1850+random(800));
        set_skill("force",1850+random(800));
	set_skill("unarmed",1850+random(800));
	set_skill("sword",1850+random(800));
	set_skill("club",1850+random(800));
	set_skill("whip",1850+random(800));
	set_skill("throwing",1850+random(800));
	set_skill("parry",1850+random(800));
set("nickname",HIC"完美无敌"NOR);
d=188+random(188);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
  	set("bonus", random(780)+680);
	set("killer_reward", ([
	      "FI&/clone/box/gbox"   :   300,
	      "TW&480"   :  200,
	      "TA&480"   :  200,
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


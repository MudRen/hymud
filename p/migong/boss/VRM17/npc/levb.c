#include <ansi.h>
inherit BOSS;
mapping *data=({
(["id":"angelali","title":"神圣联盟","name":"见习新兵",]),
(["id":"angelali","title":"神圣联盟","name":"正规军小兵",]),
(["id":"angelali","title":"神圣联盟","name":"贵族侍从",]),
(["id":"angelali","title":"神圣联盟","name":"初级战士",]),
(["id":"angelali","title":"神圣联盟","name":"义勇军战士",]),
(["id":"angelali","title":"神圣联盟","name":"正规军战士",]),
(["id":"angelali","title":"神圣联盟","name":"精锐战士",]),
(["id":"angelali","title":"神圣联盟","name":"精锐剑士",]),
(["id":"angelali","title":"神圣联盟","name":"见习骑士",]),
(["id":"angelali","title":"神圣联盟","name":"先锋骑士",]),
(["id":"angelali","title":"神圣联盟","name":"皇家骑士",]),
(["id":"angelali","title":"神圣联盟","name":"精锐骑士",]),
(["id":"angelali","title":"神圣联盟","name":"骑士长",]),
(["id":"angelali","title":"神圣联盟","name":"大骑士长",]),
(["id":"angelali","title":"神圣联盟","name":"骑士统师",])
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
"一位神圣联盟的战士。\n");
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
b=85000+random(86000);
a=86000+random(85000);
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

        set("shen_type", 1);
set("shen",100000);
        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",3500);
	set_temp("apply/damage",3400);
     set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
           }) );
if (random(2)==0)
{
     map_skill("spells", "magic-light");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.cure angelali" :),
               (: perform_action, "spells.delete" :),
               (: perform_action, "spells.holyword" :),
               (: perform_action, "spells.moonlight angelali" :),
               (: perform_action, "spells.sunbolt" :),
               (: perform_action, "spells.sunfield" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.sunarrow" :),                                                            
        }) );
}
else 
{
     map_skill("spells", "magic-ice");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.invisibility" :),
               (: perform_action, "spells.lightningball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.implosion" :),
               (: perform_action, "spells.lightningbolt" :),
               (: perform_action, "spells.stun" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.holylightning" :),                                                            
        }) );
        }
 	set("bonus", random(680)+680);
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
        if(userp(ob[i]) && ob[i]->query("shen")> 100000) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

int hit_ob(object me, object ob, int damage)
{
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
ob->apply_condition("new_poison4", 8); 
        tell_object(ob, HIR "你觉得被打中的地方闪过一阵光华！\n" NOR );
}
}

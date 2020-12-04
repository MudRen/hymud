// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name("巨蟒", ({ "ju mang" , "mang" }));
      
          set("race", "野兽");
       set("long",
"一条八尺来长的蟒蛇。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
	       set("max_qi",1800+random(800));
  set("max_jing",1800+random(800));
  set("max_sen",800+random(800));
  set("max_mana",800+random(800));
  
      set("dex",30);
     set("str" ,35);
       
    set("age", 5);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 800000);
                  
        set_temp("apply/attack", 90);
        set_temp("apply/damage", 90);
        set_temp("apply/armor", 90);
        set_temp("apply/defence",90);

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
        object ob, me, corpse;int exp,pot;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;    
              me->add("score",1);        
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
exp=8+random(5);
        if((int)me->query("combat_exp") < 800000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "获得了"+exp+"点经验和"+pot+"点潜能。\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}



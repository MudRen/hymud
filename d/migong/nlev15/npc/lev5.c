// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIY"金龙"NOR, ({ "jin long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条浑身闪烁的金光的巨龙，看到了你，向你扑了过来。
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );

  set("max_jing",25000+random(10000));
  set("max_qi",30000+random(10000));
  set("neili",39999);
  set("max_neili",39999);
      set("dex",50);
      set("con",50);
     set("str" ,50);
       
    set("age", 80);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 9000000+random(2000000));
            set_temp("apply/attack", 400);
        set_temp("apply/damage", 800);
        set_temp("apply/armor", 800);
        set_temp("apply/defence",100);
      set_skill("dodge", 400+random(100));

      set_skill("unarmed", 400+random(100));

       set_skill("dragon", 400+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.yaoyao" :),

 }) );
     set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
           }) );

    
     
   setup();

       
carry_object("/d/migong/obj/longdan");
  

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

void die()
{
        object ob, me, corpse;int exp,pot;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;
              me->add("score",1);

        message_vision(WHT"$N一声怒吼，浑身鲜血直流，缓缓躺倒在地。\n"NOR,ob,me);
  exp=60+random(20);
        if((int)me->query("combat_exp") < 28000000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "获得了"+exp+"点经验和"+pot+"点潜能。\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}



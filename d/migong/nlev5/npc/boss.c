// migong lev5

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIY"毒金雕"NOR, ({ "jin diao" , "diao" }));
                set("race", "野兽");
       set("long",
"一只长着金色羽毛的大雕。
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw" }) );
	       set("max_qi",39000+random(2000));
  set("max_jing",39000+random(2000));
  set("max_qi",39000+random(2000));
  set("max_mana",39000+random(2000));
  
      set("dex",100);
     set("str" ,100);
set("no_get",1);       
    set("age", 15);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 5000000);
                  
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/defence", 200);

   setup();

    
carry_object("/d/migong/obj/tao");
	    

}


void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(3);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}



void hunting()
{
	int i;
        object *ob;
if (!environment(this_object())) return;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse,obj;
               int exp,pot,score,i;
        int maxpot;
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;   
              me->add("score",1);
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 5000000)   {
if (random(80) < 1)
{
             corpse=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",me);
             command("rumor "+me->query("name")+"得到一颗"+corpse->query("name")+"!"NOR"。\n");
             corpse->move(me);
}        
        message("vision", me->name() + "成功打死猎物增加了800经验和600潜能。\n", me);
        me->add("combat_exp",800);
        me->add("potential",600);
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));           
        destruct(ob);
        }
               destruct(ob);
        return;
}


int hit_ob(object me, object ob, int damage)
{
if (ob)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
}
}

// migong lev10  du

#include <ansi.h>

inherit NPC;


void create()
{
  
      set_name(MAG"盲婆婆"NOR,({ "mang popo" , "popo" }));
 
       set("gender", "女性" );
 set("long",
"百毒神君的师姐,武功极高，因被百毒神君暗算毒瞎了
双眼，所以躲藏于次。\n");
        	  set("force_factor",100+random(200));
  set("max_qi",39000+random(4200));
  set("max_jing",39000+random(4200));
  set("max_sen",39000+random(4200));
  set("max_neili",19000+random(4000));
  set("max_mana",19000+random(4000));
  set("eff_neili",12500+random(4000));
  set("neili",19000+random(4000));
set("attitude", "aggressive");
        set("per", 1);
        set("age", 52);
set("no_get",1);
       set("jiali" , 200);
        set("shen", -10000);
               set("combat_exp", 8000000+random(2000000));
                 set_skill("claw", 400+random(60));

set_skill("unarmed", 400+random(60));

        set_skill("force", 300);
        set_skill("wudu-shengong", 300);
        set_skill("dodge", 290);
        set_skill("wudu-yanluobu", 250);
        set_skill("unarmed", 260);
        set_skill("qianzhu-wandushou", 260);
        set_skill("parry", 180);
        set_skill("sword", 200);
        set_skill("wudu-goufa", 280);
        set_skill("poison", 260);
        set_skill("literate", 280); 
        set_skill("finger",260);
        set_skill("shedu-qiqiao",260);
         set("chat_chance_combat", 90);
         set("chat_msg_combat", ({
                (: perform_action, "finger.sandu" :),
                (: perform_action, "sword.suo" :),
                (: perform_action, "unarmed.qzwd" :),
                (: perform_action, "finger.sandu" :),
                (: perform_action, "dodge.snake" :),
        }) );


        map_skill("finger","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");

        create_family("五毒教", 11, "长老");
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 550);
 
          set_temp("apply/armor", 350);
        set_temp("apply/damage", 350);


   set("inquiry", ([       
"百毒神君" : "他是我师弟，这个狼心狗废的东西，我的眼睛就是他毒瞎的。",
"百毒尊者" : "百毒尊者也是我师弟，他也不是个好东西，和他师兄狼狈为奸。",
"眼睛" : "我的眼睛是被断肠草毒瞎的，只有七心海棠能治。",
"七心海棠" : "听说七心海棠就只有眠龙洞里有，但我找了许久就是没找到。"
]) );  

        setup();

        carry_object("d/wudujiao/npc/obj/jiandao")->wield();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("d/wudujiao/npc/obj/wuxing");    
   carry_object("/d/migong/obj/zhang")->wield();
	
    

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
        tell_object(ob, HIG "你觉得被打中的地方一阵麻痒！\n" NOR );
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
             me->add("score",1000);
        me->add("shen",1000);
        
        message_vision(WHT"$N被打烂了!!。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 9000000)   {
        message("vision", me->name() + "为江湖除害,增加了900经验和900潜能。\n", me);
        me->add("combat_exp",900);
        me->add("potential",900);
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));           
        destruct(ob);
        }
        destruct(ob);
        return;
}

#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""YEL"", ""HIW"", ""YEL"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"堤洛"NOR, ({ "tero"}));
	set("magicgift",4);
	set("magicset",1);
       set("title",YEL"大地巨神"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的大地巨神。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	set("combat_exp",53000000+random(8000000));
        set_skill("force",490+random(300));
	set_skill("unarmed",490+random(300));
	set_skill("sword",490+random(300));
	set_skill("club",490+random(300));
	set_skill("whip",490+random(300));
	set_skill("throwing",490+random(300));
	set_skill("spells",600+random(300));
	set_skill("parry",490+random(300));
      set_skill("magic-unarmed", 650+random(200));
      set_skill("magic-sword", 650+random(200));
      set_skill("magic-fire", 600+random(200));
      set_skill("magic-earth", 650+random(200));
      set_skill("magic-ice", 660+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-earth");
        set("no_get",1);
	set_skill("force",550+random(300));
	set_skill("huntian-qigong",550+random(300));
	map_skill("force", "huntian-qigong");
b=2369000+random(66000);
a=2369000+random(68000);
d=150+random(60);
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
	set_temp("apply/armor",600);
	set_temp("apply/damage",600);

        set("chat_chance_combat", 80);
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

void die()
{
        object ob, me, corpse;
        int i,exp,pot,score;
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
              me->add("score",1);
        message_vision(YEL"$N,倒地而亡，化入了大地。\n"NOR,ob,me);

if (!me->query("migong/lev19"))
{
exp = 680000+random(188000);
pot = exp/2;
score = random(300)+950;
 me->set_temp("magicov1",1);
 me->set("migong/lev19",1);
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);	
i=random(8);
	if (i==7) {
        if ( me->query("per")< 80)
        {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
        }
	}
	else if (i==6) {
        if ( me->query("kar")< 80)
        {
	me->add("kar",1);tell_object(me,HIM"以及一点福缘。\n"NOR);
        }
	}
	else if (i==5) {
        if ( me->query("dex")< 80)
        {
	me->add("dex",1);tell_object(me,HIM"以及一点身法。\n"NOR);
        }
	}
	else if (i==4) {
        if ( me->query("str")< 80)
        {
	me->add("str",1);tell_object(me,HIM"以及一点力量。\n"NOR);
        }
	}
	else if (i==3) {
        if ( me->query("per")< 80)
        {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
        }
	}
	else if (i==2) {
        if ( me->query("kar")< 80)
        {
	me->add("kar",1);tell_object(me,HIM"以及一点福缘。\n"NOR);
        }
	}
	else if (i==1) {
        if ( me->query("con")< 80)
        {
	me->add("con",1);tell_object(me,HIM"以及一点根骨。\n"NOR);
        }
	}
	else if (i==0) {
        if ( me->query("int")< 80)
        {
	me->add("int",1);tell_object(me,HIM"以及一点悟性。\n"NOR);
        }
	}
	else if (me->query("per")< 100) {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
	}
}
        
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"成功消灭"+ob->query("title")+HIG",完成了风之世界的任务。\n"NOR, users());
        me->add("combat_exp",600);
        me->add("potential",300);
        me->add("score",1);
        me->set_temp("magicov1",1);
        me->set("migong/lev19",1);
if (!present("air boot", me)

)
{
corpse=new("/clone/magic/obj/airboot");
corpse->move(me);
message("vision", me->name() + HIG"找到了古代神器:"+corpse->query("name")+HIG"。\n"NOR, users());
}

        destruct(ob);
        }
if (!present("air boot", me)

)
{
corpse=new("/clone/magic/obj/airboot");
corpse->move(me);
message("vision", me->name() + HIG"找到了古代神器:"+corpse->query("name")+HIG"。\n"NOR, users());
}
               destruct(ob);
        return;
}


#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIR"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"�������_"NOR, ({ "salamander"}));
	set("magicgift",1);
	set("magicset",1);
       set("title",HIR"��֮����"NOR);
       set("zhuanbest",1);
       set("long",
"һλ���µĻ�֮����\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",50000+random(500));
	set("combat_exp",33000000+random(8000000));
        set_skill("force",400+random(300));
	set_skill("unarmed",400+random(300));
	set_skill("sword",400+random(300));
	set_skill("club",400+random(300));
	set_skill("whip",400+random(300));
	set_skill("throwing",400+random(300));
	set_skill("spells",600+random(300));
	set_skill("parry",400+random(300));
      set_skill("magic-unarmed", 400+random(200));
      set_skill("magic-sword", 400+random(200));
      set_skill("magic-fire", 600+random(200));
      set_skill("magic-water", 600+random(200));
      set_skill("magic-ice", 600+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-fire");
        set("no_get",1);
b=2125000+random(66000);
a=2225000+random(68000);
d=35+random(60);
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

        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: perform_action, "spells.summon" :),
               (: perform_action, "spells.light" :),
               (: perform_action, "spells.fireball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.immolation" :),
               (: perform_action, "spells.firebolt" :),
               (: perform_action, "spells.meteor" :),                                                            
               (: perform_action, "spells.incinerate" :),                                                                                                                     
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
        message_vision(HIR"$N,���ض�������Ϊ��һ�Ż��ס�\n"NOR,ob,me);
if (!me->query("migong/lev17"))
{
exp = 580000+random(88000);
pot = exp/2;
score = random(300)+950;
 me->set_temp("magicov1",1);
 me->set("migong/lev17",1);
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n"NOR);	
i=random(8);
	if (i==7) {
        if ( me->query("per")< 80)
        {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
        }
	}
	else if (i==6) {
        if ( me->query("kar")< 80)
        {
	me->add("kar",1);tell_object(me,HIM"�Լ�һ�㸣Ե��\n"NOR);
        }
	}
	else if (i==5) {
        if ( me->query("dex")< 80)
        {
	me->add("dex",1);tell_object(me,HIM"�Լ�һ������\n"NOR);
        }
	}
	else if (i==4) {
        if ( me->query("str")< 80)
        {
	me->add("str",1);tell_object(me,HIM"�Լ�һ��������\n"NOR);
        }
	}
	else if (i==3) {
        if ( me->query("per")< 80)
        {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
        }
	}
	else if (i==2) {
        if ( me->query("kar")< 80)
        {
	me->add("kar",1);tell_object(me,HIM"�Լ�һ�㸣Ե��\n"NOR);
        }
	}
	else if (i==1) {
        if ( me->query("con")< 80)
        {
	me->add("con",1);tell_object(me,HIM"�Լ�һ����ǡ�\n"NOR);
        }
	}
	else if (i==0) {
        if ( me->query("int")< 80)
        {
	me->add("int",1);tell_object(me,HIM"�Լ�һ�����ԡ�\n"NOR);
        }
	}
	else if (me->query("per")< 100) {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
	}
}

        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"�ɹ�����"+ob->query("title")+HIG",�����ˮ֮���������\n"NOR, users());
        me->add("combat_exp",600);
        me->add("potential",300);
        me->add("score",1);
        me->set("migong/lev17",1);
        me->set_temp("magicov1",1);
if (!present("water armor", me)

)
{
corpse=new("/clone/magic/obj/waterarmor");
corpse->move(me);
message("vision", me->name() + HIG"�ҵ��˹Ŵ�����:"+corpse->query("name")+HIG"��\n"NOR, users());
}

        destruct(ob);
        }
if (!present("water armor", me)

)

{
corpse=new("/clone/magic/obj/waterarmor");
corpse->move(me);
message("vision", me->name() + HIG"�ҵ��˹Ŵ�����:"+corpse->query("name")+"��\n"NOR, me);
}


               destruct(ob);
        return;
}


void unconcious()
{
die();
}

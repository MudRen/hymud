#include <ansi.h>
inherit BOSS;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"ʥ��ʿ"NOR, ({ "champion"}));
if (random(2)==0)
	set("magicgift",5);
else 	set("magicgift",6);
set("nickname",HIW"��ʥ����"NOR);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"һֻ���µ�ʥ��ʿ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	 set("combat_exp",55000000+random(8000000));
        set_skill("force",1450+random(300));
	set_skill("unarmed",1450+random(300));
	set_skill("sword",1450+random(300));
	set_skill("club",1450+random(300));
	set_skill("whip",1450+random(300));
	set_skill("throwing",1450+random(300));
	set_skill("parry",1450+random(300));
      set_skill("magic-dark", 1400+random(300));
      set_skill("magic-light", 1400+random(300));
      set_skill("magic-earth", 1400+random(300));
      set_skill("magic-ice", 1400+random(300));
      set_skill("magic-water", 1400+random(300));
      set_skill("magic-fire", 1400+random(300));
      set_skill("magic-unarmed", 1450+random(300));
      set_skill("magic-sword", 1450+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
      map_skill("spells", "magic-light");
        set("no_get",1);
	set_skill("force",1550+random(300));
	set_skill("huntian-qigong",1550+random(300));
	map_skill("force", "huntian-qigong");
b=159600+random(99000);
a=159600+random(99000);
d=95+random(80);
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
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
    (: perform_action, "spells.moonlight champion" :),
    (: perform_action, "spells.sunbolt" :),
    (: perform_action, "spells.holyword" :),
        }) );
     set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
           }) );
if (random(8)==0)
{
set("nickname",HIY"�书�߳�"NOR);
        set_skill("spells",650+random(300));
        set_skill("force",650+random(300));
	set_skill("unarmed",650+random(300));
	set_skill("sword",650+random(300));
	set_skill("club",650+random(300));
	set_skill("whip",650+random(300));
	set_skill("throwing",650+random(300));
	set_skill("parry",650+random(300));
}
else
if (random(8)==0)
{
set("nickname",MAG"ħ��ǿ��"NOR);
      set_skill("magic-unarmed", 650+random(300));
      set_skill("magic-sword", 650+random(300));
      set_skill("magic-ice", 650+random(200));
      set_skill("magic-water", 650+random(200));
      set_skill("magic-fire", 650+random(200));
      set_skill("magic-earth", 650+random(200));
      set_skill("magic-light", 650+random(200));
      set_skill("magic-dark", 650+random(200));
}
else
if (random(8)==0)
{
set("nickname",HIB"����ḻ"NOR);
set("combat_exp",50000000+random(48000000));
}
else
if (random(8)==0)
{
set("nickname",HIR"ǿ����"NOR);
set("dex",300);
        set("jing",600000);
        set("max_jing",600000);
        set("eff_jing",600000);
        set("qi",600000);
        set("max_qi",600000);
        set("eff_qi",600000);
        set("neili",600000);
        set("max_neili",600000);
	set("combat_exp",10000000);
}
else
if (random(8)==0)
{
set("nickname",HIC"������ǿ"NOR);
d=88+random(88);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(10)==0)
{
set("dex",300);
        set("jing",100000);
        set("max_jing",100000);
        set("eff_jing",100000);
        set("qi",100000);
        set("max_qi",100000);
        set("eff_qi",100000);
        set("neili",100000);
        set("max_neili",100000);
      set_skill("magic-unarmed", 650+random(300));
      set_skill("magic-sword", 650+random(300));
      set_skill("magic-ice", 650+random(200));
      set_skill("magic-water", 650+random(200));
      set_skill("magic-fire", 650+random(200));
      set_skill("magic-earth", 650+random(200));
      set_skill("magic-light", 650+random(200));
      set_skill("magic-dark", 650+random(200));
        set_skill("spells",650+random(300));
        set_skill("force",650+random(300));
	set_skill("unarmed",650+random(300));
	set_skill("sword",650+random(300));
	set_skill("club",650+random(300));
	set_skill("whip",650+random(300));
	set_skill("throwing",650+random(300));
	set_skill("parry",650+random(300));
set("nickname",HIC"�����޵�"NOR);
d=88+random(88);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
if (random(18)==0)
{
set("nickname",HIY"�书�߳�"NOR);
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
set("nickname",MAG"ħ��ǿ��"NOR);
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
set("nickname",HIB"����ḻ"NOR);
set("combat_exp",190000000+random(58000000));
}
else
if (random(18)==0)
{
set("nickname",HIR"ǿ����"NOR);
set("dex",300);
        set("jing",2900000);
        set("max_jing",2900000);
        set("eff_jing",2900000);
        set("qi",2900000);
        set("max_qi",2900000);
        set("eff_qi",2900000);
        set("neili",2900000);
        set("max_neili",2900000);
}
else
if (random(18)==0)
{
set("nickname",HIC"������ǿ"NOR);
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
set("nickname",HIC"�����޵�"NOR);
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

int hit_ob(object me, object ob, int damage)
{
string msg;
        if(random((int)me->query("combat_exp")) > ob->query("combat_exp")/3)   
{
             ob->add("qi",-ob->query("qi")/20);
             ob->add("eff_qi",-ob->query("eff_qi")/20);
             ob->add("jing",-ob->query("jing")/20);
             ob->add("eff_jing",-ob->query("eff_jing")/20);
           msg = HIC"$N"HIY"��ʥ�裡������$n"HIY"!$n"HIY"��������!!\n"NOR;
            message_vision(msg, me, ob);
}
}
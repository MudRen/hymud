#include <ansi.h>
inherit BOSS;
mapping *data=({
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"ħ����Ľ��",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"ħ��ѧԺ����",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"ħ��ѧԺ�߲���",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"ħ��ʦѧͽ",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"����ħ��ʹ",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"�߽�ħ��ʹ",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"����ħ��ʹ",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"����ħ��ʿ",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"�߼�ħ��ʿ",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"ħ��ʿ",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"��ħ��ʿ",]),
(["id":"magic wiz","title":"ħ��ʦ�л�","name":"��ħ��ʿ",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
set_name(order[random(13)]+npc["name"]+NOR,({ npc["id"] }));    
set("nickname",(HIW+npc["title"])+NOR);
	set("magicgift",1+random(6));
	set("zhuanbest",1);
	set("magicset",1);
       set("long",
"һֻ���µ�ħ��ʦ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
        set("combat_exp",48000000+random(8000000));
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
        set("no_get",1);
	set_skill("force",550+random(300));
	set_skill("huntian-qigong",550+random(300));
	map_skill("force", "huntian-qigong");
b=84600+random(86000);
a=87600+random(85000);
d=95+random(60);
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
	set_temp("apply/armor",2500);
	set_temp("apply/damage",2400);

     set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
           }) );
if (random(2)==0)
{
     map_skill("spells", "magic-fire");
        set("chat_chance_combat", 90);
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
        set("chat_chance_combat", 90);
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

//ob->apply_condition("ill_dongshang",10);
//ob->apply_condition("ill_fashao",10);
//ob->apply_condition("ill_kesou",10);
//ob->apply_condition("ill_shanghan",10);
//ob->apply_condition("ill_zhongshu",10);
//ob->apply_condition("ice_poison",10);
//ob->apply_condition("xx_poison",10);
//ob->apply_condition("cold_poison",10);
//ob->apply_condition("flower_poison",10);
//ob->apply_condition("rose_poison",10);
//ob->apply_condition("scorpion_poison",10);
  if ( random(me->query("combat_exp"))>(int)ob->query("combat_exp")/3)
{
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        ob->apply_condition("new_poison2", 8); 
        tell_object(ob, HIG "����ñ����еĵط�һ��������\n" NOR );
}
}
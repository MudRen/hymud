#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIR"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"撒拉曼達"NOR, ({ "salamander"}));
	set("magicgift",1);
	set("magicset",1);
       set("title",HIR"火之妖神"NOR);
       set("zhuanbest",1);
       set("long",
"一位可怕的火之妖神。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",50000+random(500));
	set("combat_exp",30000000+random(8000000));
        set_skill("force",900+random(300));
	set_skill("unarmed",900+random(300));
	set_skill("sword",900+random(300));
	set_skill("club",900+random(300));
	set_skill("whip",900+random(300));
	set_skill("throwing",900+random(300));
	set_skill("spells",900+random(300));
	set_skill("parry",900+random(300));
      set_skill("magic-unarmed", 900+random(200));
      set_skill("magic-sword", 900+random(200));
      set_skill("magic-fire", 900+random(200));
      set_skill("magic-water", 900+random(200));
      set_skill("magic-ice", 900+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-fire");
      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
        set("no_get",1);
b=3900000+random(960090);
a=3900000+random(980900);
d=70+random(70);
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
	set_temp("apply/attack",250);
	set_temp("apply/defense",250);
	set_temp("apply/armor",4600);
	set_temp("apply/damage",4600);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: perform_action, "spells.summon" :),
               (: perform_action, "spells.light" :),
               (: perform_action, "spells.fireball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.immolation" :),
               (: perform_action, "spells.firebolt" :),
               (: perform_action, "spells.meteor" :),                                                            
               (: perform_action, "spells.incinerate" :),                                                                                                                     
                (: big_blowing :),
                (: big_blowing :),   
        }) );
  // 物品奖励
	        set("bonus", random(100000)+9000);
	set("killer_reward", ([
                "/clone/magic/obj/waterarmor"   :   500,
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&60"   :   5000,
                "GE&6"   :  5000,
                "JD&7"   :  5000,
                "YC&4"   :  5000,
                "WG&4"   :  5000,
                "KS&7"   :  2600,
                "BL&8"   :  2600,
                "YW&5"   :  2600,
                "YA&5"   :  2600,
                "TW&480"   :  2000,
                "TA&480"   :  2000,
               "TZ&0"   :  1500,
               "TZ&1"   :  1200,
               "TZ&2"   :  1100,	
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


int big_blowing()
{
        message_vision(HIR "$N" HIR "招呼火龙，全身发出鲜红的红芒，"
                       "火龙来了！！\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}


int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "打出漫天的一条火龙．．．．．．你吓的不能动了！！！\n" NOR,
                       this_object());

                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 20000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && userp(inv[i]))
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 0;
                        inv[i]->apply_condition("new_poison3", 10); 
                        inv[i]->start_busy(2);
                        inv[i]->receive_wound("qi", dam/2);
                        inv[i]->receive_wound("jing", dam/3);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        if (me->is_busy()) me->start_busy(1);
        
        damage = 5000 + random(5000);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIR "$N" HIR "“哈”的一声吐出一团火炎，登时令$n"
               HIR "受到了烧伤。\n" NOR;
}
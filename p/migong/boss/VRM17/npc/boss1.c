#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIB"", ""HIW"", ""HIB"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"������"NOR, ({ "lakshi"}));
if (random(2)==0)
	set("magicgift",1);
else 	set("magicgift",2);
	set("magicset",1);
       set("title",HIB"ˮ֮����ʹ"NOR);
       set("zhuanbest",1);
       set("long",
"һλ���µ�ˮ֮����ʹ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",29000000+random(8000000));
        set_skill("force",900+random(300));
	set_skill("unarmed",900+random(300));
	set_skill("sword",900+random(300));
	set_skill("club",900+random(300));
	set_skill("whip",900+random(300));
	set_skill("throwing",900+random(300));
	set_skill("parry",900+random(300));
      set_skill("magic-unarmed", 900+random(200));
      set_skill("magic-sword", 900+random(200));
      set_skill("magic-fire", 900+random(200));
      set_skill("magic-water", 900+random(200));
      set_skill("magic-ice", 900+random(200));
set_skill("spells",900+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-water");
      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
        set("no_get",1);
b=3500000+random(960090);
a=3500000+random(980900);
d=60+random(60);
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
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.zeroring" :),                                                            
                (: big_blowing :),
                (: big_blowing :),   
        }) );
	        set("bonus", random(100000)+8000);
	set("killer_reward", ([
                "/clone/magic/obj/sword12"   :   500,
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
                "KS&7"   :  2500,
                "BL&8"   :  2500,
                "YW&5"   :  2500,
                "YA&5"   :  2500,
                "TW&480"   :  2000,
                "TA&480"   :  2000,
"TZ&0"   :  1500,
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
        message_vision(WHT "$N" WHT "��������ٻ�������������ȫ��תΪѩ�׵ľ�ɫ��"
                       "������ճ����˺�������\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}


int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "���һ�ɱ�������森������������������ƺ��������ᣡ����\n" NOR,
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
                        inv[i]->start_busy(2);
                        inv[i]->apply_condition("new_poison4", 10); 
                        inv[i]->receive_wound("qi", dam/2);
                        inv[i]->receive_wound("jing", dam/3);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
}
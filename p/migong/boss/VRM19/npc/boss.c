#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""YEL"", ""HIW"", ""YEL"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"����"NOR, ({ "tero"}));
	set("magicgift",4);
	set("magicset",1);
       set("title",YEL"��ؾ���"NOR);
       set("zhuanbest",1);
       set("long",
"һλ���µĴ�ؾ���\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	set("combat_exp",50000000+random(8000000));
        set_skill("force",1290+random(300));
	set_skill("unarmed",1290+random(300));
	set_skill("sword",1290+random(300));
	set_skill("club",1290+random(300));
	set_skill("whip",1290+random(300));
	set_skill("throwing",1290+random(300));
	set_skill("spells",1200+random(300));
	set_skill("parry",1290+random(300));
      set_skill("magic-unarmed", 1250+random(200));
      set_skill("magic-sword", 1250+random(200));
      set_skill("magic-fire", 1200+random(200));
      set_skill("magic-earth", 1250+random(200));
      set_skill("magic-ice", 1260+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-earth");
      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
        set("no_get",1);
	set_skill("force",1250+random(300));
	set_skill("huntian-qigong",1250+random(300));
	map_skill("force", "huntian-qigong");
b=4569000+random(966000);
a=4569000+random(968000);
d=150+random(80);
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
	set_temp("apply/armor",6600);
	set_temp("apply/damage",6600);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.stab" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.Attach" :),
               (: perform_action, "spells.missile" :),
               (: perform_action, "spells.quake" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.Dintfield" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
        }) );

// ��Ʒ����
	        set("bonus", random(60000)+39900);
	set("killer_reward", ([
                "/clone/magic/obj/airboot"   :   500,
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&5"   :  8000,
               "KS&6"   :   8000,
                "BL&6"   :  8000,
                "RI&60"   :   6000,
                "GE&6"   :  6000,
                "JD&7"   :  6000,
                "YC&4"   :  6000,
                "WG&4"   :  6000,
                "KS&7"   :  3800,
                "BL&8"   :  3800,
                "YW&5"   :  3800,
                "YA&5"   :  3800,
                "TW&480"   :  2000,
                "TA&480"   :  2000,
               "TZ&0"   :  1600,
               "TZ&1"   :  1300,
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
        message_vision(YEL "$N" YEL "�Ӵ�����ٻ������ص������������Ĵ��ð���˸��ֶ�����"
                       "������س����˶�������\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
        remove_call_out("hurting");
        call_out("hurting", 3);
        return 1;
}


int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIY "$N" HIY "���һ�����̵Ķ��森��������������ڵأ�����\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 30000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && userp(inv[i]))
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 10;
                       inv[i]->start_busy(2);
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
                        inv[i]->apply_condition("new_poison6", 8);
                        inv[i]->apply_condition("tmqidu_poison", 1);
                        inv[i]->apply_condition("sanxiao_poison",3);
                        inv[i]->apply_condition("wuhudu_poison",3);
                        inv[i]->apply_condition("qx_snake_poison",3);
                        inv[i]->apply_condition("baituo_poison",3);
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
        return HIG "$N" HIG "��������һ���³�һ����ɫ�Ķ�������ʱ��$n"
               HIG "�ܵ��˶��ˡ�\n" NOR;
}
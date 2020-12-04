#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""HIC"", ""HIC"", ""HIW"", ""HIC"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"ɳ��˹"NOR, ({ "saras"}));
	set("magicgift",3);
	set("magicset",1);
       set("title",HIC"��ħ��"NOR);
       set("zhuanbest",1);
       set("long",
"һλ���µ���֮ħ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	set("combat_exp",40000000+random(8000000));
        set_skill("force",1100+random(300));
	set_skill("unarmed",1100+random(300));
	set_skill("sword",1100+random(300));
	set_skill("club",1100+random(300));
	set_skill("whip",1100+random(300));
	set_skill("throwing",1100+random(300));
	set_skill("spells",1100+random(300));
	set_skill("parry",1100+random(300));
      set_skill("magic-unarmed", 1100+random(200));
      set_skill("magic-sword", 1100+random(200));
      set_skill("magic-fire", 1100+random(200));
      set_skill("magic-earth", 1100+random(200));
      set_skill("magic-ice", 1160+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-ice");
      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
        set("no_get",1);
	set_skill("force",1150+random(300));
	set_skill("huntian-qigong",1150+random(300));
	map_skill("force", "huntian-qigong");	
b=4555000+random(966000);
a=4555000+random(968000);
d=85+random(80);
set("str",d);
set("dex",80+d);
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
	set_temp("apply/armor",5600);
	set_temp("apply/damage",5600);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               (: perform_action, "spells.invisibility" :),
               (: perform_action, "spells.lightningball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.implosion" :),
               (: perform_action, "spells.lightningbolt" :),
               (: perform_action, "spells.stun" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.holylightning" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
        }) );
// ��Ʒ����
	        set("bonus", random(50000)+39900);
	set("killer_reward", ([
                "/clone/magic/obj/earthshield"   :   1500,
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&4"   :  8000,
               "KS&5"   :   8000,
                "BL&5"   :  8000,
                "RI&60"   :   5000,
                "GE&6"   :  5000,
                "JD&7"   :  5000,
                "YC&4"   :  5000,
                "WG&4"   :  5000,
                "KS&7"   :  2680,
                "BL&8"   :  2680,
                "YW&5"   :  2680,
                "YA&5"   :  2680,
                "TW&480"   :  2000,
                "TA&480"   :  2000,
               "TZ&0"   :  1580,
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
        message_vision(HIC "$N" HIC "���޾��������,��ȡ�����������������"
                       "����е�����䣡��\n" NOR, this_object());
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
        
        message_vision(HIC "$N" HIC "���һ���ߴ��ޱȵ��������������������Ϊ֮һ��������\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 25000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && userp(inv[i]))
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 10;
                        inv[i]->start_busy(3);
                        inv[i]->apply_condition("new_poison5", 3); 
                        inv[i]->apply_condition("new_poison4", 1); 
                        inv[i]->receive_wound("qi", dam/2);
                        inv[i]->receive_wound("jing", dam/3);
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->clear_condition();
                        if (this_object()->query("qi",1) < this_object()->query("max_qi",1))
{
        message_vision(HIC "$N" HIC "�ڵ�������Ѫ�õ��˻ָ�����\n" NOR,this_object());
                        	this_object()->add("qi",dam);
                        if (this_object()->query("eff_qi",1) < this_object()->query("max_qi",1))
                        	this_object()->add("eff_qi",dam);
}                        

                        if (this_object()->query("jing",1) < this_object()->query("max_jing",1))
{
        message_vision(HIC "$N" HIC "�ڵ����о����õ��˻ָ�����\n" NOR,this_object());
                        	this_object()->add("jing",dam);
                        if (this_object()->query("eff_jing",1) < this_object()->query("max_jing",1))
                        	this_object()->add("eff_jing",dam);
}                        


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
        return HIC "$N" HIR "��������һ���³�һ�����磬��ʱ��$n"
               HIC "�ܵ��˵��ˡ�\n" NOR;
}
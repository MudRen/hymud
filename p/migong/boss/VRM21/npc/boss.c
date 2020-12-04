#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIB"", ""HIG"", ""RED"", ""MAG"", ""HIB"", ""HIB"", ""HIB"", ""HIB"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"÷��˹��.����˹"NOR, ({ "Mephisto"}));
if (random(2)==0)
	set("magicgift",5);
else 	set("magicgift",6);
	set("magicset",1);
       set("title",HIB"����֮׹��ʹ"NOR);
       set("zhuanbest",1);
       set("long",
"һλ���µĽ���֮׹��ʹ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
set("combat_exp",78000000+random(8000000));
        set_skill("force",1550+random(300));
	set_skill("unarmed",1550+random(300));
	set_skill("sword",1550+random(300));
	set_skill("club",1550+random(300));
	set_skill("whip",1550+random(300));
	set_skill("throwing",1550+random(300));
	set_skill("parry",1550+random(300));
set_skill("spells",1600+random(300));
      set_skill("magic-unarmed", 1550+random(300));
      set_skill("magic-sword", 1550+random(200));
      set_skill("magic-dark", 1660+random(200));
      set_skill("magic-light", 1660+random(200));
      set_skill("magic-ice", 1660+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-dark");
      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
        set("no_get",1);
      set_skill("magic-dark", 1700+random(800));
      set_skill("magic-light", 1700+random(800));
      set_skill("magic-earth", 1600+random(300));
      set_skill("magic-ice", 1600+random(300));
      set_skill("magic-water", 1600+random(300));
      set_skill("magic-fire", 1600+random(300));
      set_skill("magic-unarmed", 1600+random(300));
      set_skill("magic-sword", 1600+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
	set_skill("force",1650+random(300));
	set_skill("huntian-qigong",1650+random(300));
	map_skill("force", "huntian-qigong");
b=6889000+random(966000);
a=6889000+random(968000);
d=170+random(80);
set("str",d);
set("dex",140+d);
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
    (: perform_action, "spells.nuclea" :),
    (: perform_action, "spells.darkstorm" :),
    (: perform_action, "spells.darkwind" :),
    (: perform_action, "spells.darkmetor" :),
    (: perform_action, "spells.dragon" :),
    (: perform_action, "spells.castigate" :),
                (: big_blowing :),
                (: big_blowing :), 
 }) );
 
 	set("bonus", random(200000)+9000);
	set("killer_reward", ([
		"/clone/magic/obj/darksword"   :   500,
		"FI&/clone/box/gbox"   :   10000,
		"RI&60"   :   6000,
		"GE&6"   :  6000,
		"KS&9"   :   6000,
		"BL&8"   :  6000,
		"RI&60"   :   6000,
		"GE&6"   :  6000,
		"JD&6"   :  6000,
		"YC&4"   :  6000,
		"WG&4"   :  6000,
		"KS&7"   :  6000,
		"BL&8"   :  6000,
		"YW&5"   :  6000,
		"YA&5"   :  6000,
		"TW&300"   :  6000,
		"TA&300"   :  6000,
    "TZ&0"   :  2800,
    "TZ&1"   :  2400,
    "TZ&2"   :  2200,	
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
        message_vision(HIB "$N" HIB "��������ջ���һ����â�ǣ�� ���ɣ���а�����������һ�У�"
                       "���ͻȻ�����ڣ���\n" NOR, this_object());
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
        
       message_vision(HIY "$N" HIB "���һ���޴�ĺ�ɫ������������������ڰ��鲼��أ�����\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 35000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && userp(inv[i]))
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 10;
                       inv[i]->start_busy(2);
if (this_object()->is_busy()) this_object()->start_busy(1);
	this_object()->apply_condition("new_poison8", 8);
	this_object()->clear_condition();
                        inv[i]->apply_condition("new_poison2", 8);
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
        
        damage = 7000 + random(7000);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        ob->apply_condition("new_poison1", 2); 
        ob->apply_condition("new_poison2", 8); 
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "���š���һ�������һ���ڰ����������ʱ��$n"
               HIB "�ܵ��˰�Ӱ�˺���\n" NOR; 
}
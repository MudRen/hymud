#include <ansi.h>
inherit BOSS;
int big_blowing();
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
//	npc=data[random(sizeof(data))];
if (random(2)==0)
   set_name(order[random(13)]+"����"NOR, ({ "xyanhu"}));
else
   set_name(order[random(13)]+"���"NOR, ({ "spraydew"}));
set("magicgift",1+random(6));
        set("title",HIW"��֮�ػ���"NOR);
	set("magicgift",1+random(6));
	set("zhuanbest",1);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
	set("magicset",1);
       set("long",
"���������ػ���֮һ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",185000000+random(8000000));
        set_skill("force",2690+random(300));
	set_skill("unarmed",2690+random(300));
	set_skill("sword",2690+random(300));
	set_skill("club",2690+random(300));
	set_skill("force",2690+random(300));
	set_skill("whip",2690+random(300));
	set_skill("throwing",2690+random(300));
	set_skill("parry",2690+random(300));
      set_skill("magic-dark", 2690+random(300));
      set_skill("magic-light", 2690+random(300));
      set_skill("magic-earth", 2690+random(300));
      set_skill("magic-ice", 2690+random(300));
      set_skill("magic-water", 2690+random(300));
      set_skill("magic-fire", 2690+random(300));
      set_skill("magic-unarmedboss", 2690+random(300));
      set_skill("magic-swordboss", 2690+random(300));
      map_skill("sword", "magic-swordboss");
      map_skill("unarmed", "magic-unarmedboss");
      map_skill("parry", "magic-unarmedboss");
      set_skill("jiuyin-zhengong", 2680+random(300));
      set_skill("jiuyin-shenfa", 2680+random(200));
      set_skill("dafumo-quan", 2680+random(300));
      set_skill("jiuyin-shenzhang", 2680+random(300));
      set_skill("jiuyin-shenzhua", 2680+random(300));
      set_skill("xuanyin-jian", 2680+random(300));
      set_skill("yinlong-bian", 2680+random(300));
      set_skill("xuanyin-jian", 2680+random(300));
      map_skill("dodge", "jiuyin-shenfa");
      map_skill("force", "jiuyin-zhengong");
      map_skill("strike", "cuixin-zhang");
      map_skill("claw", "jiuyin-shenzhua");
        set("no_get",1);
b=9958000+random(2568000);
a=9988000+random(2568000);
d=200+random(60);
set("str",d);
set("dex",130+d);
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

set("shen",-100000);
        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/armor",9800);
	set_temp("apply/damage",9600);
if (random(2)==0)
{
     map_skill("spells", "magic-light");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
               (: perform_action, "spells.cure lightangel" :),
               (: perform_action, "spells.delete" :),
               (: perform_action, "spells.holyword" :),
               (: perform_action, "spells.moonlight lightangel" :),
               (: perform_action, "spells.sunbolt" :),
               (: perform_action, "spells.sunfield" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.sunarrow" :),                                                            
                (: big_blowing :),
                (: big_blowing :), 
	(: command("use huoqiang") :),
        }) );
}
else 
{
     map_skill("spells", "magic-ice");
        set("chat_chance_combat", 99);
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
	(: command("use huoqiang") :),
        }) );
        }

// ��Ʒ����
	set("bonus", random(200000)+19000);
	set("killer_reward", ([
		"FI&/clone/box/gbox"   :   10000,
		"GE&7"   :  7000,
		"KS&9"   :   7000,
		"BL&9"   :  7000,
		"RI&60"   :   7000,
		"GE&7"   :  7000,
		"JD&7"   :  7000,
		"YC&5"   :  7000,
		"WG&5"   :  7000,
		"YW&5"   :  7000,
		"YA&5"   :  7000,
		"TW&480"   :  7000,
		"TA&480"   :  7000,
    "TZ&0"   :  7000,
    "TZ&1"   :  7000,
    "TZ&2"   :  7000,	
	]));
   setup();

carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/box/new2/36");	
	carry_object("/clone/box/new2/35");		
	carry_object("/clone/box/new2/34");		
	carry_object("/clone/box/new2/36");	
	carry_object("/clone/box/new2/35");		
	carry_object("/clone/box/new2/34");		
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") )
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
        call_out("check",0);
        }
}



void check()
{
        object ob=this_object();
        object me=this_player();
    
     if (!ob)
     {
     remove_call_out("check");
     return;
     }

     if (!me)
     {
     remove_call_out("check");
     return;
     }


     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
     
if (ob->is_busy() && ob->is_fighting())
{
        message_vision(HIW"$N"HIW"����ʥ��һ�����ָֻ����ж���\n",ob,me);
        ob->interrupt_me();
        ob->start_busy(1);
        ob->start_busy(0);
ob->set_temp("apply/intelligence", 200);
ob->set_temp("apply/strength",200);
ob->set_temp("apply/dexerity",200);
ob->set_temp("apply/constitution",200);
ob->set_temp("apply/karey", 200);
ob->set_temp("apply/percao", 200);	
ob->set_temp("apply/armor", 9000);
ob->set_temp("apply/defense", 200);
ob->set_temp("apply/attack", 200);
ob->set_temp("apply/damage", 9000);     
	if((int)ob->query("qi") < (int)ob->query("max_qi")/10)
        {
        ob->add("qi",ob->query("max_qi")/12);
        ob->add("eff_qi",ob->query("max_qi")/12);
        }
ob->clear_condition();
}

        remove_call_out("check");
        call_out("check",1+random(3));
}




int big_blowing()
{
        message_vision(HIY "$N" HIY "��������ջ���һ����â�ǣ�� ���ɣ������޵���������һ�У�"
                       "���ͻȻ�����ʰ�쵣���\n" NOR, this_object());
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
        
              message_vision(HIY "$N" HIY "���һ���޴����ʳ��������������������������鲼��أ�����\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 48000 / num;
        
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
                        inv[i]->apply_condition("new_poison7", 8);
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
        
        damage = 9888 + random(9888);
        damage -= ob->query_temp("apply/reduce_cold");
        if (damage < 0) damage = 0;
        ob->apply_condition("new_poison2", 2); 
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIY "$N" HIY "���š���һ������˼�����֮���� !!����ʱ��$n"
               HIY "�ܵ����˺���\n" NOR; 
}
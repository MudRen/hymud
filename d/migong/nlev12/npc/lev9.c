// migong lev12  ���ǽ� ������

#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc.c"

string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",

"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});


void create()
{
  
       int i = random(sizeof(names));
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "mo tou" , "tou" }));
 
set("title", RED"��ħͷ"NOR);
   set("gender", "����" );
 set("long",
"�书��ǿ���ĺ����������ְ��ࡣ\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",6000+random(3000));
  set("max_jing",6000+random(3000));
  set("max_sen",3000+random(3000));
  set("max_neili",13000+random(3000));
  set("max_mana",3000+random(3000));
  set("eff_neili",13000+random(3000));
  set("neili",3000+random(3000));
        set("per", 1);
        set("age", 52);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 7000000+random(2000000));
                 set_skill("strike", 400+random(60));

set_skill("xuantian-wuji", 400+random(60));

set_skill("art", 400+random(60));

set_skill("force", 400+random(60));
set_skill("sword", 400+random(60));

set_skill("parry", 400+random(60));

set_skill("dodge", 400+random(60));

set_skill("liangyi-jian", 400+random(60));

set_skill("kunlun-shenfa", 400+random(60));

set_skill("kunlun-zhang", 400+random(60));

  
        map_skill("sword", "liangyi-jian");
  
      map_skill("parry", "liangyi-jian");

 map_skill("force", "xuantian-wuji");

 map_skill("dodge", "kunlun-shenfa");
 
map_skill("unarmed"  , "kunlun-zhang");
prepare_skill("unarmed", "kunlun-zhang");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               
    (: perform_action, "sword.jianqin" :),
	
      (: perform_action, "sword.juedi" :),
	
(: perform_action, "sword.feixue" :),
	
       (: perform_action, "strike.diezhang" :),
	
     (: exert_function, "recover" :),
   (: command("wield jian") :),
  (: exert_function, "powerup" :),
  }) );
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
 
          set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
     set("chat_chance", 30);
        set("chat_msg", ({
		(: command("get silver") :),
		(: command("get gold") :),
		(: command("get coin") :),
                (: random_move :),
           }) );

        setup();
 initlvl(300+random(70));
        carry_object("/d/migong/obj/cloth")->wear();
    
//   carry_object("/d/migong/obj/sword")->wield();
	
    carry_object("/d/migong/obj/sword");
	
add_money("silver", random(10));


}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
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
        object ob, me, corpse;int exp,pot;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;    
             me->add("score",1);
        me->add("shen",10);
        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
exp=50+random(20);
        if((int)me->query("combat_exp") < 12000000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "�����"+exp+"�㾭���"+pot+"��Ǳ�ܡ�\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}
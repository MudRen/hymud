// migong lev6 ��ɽ�ȷ� ����

#include <ansi.h>

inherit NPC;


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
 ({ "man" }));
 
set("title", HIC"����ͽ"NOR);
   set("gender", "����" );
 set("long",
"����ʦ�ţ����������ķ�ͽ��\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",1500+random(1500));
  set("max_jing",1500+random(1500));
  set("max_sen",1500+random(1500));
  set("max_neili",1500+random(1500));
  set("max_mana",1500+random(1500));
  set("eff_neili",1500+random(1500));
  set("neili",1500+random(1500));
        set("per", 1);
        set("age", 22);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 1200000+random(500000));
                 set_skill("unarmed", 210+random(40));

set_skill("chousui-zhang", 210+random(40));

set_skill("huagong-dafa", 210+random(40));

set_skill("force", 210+random(40));

set_skill("parry", 210+random(40));

set_skill("dodge", 210+random(40));

set_skill("tianshan-zhang", 210+random(40));

set_skill("staff", 210+random(40));

set_skill("zhaixinggong", 210+random(40));

  
        map_skill("staff", "tianshan-zhang");
  
      map_skill("parry", "tianshan-zhang");

 map_skill("force", "huagong-dafa");

 map_skill("dodge", "zhaixinggong");
 
map_skill("unarmed"  , "chousui-zhang");
prepare_skill("unarmed", "chousui-zhang");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
               
      (: perform_action, "staff.hushen" :),
	
  (: perform_action, "unarmed.tianshan" :),
	
        (: exert_function, "powerup" :),
     (: exert_function, "recover" :),
    }) );
            set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
 
          set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/shezhang")->wield();
	
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
 exp=8+random(5);
        if((int)me->query("combat_exp") < 3500000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "�����"+exp+"�㾭���"+pot+"��Ǳ�ܡ�\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}

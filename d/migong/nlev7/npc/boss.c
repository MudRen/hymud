// migong lev7 boss

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
 ({ "pantu" }));
 
set("title", BLU"������ͽ"NOR);
   set("gender", "����" );
 set("long",
"���������ʮ���޺����������ַ��ɣ�Ϊ������ͨ����
�����Ѳ����ڴΡ�\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",36000+random(2000));
  set("max_jing",36000+random(2000));
  set("max_sen",36000+random(2000));
  set("max_neili",39000+random(2000));
  set("max_mana",33000+random(2000));
  set("eff_neili",19000+random(2000));
  set("neili",19000+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 2700000+random(500000));
                 set_skill("hand", 250+random(40));
set("no_get",1);
  set_skill("whip", 250+random(40));

  set_skill("riyue-bian", 250+random(40));

 set_skill("claw", 250+random(40));

set_skill("hunyuan-yiqi", 250+random(40));

set_skill("yijinjing", 250+random(40));

set_skill("force", 250+random(40));
set_skill("qianye-shou", 250+random(40));

set_skill("parry", 250+random(40));

set_skill("dodge", 250+random(40));

set_skill("shaolin-shenfa", 350+random(40));

set_skill("longzhua-gong", 350+random(40));

  
        map_skill("hand", "qianye-shou");
  
       map_skill("whip", "riyue-bian");

      map_skill("parry", "riyue-bian");

 map_skill("force", "yijinjing");

 map_skill("dodge", "shaolin-shenfa");
 
map_skill("claw"  , "longzhua-gong");
prepare_skill("hand", "qianye-shou");
prepare_skill("claw", "longzhua-gong");
set("chat_chance", 40);
        set("chat_msg", ({
                "������ͽ�е����Թ������ɣ���\n",
                                   }) );

 
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
              	
      (: perform_action, "claw.sanzhua" :),
	
       (: perform_action, "whip.fumoquan" :),
	
     (: perform_action, "whip.fumoquan" :),
	
    (: perform_action, "whip.chan" :),
	
       (: perform_action, "hand.qianshou" :),
	
          (: exert_function, "recover" :),
    (: exert_function, "jingang" :),
    (: command("wield bian") :),
 }) );
            set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
 
          set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
  
carry_object("/d/migong/obj/bian")->wield();
 
carry_object("/d/migong/obj/bian");
     
  	add_money("gold", random(6));


}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(3);
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
void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse,obj;
        int exp,pot,score,i;
        int maxpot;
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));

        if((int)me->query("combat_exp") < 6000000)   {
if (random(70) < 1)
{
             corpse=new("/clone/gem/gem");
             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+corpse->query("name")+"!"NOR"��\n");
             corpse->move(killer);
}        
        message("vision", me->name() + "Ϊ��������,������900�����600Ǳ�ܡ�\n", me);
        me->add("combat_exp",900);
        me->add("potential",600);
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));           
        destruct(ob);
        }
        destruct(ob);
        return;
}

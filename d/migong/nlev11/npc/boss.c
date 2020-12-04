// migong lev11  huoyan-dao

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
 ({ "sha shou" , "shou" }));
 
set("title", HIR"ɱ��֮��"NOR);
   set("gender", "����" );
 set("long",
"����ɱ�ֵ���ͷĿ��һֱ�ڰ��л�š�\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",39000+random(2500));
  set("max_jing",39000+random(2500));
  set("max_sen",390000+random(2500));
  set("max_neili",19000+random(2500));
  set("max_mana",9000+random(2500));
  set("eff_neili",19000+random(2500));
  set("neili",19000+random(5000));
        set("per", 1);
        set("age", 50);
set("no_get",1);
       set("jiali" , 50);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 6000000+random(2000000));
                 set_skill("strike", 360+random(60));

set_skill("longxiang", 360+random(60));

set_skill("xiaowuxiang", 360+random(60));

set_skill("force", 360+random(60));
set_skill("huoyan-dao", 360+random(60));
set_skill("parry", 360+random(60));

set_skill("dodge", 360+random(60));

set_skill("lamaism", 360+random(60));

set_skill("shenkong-xing", 360+random(60));

         map_skill("parry", "huoyan-dao");

 map_skill("force", "xiaowuxiang");

 map_skill("dodge", "shenkong-xing");
 
map_skill("strike"  , "huoyan-dao");
prepare_skill("strike", "huoyan-dao");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
             
   (: perform_action, "strike.fen" :),

     (: perform_action, "strike.xiuluo" :),
	
    (: perform_action, "strike.honglian" :),
	
     (: perform_action, "strike.fen" :),
	
     (: exert_function, "recover" :),	
       (: perform_action, "dodge.tianmaxingkong" :),

     (: exert_function, "shield" :),
     }) );
            set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
 
          set_temp("apply/armor", 250);
        set_temp("apply/damage", 250);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

add_money("gold", 30);
        

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
        int maxpot;
        int exp,pot,score,i; 
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;    
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N������Ѫ����,���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 12200000)   {

if (random(45) < 1)
{
             corpse=new("/clone/gem/gem");
             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+corpse->query("name")+"!"NOR"��\n");
             corpse->move(killer);
}        
        message("vision", me->name() + "Ϊ��������,������1500�����900Ǳ�ܡ�\n", me);
        me->add("combat_exp",1500);
        me->add("potential",900);
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));           
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));           

        destruct(ob);
        }
        destruct(ob);
        return;
}

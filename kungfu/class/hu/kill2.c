#include <ansi.h>


inherit NPC;


void create()
{
        set_name("Ѧȵ", ({ "xue que", "xueque" }));
	set("gender", "Ů��");
	set("title", HIB"ҩ���ȶ�ʦ��"NOR);
        set("shen_type", -1);
        set("age", 50);
        set("str", 30);
        set("con", 38);
        set("int", 20);
        set("dex", 26);
        set("per", 6);
        set("max_qi", 34400);
        set("max_jing", 32200);
        set("qi", 34400);
        set("jing", 32200);
        set("neili", 35500);
        set("max_neili", 35500);
        set("jiali", 135);
        set("combat_exp", 5200000);

        set_skill("force", 250);
	set_skill("shenlong-xinfa", 380);
        set_skill("dodge", 200);
	set_skill("yixingbu", 380);
        set_skill("hand", 250);
	set_skill("shenlong-bashi", 380);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 380);
        set_skill("parry", 250);
set_skill("claw", 300);
set_skill("strike", 300);
        set_skill("staff", 200);
        set_skill("sword", 200);
        set_skill("zhaosheshu", 380);
        set_skill("yangsheshu", 380);
	set_skill("shedao-qigong", 380);
	set_skill("literate", 200);
	set_skill("dulong-shenzhua", 380);
	set_skill("xuanming-zhang", 380);
        set("vendetta/authority",1);
        set_skill("leg",200);
        set_skill("shenlong-tuifa",380);
        

        map_skill("strike", "xuanming-zhang");
        map_skill("force",  "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
        map_skill("parry",  "dulong-shenzhua");
        map_skill("unarmed",  "dulong-shenzhua");
        map_skill("claw",  "dulong-shenzhua");
	map_skill("hand", "shenlong-bashi");
        prepare_skill("claw", "dulong-shenzhua");

             
  



        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({               
                (: perform_action, "claw.bao" :),
                (: perform_action, "claw.ju" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));



        set_temp("apply/attack", 180);
        set_temp("apply/damage", 180);
        set_temp("apply/armor", 180);



        setup();

        carry_object("/clone/cloth/baipao")->wear();
}

void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
              //me->add("score",1);        
        message_vision(RED"$Nһ��ŭ�𣬻�����Ѫֱ�������˳�ȥ!\n"NOR,ob,me);
        


        me->set_temp("killyao2",1);


               destruct(ob);
        return;
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

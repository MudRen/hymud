// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIR"�����"NOR, ({ "huo long" , "long" , "dragon" }));
                set("race", "Ұ��");
       set("long",
"һ���޴�������������Ż𣬿������㣬�������˹�����
���������������Ѩ����پ�������ѹ�֣�������ʮ�ֵؿ���
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",80000+random(20000));
  set("max_jing",80000+random(20000));
  set("max_sen",80000+random(20000));
  set("max_mana",80000+random(20000));
  set("max_neili",80000+random(20000));
set("neili",850000+random(20000));
      set("dex",120);
      set("con",100);
     set("str" ,100);
       set("no_get",1);
    set("age", 150);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 11000000+random(2000000));
            set_temp("apply/attack", 500);
        set_temp("apply/damage", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",500);
       set_skill("dodge", 600+random(100));

      set_skill("unarmed", 600+random(100));

       set_skill("dragon", 600+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
 }) );
     
   setup();

        

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
void unconcious()
{
    die();
}
void die()
{
        object corpse, killer,obj;
        int maxpot;
        int exp,pot,score,i; 
        string skill;
        object jla , jlb;
object me = query_temp("last_damage_from");
        if( !living(this_object()) ) revive(1);
        if( wizardp(this_object()) && query("env/immortal") ) return;

        this_object()->clear_condition();

        COMBAT_D->announce(this_object(), "dead");
        if( objectp(killer = query_temp("last_damage_from")) ) {
                set_temp("my_killer", killer->query("id"));
                COMBAT_D->killer_reward(killer, this_object());
        }

        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
if (!killer) return;    


        if (userp(killer) && (int)killer->query("combat_exp") < 20000000)
        {
if (random(15) < 1)
{
             jla=new("/clone/gem/gem");
             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
             jla->move(killer);
}
             message_vision("$N�õ�һ����������\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"HIR"������"NOR"��\n");
             jla=new("/d/migong/obj/dan3");
             jla->move(killer);
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));           
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));  
        message("vision", me->name() + "�ɹ���������������1600�����1250Ǳ�ܡ�\n", me);
        me->add("combat_exp",1600);
        me->add("potential",1250);                
               }

        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        this_object()->dismiss_team();
        destruct(this_object());
}

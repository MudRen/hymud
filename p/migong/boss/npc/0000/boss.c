// migong lev15

#include <ansi.h>

inherit BOSS;


void create()

{
    
   set_name(HIR"ǧ�������"NOR, ({ "huo long" , "long" , "dragon" }));
                set("race", "Ұ��");
       set("long",
"һ���޴�������������Ż𣬿������㣬�������˹�����
���������������Ѩ����پ�������ѹ�֣�������ʮ�ֵؿ���
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("qi",880000);
	       set("eff_qi",880000);
	       set("max_qi",880000);
set("jing",880000);
  set("eff_jing",880000);
  set("max_jing",880000);
set("neili",309999);
  set("max_neili",309999);
  set("max_sen",309999);
  set("max_mana",309999);
  set("jiali",2000);
      set("dex",80);
      set("con",80);
      set("int",80);
     set("str" ,80);
       set("no_get",1);
    set("age", 69);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 18000000);
            set_temp("apply/attack", 200);
        set_temp("apply/damage", 3200);
        set_temp("apply/armor", 3500);
        set_temp("apply/defence",200);
      set_skill("dodge", 800);
      set_skill("force", 800);
      set_skill("unarmed", 800);
      set_skill("dragon",850);
      set_skill("spells",850);
     set_skill("magic-old",800);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
    (: perform_action, "unarmed.penhuo" :),
    (: perform_action, "unarmed.tuwu" :),
    (: perform_action, "unarmed.yaoyao" :),
    (: perform_action, "spells.magic1" :),
    (: perform_action, "spells.magic2" :),
    (: perform_action, "spells.magic3" :),
    (: perform_action, "spells.magic4" :),
    (: perform_action, "spells.magic5" :),
    (: perform_action, "spells.magic6" :),
    (: perform_action, "spells.magic7" :),

 }) );


  set("bonus", random(40000)+5000);
	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   8000,
                "GE&3"   :  8000,
               "KS&3"   :   8000,
                "BL&3"   :  8000,
                "RI&30"   :   3000,
                "GE&3"   :  3000,
                "JD&4"   :  3000,
                "YC&1"   :  3000,
                "WG&1"   :  3000,
//               "KS&5"   :   300,
//                "BL&5"   :  300,
//                "YW&3"   :  500,
//                "YA&3"   :  500,
                "TW&280"   :  1000,
                "TA&280"   :  1000,
                "TZ&0"   :  100,
	]));
     
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
        //if(!userp(ob[i])) return;
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
        //ob->start_busy(2);
}
        remove_call_out("check");
        call_out("check",1+random(3));
}
int hit_ob(object me, object ob, int damage)
{
if (ob=me)
{
if (me->query("qi") < me->query("max_qi")/2)
{
me->add("qi",me->query("max_qi")/40);
me->add("eff_qi",me->query("max_qi")/40);
}
if (me->query("jing") < me->query("max_jing")/2)
{
me->add("jing",me->query("max_jing")/40);
me->add("eff_jing",me->query("max_jing")/40);
me->set("neili",me->query("max_neili"));
}
}
if (ob!=me)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n" NOR );
}
}

// migong lev15

#include <ansi.h>

inherit NPC;

int big_blowing();


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
	       set("qi",299000);
	       set("eff_qi",299000);
	       set("max_qi",299000);
set("jing",299000);
  set("eff_jing",299000);
  set("max_jing",299000);
set("neili",299999);
  set("max_neili",299999);
  set("max_sen",299999);
  set("max_mana",299999);
  
      set("dex",80);
      set("con",80);
      set("int",80);
     set("str" ,80);
       set("no_get",1);
    set("age", 999);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 25000000);
            set_temp("apply/attack", 200);
        set_temp("apply/damage", 2999);
        set_temp("apply/armor", 2500);
        set_temp("apply/defence",200);
      set_skill("taiji-shengong", 500);
      set_skill("parry", 500);
      set_skill("dodge", 500);
      set_skill("force", 500);
      set_skill("unarmed", 500);
      set_skill("dragon",850);
      set_skill("spells",850);
     set_skill("magic-old",850);
      map_skill("unarmed", "dragon");
map_skill("force", "taiji-shengong");
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
                (: big_blowing :),
                (: big_blowing :),                	
 }) );
        set("bonus", random(20000)+2000);
   setup();
        carry_object("/clone/money/gold")->set_amount(20+random(220));
        

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

int big_blowing()
{
        message_vision(HIB "$N" HIB "�ӻ��������������һ�ڻ�����ȫ��תΪ�ʺ�Ļ�ɫ��"
                       "���������ʹ��˼�������\n" NOR, this_object());
if (this_object()->is_busy()) this_object()->start_busy(1);
        remove_call_out("hurting");
        call_out("hurting", random(2) + 1);
        return 1;
}


int hurting()
{
        int dam, i , num;
        object *inv;
        
        message_vision(HIB "$N" HIB "�³�һ�ɳ�ɷٽ�Ļ��森������������������ƺ�����ȼ���ţ�����\n" NOR,
                       this_object());
                       
        inv = all_inventory(environment(this_object()));        

        num = sizeof(inv);       
        if (num < 1) num = 1;
        if (num > 5) num = 5;
        
        dam = 18000 / num;
        
        for (i=sizeof(inv)-1; i>=0; i--)
        {
                if (living(inv[i]) && inv[i] != this_object() && userp(inv[i]))
                {
                        dam -= inv[i]->query_temp("apply/reduce_wind");
                        if (dam <0) dam = 0;
                        
                        inv[i]->receive_wound("qi", dam);
                        inv[i]->receive_wound("jing", dam/3);
                        COMBAT_D->report_status(inv[i], 1);
                }
        }
        return 1;
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

if (!killer) return;
if (me->query("migong/lev15"))
{
if( !environment(me)->query("no_fight")
&& random(4)==1)
{
obj=new("/d/migong/obj/npct"); 
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц���������ʶ��һ������������! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}
else 
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		obj->test_robot(me);
}
}

if (!me->query("migong/lev15"))
{
me->set("migong/lev15",1);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "������Թ���ʮ���!"NOR"��\n", users());
exp = 500000+random(25000);
pot = exp/2;
score = random(300)+1650;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"�㱻�����ˣ�\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n"NOR);
i=random(8);
	if (i==7) {
        if ( me->query("per")< 60)
        {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
        }
	}
	else if (i==6) {
        if ( me->query("kar")< 60)
        {
	me->add("kar",1);tell_object(me,HIM"�Լ�һ�㸣Ե��\n"NOR);
        }
	}
	else if (i==5) {
        if ( me->query("dex")< 60)
        {
	me->add("dex",1);tell_object(me,HIM"�Լ�һ������\n"NOR);
        }
	}
	else if (i==4) {
        if ( me->query("str")< 60)
        {
	me->add("str",1);tell_object(me,HIM"�Լ�һ��������\n"NOR);
        }
	}
	else if (i==3) {
        if ( me->query("per")< 60)
        {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
        }
	}
	else if (i==2) {
        if ( me->query("kar")< 60)
        {
	me->add("kar",1);tell_object(me,HIM"�Լ�һ�㸣Ե��\n"NOR);
        }
	}
	else if (i==1) {
        if ( me->query("con")< 60)
        {
	me->add("con",1);tell_object(me,HIM"�Լ�һ����ǡ�\n"NOR);
        }
	}
	else if (i==0) {
        if ( me->query("int")< 60)
        {
	me->add("int",1);tell_object(me,HIM"�Լ�һ�����ԡ�\n"NOR);
        }
	}
	else if (me->query("per")< 100) {
	me->add("per",1);tell_object(me,HIM"�Լ�һ����ò��\n"NOR);
	}
}

        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
if (random(3)==0) environment(this_object())->set("already",1);
if (random(10) < 1)
{
             jla=new("/clone/gem/gem");
if (jla->query("level") >4
&& killer->query("combat_exp") > 38000000)
{
        jla=new("/clone/gem/gem");
jla->set_level(random(17),(random(2)+1));
}
             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
             jla->move(killer);
}

        if (userp(killer) && !environment(this_object())->query("already")
        && killer->query("combat_exp") < 38000000)
        {
             jla=new("/clone/gem/robe");
             message_vision("$N�õ�һ��ħ��ʦ�ۡ�\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
             jla->move(killer);
             jla=new("/clone/gem/ring"+random(10));
             message_vision("$N�õ�һ��ħ����ָ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
             jla->move(killer);
             jla=new("/clone/gem/gem");
if (jla->query("level") >4 && random(3)==0)
{
        jla=new("/clone/gem/gem");
}
if (jla->query("level") >4
&& killer->query("combat_exp") > 38000000)
{
        jla=new("/clone/gem/gem");
jla->set_level(random(17),(random(2)+1));
}
             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
             jla->move(killer);
             jla=new("/clone/gem/gem");
if (jla->query("level") >4 && random(3)==0)
{
        jla=new("/clone/gem/gem");
}

if (jla->query("level") >4
&& killer->query("combat_exp") > 38000000)
{
        jla=new("/clone/gem/gem");
jla->set_level(random(17),(random(2)+1));
}
if (jla->query("level") >6)
{
        jla=new("/clone/gem/gem");
jla->set_level(random(17),(random(2)+1));
}
             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
             jla->move(killer);
             jla=new("/clone/gem/gem");
if (jla->query("level") >4 && random(3)==0)
{
        jla=new("/clone/gem/gem");
jla->set_level(random(17),(random(2)+1));
}

if (jla->query("level") >4
&& killer->query("combat_exp") > 38000000)
{
        jla=new("/clone/gem/gem");
jla->set_level(random(17),(random(2)+1));
}

             message_vision("$N�õ�һ���������ı�ʯ��\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"+jla->query("name")+"!"NOR"��\n");
             jla->move(killer);

             message_vision("$N�õ�һ��ǧ������ס�\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"HIR"ǧ�������"NOR"��\n");
             jla=new("/d/migong/obj/jia3");
if (jla->query("level") >4 && random(3)==0)
{
        jla=new("/clone/gem/gem");
}

if (jla->query("level") >4
&& killer->query("combat_exp") > 38000000)
{
        jla=new("/clone/gem/gem");
jla->set_level(random(17),(random(2)+1));
}
             jla->move(killer);
             killer->add("combat_exp",4000);
              message_vision("$N�õ�һ��ǧ���������\n",killer);
             command("rumor "+killer->query("name")+"�õ�һ��"HIR"ǧ�������"NOR"��\n");
             jlb=new("/d/migong/obj/dan4");
             jlb->move(killer);
            
             }
environment(this_object())->set("already",1);
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        this_object()->dismiss_team();
        destruct(this_object());
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
}
        remove_call_out("check");
        call_out("check",1+random(3));
}
mixed hit_ob(object me, object ob, int damage_bouns)
{
	        int damage;
if (ob=me)
{
if (me->query("qi") < me->query("max_qi"))
{
me->add("qi",me->query("max_qi")/60);
me->add("eff_qi",me->query("max_qi")/60);
}
if (me->query("jing") < me->query("max_jing"))
{
me->add("jing",me->query("max_jing")/60);
me->add("eff_jing",me->query("max_jing")/60);
me->set("neili",me->query("max_neili"));
}
}
if (ob!=me && random(2)==0)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n" NOR );
}

else
{        
        damage = 1200 + random(2200);
        damage -= ob->query_temp("apply/reduce_fire");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "���𡱵�һ���³�һ���һ𣬵�ʱ��$n"
               HIB "��������һ������\n" NOR;

}
}




// migong lev15

#include <ansi.h>


inherit BOSS;

int big_blowing();


void create()

{
    	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(HIR"��.ǧ�������"NOR, ({ "huo long" , "long" , "dragon" }));
                set("race", "Ұ��");
       set("long",
"һ���޴�������������Ż𣬿������㣬�������˹�����
���������������Ѩ����پ�������ѹ�֣�������ʮ�ֵؿ���
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("qi",1800000);
	       set("eff_qi",1800000);
	       set("max_qi",1800000);
set("jing",1800000);
  set("eff_jing",1800000);
  set("max_jing",1800000);
set("neili",1899990);
  set("max_neili",1899990);

  
      set("dex",180);
      set("con",180);
      set("int",180);
     set("str" ,180);
       set("no_get",1);
    set("age", 999);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 125000000);
            set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 3500);
        set_temp("apply/defence",3500);
      set_skill("dodge", 900);
      set_skill("force", 900);
      set_skill("unarmed", 900);
      set_skill("dragon",950);
      set_skill("spells",950);
     set_skill("magic-old",1200);
      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");
      map_skill("spells", "magic-old");
      set_skill("taiji-shengong", 800);
      map_skill("force", "taiji-shengong");
    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 90);
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
set("bonus", random(52000)+8888);
// ��Ʒ���� ˵��
// ������� 10000Ϊ���,�ص�,5000Ϊ1/2����,����ԽС,����Ŀ���Խ��.
// �������йؼ����� FI ��ͷ��ʾΪ����ĳ���ض���Ʒ
// �������йؼ����� RI  ��ͷ��ʾΪ����ĳ����ָ %dΪ�ȼ�(10-60) 
// �������йؼ����� GE ��ͷ��ʾΪ����ĳ����ʯ %dΪ�ȼ�(1-8)
// �������йؼ����� JD ��ͷ��ʾΪ����ĳ��������������ʯ %dΪ�ȼ�(1-8)
// �������йؼ����� YC ��ͷ��ʾΪ����ҩ�� %dΪ��Ч����("����ȼ���Ч)
// �������йؼ����� WG ��ͷ��ʾΪ���䱦��װ�� %dΪ��Ч����
// �������йؼ����� KS ��ͷ��ʾΪ��������ÿ�ʯ %dΪ�ȼ�(1-10)
// �������йؼ����� BL ��ͷ��ʾΪ��������ò��� %dΪ�ȼ�(1-10)
// �������йؼ����� YW ��ͷ��ʾΪ���������������ʯ %dΪ�ȼ�(1-6)
// �������йؼ����� YA ��ͷ��ʾΪ��������������ʯ %dΪ�ȼ�(1-6)
// �������йؼ����� YW ��ͷ��ʾΪ���������������ʯ %dΪ�ȼ�(1-6)
// �������йؼ����� TW ��ͷ��ʾΪ����������� %dΪ�ȼ� (0-480)
// �������йؼ����� TA ��ͷ��ʾΪ���������� %dΪ�ȼ�(0-480)


	set("killer_reward", ([
                "FI&/clone/box/gbox"   :   10000,
                "RI&10"   :   5000,
                "GE&3"   :  5000,
               "KS&3"   :   5000,
                "BL&3"   :  5000,
                "RI&60"   :   3000,
                "GE&6"   :  3000,
                "JD&7"   :  3000,
                "YC&4"   :  3000,
                "WG&4"   :  3000,
                "KS&7"   :  1500,
                "BL&8"   :  1500,
                "YW&5"   :  1500,
                "YA&5"   :  1500,
                "TW&480"   :  1500,
                "TA&480"   :  1500,
                "TZ&0"   :  1500,	
	]));
	
b=2600000+random(660090);
a=2800000+random(680900);
d=50+random(60);
set("str",d);
set("dex",30+d);
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
                        inv[i]->receive_wound("jing", dam/2);
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
	ob->apply_condition("new_poison3", 10); 
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n" NOR );
}

else
{        
        damage = 1200 + random(2800);
        damage -= ob->query_temp("apply/reduce_fire");
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
        return HIB "$N" HIB "���𡱵�һ���³�һ���һ𣬵�ʱ��$n"
               HIB "��������һ������\n" NOR;

}
}




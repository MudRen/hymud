// lestat 2001


#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
            set_name("�������",({"yuqing"}));
                set("title", HIC"�������"NOR);
//        set("gender","����");
//        set("age", 60);
        set("str", 40);
        set("cor", 30);
                set("con", 30);
                set("cps", 30);
                set("spi", 30);
                set("int", 30);
//        set_temp("apply/damage", 125);
//        set_temp("apply/armor", 500);
            set_skill("unarmed", 100);
        
   set("combat_exp", 1000000);
   create_family("��ׯ��", 2, "����");
 
   setup();
   initlvl((200+random(280)),15);
   carry_object("/d/obj/cloth/baguapao")->wear();
//   carry_object("/d/obj/weapon/hammer/bahammer")->wield();
   carry_object("/d/obj/weapon/sword/qingfeng")->wield();


}

void copy_status(object me,object ob)
{
    me->set("name",ob->query("name"));
    me->set("gender",ob->query("gender"));
        me->set("age",ob->query("age"));
    me->set("nickname",ob->query("nickname"));
   
   me->set("max_qi",ob->query("max_qi"));
   me->set("eff_qi",ob->query("eff_qi"));
   me->set("qi",ob->query("qi"));

   me->set("max_jing",ob->query("max_jing"));
   me->set("eff_jing",ob->query("eff_jing"));
   me->set("jing",ob->query("jing"));

   me->set("max_jing",ob->query("max_jing"));
   me->set("eff_jing",ob->query("eff_jing"));
   me->set("jing",ob->query("jing"));

   me->set("max_neili",ob->query("max_neili")*5/4);
   me->set("neili",ob->query("neili")*5/4);
   me->set("force_factor",ob->query("force_factor")*5/4);

   me->set("max_neili",ob->query("max_neili")*5/4);
   me->set("neili",ob->query("neili")*5/4);
   me->set("mana_factor",ob->query("mana_factor")*5/4);
   me->set("combat_exp",ob->query("combat_exp")*5/4);
   me->set("combat_exp",ob->query("combat_exp")*5/4);
}

void die()
{
        message("vision",
                MAG "����һ�����죬����"+ name() + "����һ�Σ�����һ�����������ȥ��\n" NOR,environment(),
                this_object() );
        destruct(this_object());
}

int heal_up()
{
           if( environment() && (!is_fighting() )  ) {
                call_out("die", 1);
                return 1;
        }
      add("time", 1);
        return ::heal_up() + 1;
}

void invocation(object who)
{
   int i;
   object me,*enemy;

   me=this_object();
   message("vision",
     HIC +who->query("name")+"����:

         �����س��������أ�һͳ���������ţ����屾ͬ����ϣ�����ɽ���Ի��档��

         ֻ����������һ�����죬��ʱ��ǰ����һλ"+who->query("name")+"��\n" NOR,
     environment(),this_object());
   copy_status(me,who);
   enemy=who->query_enemy();
   i=sizeof(enemy);
   while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
   set("leader", (string)who->query("id"));
        set_leader(who);
}


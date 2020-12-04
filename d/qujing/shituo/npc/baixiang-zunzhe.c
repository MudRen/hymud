
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// baixiang-zunzhe.c...weiqi, 97.09.15.

inherit NPC;
#include "/d/migong/romnpc2.c"

void create()
{
   set_name("��������", ({"baixiang zunzhe", "baixiang", "zunzhe"}));
   set("title", "������ ��ħ��");
   set("gender", "����" );
   set("age", 43);
   set("per", 112);//no rongmao description.
   set("str", 50);
   set("long", "ʨ��ɽ����������\n��ƽ���µ������󣬿�������������˾����ᡣ\n");
   set("class", "yaomo");
   set("combat_exp", 53800000);
   set("attitude", "peaceful");
   create_family("��ѩɽ", 2, "����");


  set("str",100);
  set("dex",100);
   set("max_kee", 1200);
   set("max_jing", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 800);
   set("max_mana", 400);   
   set("force_factor", 60);
   set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);


   setup();
   initlvl((700+random(700)),38);

   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/obj/weapon/blade/yanblade")->wield();
}


void init()
{       
   object ob=this_player();

   ::init();
   if ( ((string)ob->query("gender")=="����") && ((int)ob->query("str") < 20) && (random(3) > 1) )
        {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
     command("kick " + ob->query("id"));
     command("say ���������");
     command("laugh");
     break;
   }
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

object taishang = new (__DIR__"pusa");
  if (ob)
  {
    ob->set_temp("obstacle/shituo2_killed",1);
    taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N�޿��κε���������ԭ����һֻ����\n",me);
  message_vision ("\n���������ߡ�\n",me);
  

::die();
}



void unconcious ()
{
  die ();
}
int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);

  ::kill_ob(ob);
}

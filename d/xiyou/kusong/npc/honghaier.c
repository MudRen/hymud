//Cracked by Roath
inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
int ask_niang(object me);
int do_yes();

int rank_me();

void create()
{
       set_name("�캢��", ({"honghai er","er"}));
	set("title", "ʥӤ����");
	set("long", "ţħ������ɲŮ�Ķ��ӣ��ڻ���ɽ��������һ��ñ��졣\n");
       set("gender", "����");
       set("age", 16);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("spi", 25);

       	set("attitude", "heroism");

        
  set("combat_exp", 22500000);

        set("eff_dx", -500000);
        set("nkgain", 500);

       	set("class","yaomo");
       	set("max_qi", 1600);
       	set("max_jing", 1600);
       	set("neili", 2500);
       	set("max_neili", 1600);
       	set("force_factor", 100);
       	set("max_neili", 1600);
       	set("neili", 2500);
       	set("mana_factor", 80);
       



	create_family("���ƶ�", 2, "��");

        set("inquiry", ([
               
                "���ȹ���": (: ask_niang :),
]) );


        setup();
        
if (random(2)==0)
     initlvl((290+random(390)),7);        
else initlvl((390+random(390)),59);
     
        carry_object("/d/qujing/nanhai/obj/huojianqiang")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}





void init()
{
        object ob = this_player();
        remove_call_out("check");
        call_out("check",1,ob);
        add_action("do_yes","ok");
}

void check(object ob)
{
        object where;
        if (!ob) return;
        where=environment(ob);
        if(ob->query("family/family_name") == "���ƶ�")
           return;
        if(ob->query("title") == "��ͨ����")
           return;
        if(ob->query_temp("kusong_killed") == 1)
           return;
        if ( random(10)==0 )
           {
        command("say ��λ����������Ե��");
        command("say ������ץ��һ�����У������������Գ������ϰ���");
        command("xixi");
        return;
            }

        if( present("jin che",where) || present("mu che",where)
        ||  present("shui che",where) || present("huo che",where) ||
            present("tu che",where) )
          {
if (userp(ob)) {
        kill_ob(ob);
        message_vision(HIR"ֻ���캢���ּ����г������л��ǹ��$Nһָ��\n"NOR,ob);
        message_vision(HIR"һ������������Ũ������$N��$N������ߡ�\n"NOR,ob);
        ob->move(__DIR__"guaishiya");
        ob->unconcious();
        }
}

}
int ask_niang(object me)
{
       me=this_player();
       command("jump");
       me->set_temp("ok",1);
       command("say ��ȥ������һ��������ok����\n");
       return 1;
}

int do_yes()
{
        object ob = this_player();
        if( ! ob->query_temp("ok") ) return 0;
        command("say ���ڼҵȺ򣬺�����ȥ��ء�");
        command("bye");
        destruct(this_object());
        return 1;
}

int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void announce_success (object who)
{
  int i;
  object honghaier= this_object();

  if (! who->query_temp("che1_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che2_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che3_broken"))
   {
    destruct (honghaier);
    return;
   } 
  if (! who->query_temp("che4_broken"))
   {
    destruct (honghaier);
    return;  
   } 
  if (! who->query_temp("che5_broken"))
   {
    destruct (honghaier);
    return;  
   } 
  honghaier->move(environment(who));
  who->set_temp("kusong_killed",1);
  message_vision (HIR"һ�ź�ɫ������ӿ�˹���,�캢��ͻȻ��������˳���.\n"NOR,who);
  message_vision (HIG"$N����"HIR+"���ǹ"HIG+"��$nһָ:�󵨳���,���ƻ��ҵ����г�.\n"NOR,honghaier,who);
  message_vision (HIG"ֻ��һ��$Nŭ��:�Ҿ�˵������ô��������.����������.\n"NOR,honghaier,who);
  who->command("bian");
  kill_ob(who);
}  
void die()
{
  object ob = query_temp("my_killer");
  object pusa = new ("/d/qujing/kusong/npc/pusa");
  object me = this_object();
  if (ob->query_temp("obstacle/hong_killed")) 
{
	::die();  
  return ;
}
  if (ob)
  {
    ob->set_temp("obstacle/hong_killed",1);
  pusa->announce_success (ob);
  destruct (pusa); 
  }
  message_vision(HIY"���ϴ��������������������캢�����������һ��Ϻ�ȥ��\n"NOR,ob);
::die();
}
void destruct_me (object me)
{
  destruct (me);
}


void unconcious ()
{
  die();
}

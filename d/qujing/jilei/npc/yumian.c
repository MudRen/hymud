//Cracked by Roath
// created 12/18/1997 by snowcat
int jilei();

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("���湫��", ({ "yumian gongzhu", "yumian", "gongzhu", "princess" }));
  set("title", "����ɽ");   
  set("long", "һλ������ֵ�Ů�ӣ�������Ť������֫��\n");
  set("gender", "Ů��");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("max_qi", 800);
  set("max_jing", 800);
  set("max_jing", 800);
  set("neili", 700);
  set("max_neili", 700);
  set("force_factor", 50);
  set("max_neili", 700);
  set("neili", 700);
  set("mana_factor", 50);
  set("combat_exp", 450000);
  set("combat_exp", 2500000);


	set("inquiry", ([
      "����ɽ"   : (:jilei:),
	]));

  setup();
    initlvl((500+random(500)),31);
  
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/jilei/obj/wufeng")->wield();
  carry_object("/d/obj/fabao/xiang-hebao");
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object li = new ("/d/qujing/jilei/npc/li");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/jilei_yumian_killed",1);
  li->announce_success (ob);
  destruct (li); 
  }
  message_vision ("\n$N�����ڵ�������������һֻ���꾫��\n",me);
  message_vision ("���꾫���ڵ��ϣ����ˡ�\n\n",me);
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
  object where = environment (me);
  object niumo = present ("niumo wang", where);

  set_temp("my_killer",ob);
  ::kill_ob(ob);
  if (niumo && !niumo->is_fighting())
    niumo->kill_ob(ob);
}

void init()
{
object ob, me;
me=this_object();
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {
remove_call_out("greeting");
call_out("greeting", 1, ob);
}
}
int jilei()
{
object who=this_player();
who->delete("betray");
return 1;
}


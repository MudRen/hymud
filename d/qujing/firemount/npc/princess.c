// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "���ȹ���"
inherit NPC;
#include "/d/migong/romnpc2.c"

int test_player (object who);

void create()
{
  string dir;
  set_name(NAME, ({"tieshan gongzhu", "gongzhu", "princess"}));
  set("title", "����ɽ������ɲ");
  set("gender", "Ů��");
  set("age", 28);
  set("per", 18);
  set("long", "����ɽ���ȹ�����\n");
  set("rank_info/respect", "���ڹ���");
  set("combat_exp", 4000000);
  set("combat_exp", 35000000);

  set_skill("snowsword", 380);
  set_skill("sword", 380);
  set_skill("dragonfight", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set_skill("spells", 80);
  set_skill("dragonstep", 80);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("max_jing", 221000);
  set("max_qi", 221000);
  set("max_jing", 221000);
  set("neili", 221500);
  set("max_neili", 221500);
  set("neili", 221500);
  set("max_neili", 221500);
  set("force_factor", 40);

  create_family("����ɽ�Ž���",2,"����");
  set("inquiry", ([
        "name":   "����ϸ��������˭��",
        "here":   "��������ȥ�ʣ�",
        "����ɽ": "�ߺߣ�ֻ��һ����������ס����ɽ��",
        "����":   "�Һ��ٰ��洫��������������ա�",
        "����":   (: test_player :),
      ]));

  setup();
  initlvl((490+random(490)),23);
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/firemount/";
  carry_object(dir+"obj/skirt")->wear();
  carry_object(dir+"obj/tieshan");
}

void init()
{
  ::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
}

void announce_success(object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp")<4000)
  {
    tell_object (who,"��ĵ��в�����ʲô��û�еõ���\n");
    return;
  }  

  if (who->query("obstacle/firemount") == "done")
  {
    tell_object (who,"���Ѿ�������һ�أ�ʲô���ò����ˣ�\n");
    return;
  }  
  i = random(800);
  message_vision (HIY "һ�ź�ɫ����Ʈ�������ֳ�"+NAME+"��\n" NOR,who);
  who->add("obstacle/number",1);
  who->set("obstacle/firemount","done");
  who->add("combat_exp",i+32000);
     who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"�����˻���ɽ�˰�����");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(i+32000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
  who->save();
  message_vision (HIY NAME+"��Ϊ��ɫ�����������ϱ�Ʈȥ��\n" NOR,who);
}

void return_object (object who, object ob)
{
  command ("give "+ob->query("id")+" to "+who->query("id"));
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "palm bone")
  {
    command("shake");
    call_out("return_object",1,who,ob);
    return 1;    
  }

  if (who->query("combat_exp")<4000)
  {
    message_vision ("$N��$nҡҡͷ������в�������Ž������Ǽٻ���\n",me,who);
    call_out("return_object",1,who,ob);
    return 1;
  }  

  message_vision ("$N���°Ž��ǣ���$n������л��\n",me,who);
  who->set("obstacle/firemount_bone",who->query("obstacle/firemount_bone")+1);
  if (who->query("obstacle/firemount_bone") > 9)
  {
    call_out("give_tieshan",1,me,who);
  }
  return 1;
}

void inform_player (string msg, object who)
{
  object me = this_object();

  message_vision (msg, me, who);
}


void unconcious ()
{
       object ob, me, corpse;
        object tieshan = present("tie shan",me);
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) me = query_temp("my_killer");
if (me)  
{
if (tieshan)
  {
    message_vision ("$N��Цһ�£�"+
                    "�ܲ���Ը��˫���������ȣ�����$n��\n",me,ob);
    tieshan->move(me);
    if (me->query("obstacle/firemount")!="done")
      me->set("obstacle/firemount","won");
  }
  else
  {
    message_vision ("$NΪ�ѵ�˵���������Ѿ������ˣ�"+
                    "����ʵ������������\n",me,ob);
  }
 }  
}

void die ()
{
           
::die();
}

void give_tieshan (object me, object who)
{
  object tieshan = present("tie shan",me);
  string msg;

  if (tieshan)
  {
    message_vision ("$N��Цһ�£�"+
                    "�ܲ���Ը��˫���������ȣ�����$n��\n",me,who);
    tieshan->move(who);
    if (who->query("obstacle/firemount")!="done")
      who->set("obstacle/firemount","won");
  }
  else
  {
    message_vision ("$NΪ�ѵ�˵���������Ѿ������ˣ�"+
                    "����ʵ������������\n",me,who);
  }
}

int test_player (object me)
{
  object who = this_player();
  string msg = "$N˵������λ"+RANK_D->query_respect(who);

  if (who->query("combat_exp")<4000)
  {
    inform_player (msg+"���в���������������������ĸ��ǣ�\n",who);
    return 1;
  }  

  if (who->query("obstacle/firemount") == "won" ||
      who->query("obstacle/firemount") == "done")
  {
    give_tieshan (me,who);
    return 1;
  }  

  if (who->query("obstacle/firemount") == "fight")
    inform_player (msg+"���������ã��������㣡\n",who);
  else    
    inform_player (msg+"����Ǹ�ˬ��֮�ˣ�������ϲ�����֣�\n",who);

  call_out ("fight_player",3,who);
  return 1;
}

void fight_player (object who)
{
  object me = this_object();

  message_vision ("$N������һ�ȣ�������\n",me,who);
  who->set("obstacle/firemount","fight");
  command("fight "+who->query("id"));
} 

int accept_fight(object who)
{
  object me;
  me = this_object();

  set_temp("my_killer",who);
  remove_call_out("check_fight");
  call_out("check_fight", 1, me, who);
  return 1;
}

void player_win (object me, object who)
{
  object tieshan = present("tie shan",me);
  string msg;

  message_vision ("$N��ʧɫ�����书�����书��\n",me);
  give_tieshan (me,who);
  call_out ("princess_disappear",2,me);
}

void player_lose (object me, object who)
{
  message_vision ("$Nһ㶣���æ��ס$n������˵����ʧ��ʧ��\n",me,who);
  call_out ("princess_disappear",2,me);
}

void check_fight (object me, object who)
{
  int my_kee, whos_kee;
  int my_max_kee, whos_max_kee;

  my_kee = me->query("qi");
  whos_kee = who->query("qi");
  my_max_kee = me->query("max_qi");
  whos_max_kee = who->query("max_qi");

  if (me->is_fighting())
  {
    call_out ("check_fight",2,me,who);
    return;
  }

  if (!present(who, environment(me)))
    return;

  if ((my_kee*100/my_max_kee) <= 50)
    player_win (me, who);
  else if ((whos_kee*100/whos_max_kee) <= 50)
    player_lose (me, who);

}

void princess_disappear (object me)
{
  message_vision ("$N�����ػ�Ϊ��ɫ������ʧ�ˡ�\n",me);
  destruct (me);
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (me->is_fighting())
  {
    message_vision ("$N��$nҡҡͷ��һ��һ����������Ҫһӵ���ϣ�\n",me,who);
    return 1;
  }
  
  if (who->query("obstacle/firemount") == "fight")
  {
    me->set("qi", me->query("max_qi"));
    me->set("eff_qi", me->query("max_qi"));
    return 0; // can fight
  }

  message_vision ("$N��$nҡҡͷ��Ҫ��ܳ�ȥ��\n",me,who);
  return 1;
}

void fight_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::fight_ob(ob);
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  if(arg && present(arg,environment(me))!=me) return 0;
  message_vision ("$N������������������˼������\n",who);
  call_out("no_cast",2,who,me);
  return 1;
}

void no_cast(object who, object me)
{
  message_vision ("ССɽ��������һƬ���ҵĻ�����$N����$nһЦ��\n",
                  me,who);
}

int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision ("$N���źڰ�����֡���һ��С�����������ĳ�����\n",who);
  call_out("no_steal",2,who,me);
  return 1;
}

void no_steal(object who, object me)
{
  message_vision ("$N����ס���ӣ���$n˵���������԰����ɡ�\n",me,who);
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if(arg && present(arg,environment(me))!=me) return 0;

  message_vision ("$N��Ȼ��¶ɱ���������غ���һ����ɱ��\n",who);
  call_out("no_kill",2,who,me);
  return 1;
}

void no_kill(object who, object me)
{
  message_vision ("ɲ�Ǽ�ɽ������С���׷��ϴ�����Χ��$N����һ�š�\n",who);
  message_vision ("ֻ��$N�����˵����������һ�ж����������ˡ�\n",me);
}


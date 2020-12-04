// written by smile 12/09/1998

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("����ɽ��", ({"heimian shanshen", "shanshen"}));
  set("gender", "����");
  set("age", 70);
  set("attitude", "friendly");
  set("combat_exp", 730000);
  set("per", 20);
  set_skill("dodge", 100);
  set_skill("force", 100);
  set_skill("parry", 100);

  set("max_jing",1800);
  set("max_qi",1800);
  set("max_jing",1800);
  set("neili",800);
  set("max_neili",800);
  set("max_neili",1280);
  set("force_factor",60);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}



void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 100000)
     {
        message_vision("����ɽ�����һ���֣����в���ǿ������Ȼ��\n",who);
    return;
     }
  if (who->query("obstacle/baigudong") == "done")
     {
       message_vision(HIY"����ɽ���$Nһ���֣���������ʧ��ɽ���У�\n" NOR,who);
    return;
     }
  if (! who->query_temp("obstacle/baigudong_nuzi_killed"))
    return;
  if (! who->query_temp("obstacle/baigudong_furen_killed"))
    return;
  if (! who->query_temp("obstacle/baigudong_gonggong_killed"))
    return;
  if (! who->query_temp("obstacle/baigudong_baigujing_killed"))
    return;
  i = random(600);
  who->add("obstacle/number",1);
     who->add("obstacle/potential",1);
  who->set("obstacle/baigudong","done");
  who->set("obstacle/sanda","done");
  who->add("combat_exp",i+4000);
    who->add("potential",i*7);
  who->add("mpgx",10);
  command("chat "+who->query("name")+"�׹Ƕ�����׹Ǿ���Ϊ�ķ������츣��");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}


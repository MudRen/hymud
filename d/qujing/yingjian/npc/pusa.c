//Cracked by Roath

inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
void create()
{
   set_name("����", ({ "jie di"}));
   set("title", "��������");
   set("long", @LONG
�������������ߡ�
LONG);
   set("gender", "����");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "ƶɮ");
   set("class", "bonze");
   set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_qi", 5000);
   set("max_jing", 5000);
   set("max_jing", 5000);
   set("neili", 4000);
   set("max_neili", 2000);
   set("force_factor", 145);
   set("max_neili", 3000);
   set("neili", 6000);
   set("mana_factor", 150);
   set("combat_exp", 2000000);
   set_skill("literate", 150);
  

   setup();
   initlvl((500+random(500)),1);
   carry_object("/d/qujing/nanhai/obj/sengpao")->wear();
   //carry_object("/d/qujing/nanhai/obj/budd_staff")->wield();

}

void announce_success (object who)
{
  int i;
  object horse=new("/d/qujing/yingjian/obj/horse");
  object here;
  object me = this_object();
  here=environment(who);

  if (who->query("combat_exp",1) < 1000000)
    return;
  if (who->query("obstacle/yj") == "done")
    return;
  if (! who->query_temp("obstacle/long_killed"))
    return;
  if (who->query("obstacle/sc") != "done")
    return;  
    
  i = random(900);
  message_vision (HIY"һƬ���ƹ��󣬽��г���������ǰ��\n",who);
  message_vision (HIY"\nֻ������ŭ��һ����������������̫�ӻ����ݹ�ȡ���ˣ�\n",who);
  message_vision (HIY"\n��Ȼ�����˵��ڵأ������һƥ����\n",who);
  horse->move(here);
  who->add("obstacle/number",1);
  who->set("obstacle/yj","done");
  who->add("combat_exp",i+8000);
  who->add("potential",i*8);
  who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"ӥ�����������");
message("channel:chat",HIY"������ն������������(guanyin pusa)��"+who->query("name")+"��������ȡ��[1;37m�����أ�\n"NOR,users());
        tell_object (who,"��Ӯ����"+chinese_number(i+8000)+"�㾭��"+
               chinese_number(i*8)+"��Ǳ��"+
               "ʮ�����ɹ��� ����ɳ����ޣ�\n");

	  command("wave");
	  who->save();
}

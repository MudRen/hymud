//Cracked by Roath
 
inherit NPC;
#include "/d/migong/romnpc2.c"
#include <ansi.h>
void create()
{
   set_name("�鼪����", ({ "lingji pusa", "ling ji", "pusa" }));
   set("long","һ���������ɽ������");
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
   set("combat_exp", 2000000);
   set_skill("literate", 150);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
 

   setup();
   initlvl((300+random(200)),8);
   carry_object("/d/qujing/nanhai/obj/jiasha")->wear();
   carry_object("/d/qujing/nanhai/obj/nine-ring")->wield();
}

void announce_success (object who)
{
  int i;
  object me = this_object(); 
  
  if( ! who->query_temp("obstacle/hfg_killed"))
     return;
  if (who->query("obstacle/yz") != "done")
    return;  
  if( who->query("combat_exp") < 10000)
     return;
  if( who->query("obstacle/hfg") == "done")
    return;

  i = random(500);
  who->add("obstacle/number",1);
  who->set("obstacle/hfg","done");
    who->add("potential",i*7);
  who->add("mpgx",10);
         who->add("combat_exp",i+2000);
me->command("chat "+who->query("name")+"�Ʒ�ɽ�Ʒ����ս��Ʒ�֣�");
  message("channel:chat",HIY"������ն������������(guanyin pusa)��"+who->query("name")+"��������ȡ��[1;37m�����أ�\n"NOR,users());
  tell_object (who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}

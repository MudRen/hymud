// created by smile 12/10/1998
//ѲɽС����route in baigushan
#include <ansi.h>
inherit NPC;

void create()
{
  object me=this_object();
  int i = random(5)+10;
  string str;
  set_name("ѲɽС��", ({"xiao yao","yao"}));
  set("gender", "����");
  set("age", 25);
  set("xiaoyao","xiaoyao");  
  set("combat_exp", 18000*i);
  set("attitude","aggressive");
  set("per", 8);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("staff", 10*i);
  set_skill("club", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("staff", 10*i);
  set_skill("staff", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_jing",80*i);
  set("max_qi",80*i);
  set("max_jing",80*i);
  set("neili",80*i);
  set("max_neili",80*i);
  set("max_neili",80*i);
  set("force_factor",8*i);
 
  set("chat_chance",10);
  set("chat_msg",({
       "ѲɽС�����Ŀ�ˮ����������,�ٺ٣���������һ�������ˡ���\n",
       "ѲɽС����е�������Ҫ�������ˣ������������ܣ�\n",
       (: random_move :),
       "ѲɽС�����˸���ָ�����������츣���ˡ���\n",
       "ѲɽС���ٺ���Ц�����������������ȥ���ã�\n",
       (: random_move :),
  }));
  
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baigudong/obj/armor")->wear();
  str = "/d/qujing/baigudong/obj/weapon0";
  str[strlen(str)-1] = '0'+random(10);
  carry_object(str)->wield();
}

void init()
{
  object ob=this_player();
  call_out("greeting",1,ob);
}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
  if (ob && interactive(ob))
  {
    if(!ob->query_temp("obstacle/xiaoyao_kill"))
     {
    if (ob->query_temp("obstacle/east_from")!=0)
     {
     command("consider "+ob->query("id"));
      message_vision ("
$N����ǰ�������˵�ж�������ȡ������·�������˿��Գ�������,����������!\n"+
             HIR+RANK_D->query_rude(ob)+"���ߣ�\n" NOR,this_object(),ob);
     }
    else {
      message_vision("$N��ϲ��������һ����������������!\n",this_object());

         }  
      }
     this_object()->kill_ob(ob);
     ob->set_temp("obstacle/xiaoyao_kill",1);
  } 
}
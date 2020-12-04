// fangzhang, the one in jail.
// created by mes, updated 6-21-97 pickle

/************************************************************/
#include <ansi.h>
inherit NPC;

string quest_complete();
int award(object me);
void destroy(object ob);
int annouce_adjust(object me);
string answer();
string check_gift();
int do_add(string arg);
int do_subtract(string arg);
int do_finalized(string arg);

string method="
����ָ�����£�

�����츳��subtract <arg>
�����츳��add <arg>
��������state
�������ܣ�finalize

����� <arg> ���츳����д��

������str    ��ʶ��cor    ���ԣ�int    ���ԣ�spi
������cps    ��ò��per    ���ǣ�con    ��Ե��kar

";
int total = 0;
int credit = 0;
mapping points=([]);
mapping gift=([
	"str"		: "����",
	"cor"		: "��ʶ",
	"int"		: "����",
	"spi"		: "����",
	"cps"		: "����",
	"per"		: "��ò",
	"con"		: "����",
	"kar"		: "��Ե",
]);
string *gift_name=({ "kar", "con", "per", "cps", "spi", "int", "cor", "str", });
/************************************************************/
void create()
{
  set_name("Բ��",({"yuan qing", "yuan", "qing", "fang zhang", "monk", "yuanqing"}));
  set("title","����");
  set("gender", "����");
  set("age", 80);
  set("long","һ�����ݵ��Ϻ��У��ƺ����ŷ��ˡ�\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "peaceful");
  set("inquiry", ([
		   "name"   : "�������ɱ��������µ�Բ�峤�ϡ�",
		   "here"   : "��Ҳ��֪����ô���¡�����������������أ�ͻȻ�ͱ�һ��������������ˡ�",
		   "rumors" : "�����Լ�����������֪������ʲô����ȥ������ģ�",
		   "����"   : "Ҳ��֪��û����λӢ�ۿ�������ҡ�����",
		   "rescue" : (: quest_complete :),
		   "���"   : (: quest_complete :),

		   ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/

/************************************************************/
string quest_complete()
{
  object monk=this_object(), me=this_player();
  string served;

  if (stringp(served=query("serving"))
   && served != me->query("id"))
    if (present(served, environment(monk)))
    {
	return "��лʩ�����⣬�������˴�Ӧ�����ĳ�ȥ��";
    }
  if (me->query("obstacle/wudidong") == "done")
  {
      tell_object (me,"���Ѿ�������һ�أ�ʲô���ò����ˣ�\n");
      return "�⣮����";
  }
  if (served==me->query("id"))
	return "�����ӷ�ʩ�������Ѿ���Ӧ�����ĳ�ȥ��ô��";
  if (!wizardp(me) || !me->query("env/immortal"))
  if (!me->query_temp("mark/wudidong_opened_door")
    || me->query_temp("mark/wudidong_no_hope_of_knowing_trap"))
  {
      command("say �㡢�㡢�㣬����˭��Ŷ�����������ҵģ����������Ӳ��󰡣�");
      command("say ��Ҳ�Ǳ����˴����˱������İɣ���Ҫ�Ǹ����ȥ�ˣ����ø�ץ������");
      return "�����ӷ��ҷ�ȱ���ƶɮ�����Ų��̾��ø���ɡ�";
  }
  me->set_temp("wudidong/can_ask_monk");
  set("serving", me->query("id"));
   call_out("award", 0, me);
  return "��λʩ������������ҵģ�";
}




int award(object me)
{
  object monk=this_object();
        string myid=me->query("id");
        string myname=me->query("name");
  int year, day, hour, reward, mykar=me->query_kar();

  command("thank " + myid);
  command("say ���������̻��£�");
  command("south");
  call_out ("destroy",2, monk);	

  me->add("obstacle/number",1);
  me->set("obstacle/wudidong","done");
  me->delete_temp("mark/wudidong_opened_door");
  reward=37000+random((mykar-10)*80);
 
  tell_object (me,"��Ӯ����"+chinese_number(reward)+"�㾭�� "+chinese_number(reward/2)+"��Ǳ�� ʮ�����ɹ��� ����ɳ����ޣ���\n");
  command("rumor ��˵"+myname+"�����޵׶����ȳ�������ץȥ��һ���Ϻ��У�Ҳ��֪�����Ǽ١�");
  me->add("combat_exp",reward);
     me->add("potential",reward/2);
   me->add("mpgx",10);me->add("expmax",2);
  me->save();


  return 1;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
/************************************************************/

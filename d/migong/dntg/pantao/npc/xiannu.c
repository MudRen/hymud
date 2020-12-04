#include <ansi.h>
inherit NPC;

void greeting(object);
void die();
void unconcious();
void announce(object);

void create()
{
  set_name("��Ů", ({ "xian nu", "xian"}) );
  set("gender", "Ů��" );
  set("age", 18);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "friendly");
  
    set("combat_exp", 500000);
  set("daoxing", 300000);



	set("max_qi", 38000);
	set("max_jing", 38000);
	set("neili", 34000);
	set("max_neili", 34000);
	set("max_neili", 34000);
	set("jiali", 100);
	set("combat_exp", 18500000);
	set("score", 400000);

	set_skill("unarmed", 1250);
	set_skill("force", 1250);
	set_skill("huagong-dafa", 1380);
	set_skill("throwing", 1250);
	set_skill("feixing-shu", 1380);
	set_skill("dodge", 1250);
	set_skill("zhaixinggong", 1380);
	set_skill("strike", 1250);
	set_skill("chousui-zhang", 1380);
	set_skill("claw", 1350);
	set_skill("sanyin-wugongzhao", 1380);
	set_skill("parry", 1200);
	set_skill("staff", 1300);
	set_skill("poison", 1380);
	set_skill("tianshan-zhang", 1380);
	set_skill("chanhun-suo", 1380);
	set_skill("whip", 1380);
	set_skill("literate", 1150);
set_skill("blade", 1250);
set_skill("xuantian-strike", 1380);
set_skill("bingpo-blade", 1380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);

  setup();

             carry_object(__DIR__"luoyi")->wear();
             carry_object(__DIR__"rose")->wear();
  carry_object(__DIR__"wuchou")->wield();
}

void init()
{
  object ob;

  ::init();
  //add_action("do_set","sett");
   if( interactive(ob = this_player()) && !is_fighting() )
   {
       remove_call_out("greeting");
      call_out("greeting", 1, ob);
   }

}

// int do_set() { set_temp("my_killer",this_player());return 1; }

void greeting(object ob)
{
  object me=this_object();
  
  if (ob->query("dntg/pantao")=="doing") {
     command("bow "+ob->query("id"));
     command("say �ҷ���ĸ֮������ժ��ң�����֮������������");
  } else command ("shysmile "+ob->query("id"));
  


}
void unconcious() {die();}

void die()
{
  object me = this_object();
  object ob=me->query_temp("my_killer"); 
  int mark;

  if (objectp(ob)) {
    mark=ob->query_temp("pantao/"+me->query("name"));
    //message_vision("�úúã�\n",me);
    command("sob "+ob->query("id"));
    message_vision("$Nһ��ţ�ŭ����������"+
       RANK_D->query_rude(ob)+
       "��͵�����һ�Ҫ���ף�����������ĸ���������㣡��\n",
       me);
    message_vision(HIY"$N��һָ������һ���Ʋʣ��߸����˵�������ȥ��
�ٴ�һ�����ڣ���֮����ȽȽ�����𡣡���\n"NOR,me);
    if (!mark) {
        ob->set_temp("pantao/"+me->query("name"),1);
        mark=(int) ob->query_temp("pantao/total");
        if (mark) mark++;
        else mark=1;
        ob->set_temp("pantao/total",mark);
        if (mark==7) announce(ob);
    }
    destruct(me);

  }
  else ::die();
  return;
}

void kill_ob (object ob)
{
  object me = this_object();

  if (ob!=me->query_temp("my_killer") )
      me->delete_temp("my_killer");
  ::kill_ob(ob);
}

void announce(object ob) {
   object me=this_object();

   if (ob->query("dntg/pantao") != "doing") return;
   me->set("name","����ĸ");
   me->set("id","xi wangmu");
   command("chat "+ob->query("name")+"��"+RANK_D->query_rude(ob)+
            "������죬�����Ե���͵����ң���ɱ�����ˣ�");
   ob->set("dntg/pantao","done");
log_file("dntg",sprintf("%s(%s) passed pantao-yuan on %s\n",ob->name(1), geteuid(ob), ctime(time()) ) );
}
 
int accept_object(object me, object ob)
{

     if ((string)ob->query("name")!="�Һ�") {
            command("shysmile "+me->query("id"));
            command("thank "+me->query("id"));
            //command("give " + ob->query("id") + "to " + me->query("id"));
            destruct(ob);
            return 1;
       }
      if (me->query("dntg/pantao")!="doing") {
             command("trip "+me->query("id"));
             command("boring "+me->query("id"));
             return 1;
       }
       command("ah "+me->query("id"));
       command("say ��"+RANK_D->query_rude(me)+
                "����͵����ң���������");
       set_temp("my_killer",me);
       kill_ob(me);                  
       return 1;
}      






��

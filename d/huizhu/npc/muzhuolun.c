inherit NPC;
#include <ansi.h>
int ask_me();
void create()
{
   set_name("ľ׿��",({"muzhuolun"}));
   set("gender","����");
      set("long","ľ׿���ǻ��岿���Ӣ��!\n");
   set("shen",25000);
   set("combat_exp",500000);
     set("age",45);
    set("food",250);
    set("water",250);
   set("neili",2500);
   set("max_neili",2500);
   set("force_factor",60);

   set_skill("dodge",160);
   set_skill("force",160);
   set_skill("parry",160);
   set_skill("unarmed",160);
   set_skill("blade", 200);
        set("title",HIY"����Ӣ��"NOR);
        set("inquiry", ([

"��������" : (: ask_me :),
        ]));

	setup();
   carry_object("clone/weapon/gangdao")->wield();
   carry_object("clone/cloth/cloth")->wear();
	add_money("gold",1);
}


int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book941"))
	{
		message_vision("$N��$n˵���� ��������������������ˡ��治֪����Ǻá�\n",this_object(),who);
  
		return 1;	
	}

	if(!who->query_temp("book942"))
	{
		message_vision("$N��$n˵���� ��������������������ˡ���˵���Ѿ��������Ͻ����˳�͢��\n",this_object(),who);
  
		return 1;	
	}

	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� ��л�����������һ��������顣\n",this_object(),who);
	message_vision("$N��$n˵���� ��˵�¼���ȥ������Ǭ¡����ȥ�ˡ�\n",this_object(),who);
if(((int)who->query("jinyong/book9")==3))	
{
        i = 800+random(2800);
	who->set("jinyong/book9",4);
	who->add("combat_exp",i+15880);
	who->add("potential",i*19);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+15880)+"�㾭��"+
	           chinese_number(i*19)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
}
                     
	return 1;
}
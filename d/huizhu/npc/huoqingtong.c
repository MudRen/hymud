
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
   set_name("����ͩ",({"huo qingtong"}));
   set("gender","Ů��");
   set("long","ľ׿�׵Ĵ�Ů��,������ˬ,Ů�к���!\n");
   set("score",4000);
   set("combat_exp",150000);
   set("title",HIY"�������"NOR);
   set("area_name","������Ⱥ");
   
set("per",35);
set("age",21);
   set("qi",1000);
   set("max_qi",1000);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",30);

   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("unarmed",80);
   set_skill("whip",80);
   set_skill("sword",100);
        set("inquiry", ([

"������" : (: ask_me :),
        ]));
   setup();
   add_money("silver",30);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/sword")->wield();
}


int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book931"))
	{
		message_vision("$N��$n˵���� ����ʥ���������̩ɽ����կ��ǿ���������ˡ��治֪����Ǻá�\n",this_object(),who);
  
		return 1;	
	}

	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� ��л�����������һ�ʥ���������\n",this_object(),who);
	message_vision("$N��$n˵���� ���������������������������ˡ��¹���������������\n",this_object(),who);
if(((int)who->query("jinyong/book9")==2))	
{
        i = 500+random(2800);
	who->set("jinyong/book9",3);
	who->add("combat_exp",i+12880);
	who->add("potential",i*19);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+12880)+"�㾭��"+
	           chinese_number(i*19)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
}
                     
	return 1;
}
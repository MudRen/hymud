#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name( "�г�" , ({ "xing chi","xingchi"}));
        set("shen_type", 0);
        set("age",43);
        set("title", HIR"�Ϻ���"NOR);
        set("gender", "Ů��");
      set("per",24);
        set("long",
                "�����ðװ����֣�����������ɫ�Եúܲ԰ס�\n");
        set("combat_exp", 500);
        set("attitude", "friendly");
        set("inquiry", ([
                "�����Ӹ�" : "Ҫ������̫ƽ����Ҫ�������Ӹ���������\n",
                "Ӫ��" : (: ask_me :),
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}
int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book7")!=5))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл����֮����\n",this_object(),who);
	message_vision("$N��$n˵���� �������������Ҫ�����ˣ����°���Ҫ������ ��\n",this_object(),who);
	who->set_temp("book761",1);
	call_out("destroying", 0);                       

	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N˵�������������ʧ������......\n"NOR,ob);
destruct(this_object());
   return;      
}
// miaoruolan.c ������

#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
	set_name("������", ({ "miao ruolan", "ruolan", "miao" }) );
	set("gender", "Ů��");
	set("age", 17);
	set("long","�������µ�һ���֣�����������޵��֡��ġ���������˷�֮Ů��ֻ����С�ҽ̣���ϰ�书��\n");
	set("attitude", "friendly");
	set("str", 15);
	set("int", 15);
	set("con", 19);
	set("dex", 17);
	set("per", 34);
	set("combat_exp", 2000);

	set("chat_chance", 10);
	set("chat_msg", ({
		"���������ĵص��������Ǹ�������С�к�����Ҳ��֪��ô���ˣ�\n",
		"��������������ü��������ô��û��ɽ��\n",
        }) );
	        set("inquiry", ([
                "���" : (: ask_me :),
        ]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
    
        if(((int)who->query("jinyong/book2")!=1))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	

	  	if(((int)who->query("jinyong/book2")>=2))
	{
		message_vision("$N��$n˵���� ��������,����˵ʲô����\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	
	
        if((!(int)who->query_temp("killtian1")))
	{
		message_vision("$N��$n˵���� ��ûɱ�˶�ϣ�� ���Ӳ���ȥ��\n",this_object(),who);
		return 1;	
	}
	
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл��������֮����\n",this_object(),who);
	message_vision("����磬����ѩɽ�ϡ���ȥ�����ɡ�\n",this_object());

	
	i = 500+random(800);
	who->set("jinyong/book2",2);
	who->add("combat_exp",i+9880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
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
// /d/yixing/npc/zhan.c չ��
// Last Modified by winder on Jul. 12 2002
#include <ansi.h>
inherit NPC;

int ask_me();

void create()
{
	set_name("չ��", ({ "zhan fei", "zhan" }));
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "����������");
	set("long", "����һ���������µĺ��ӡ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 700);
	set("max_jing", 400);
	set("max_neili", 500);
	set("neili", 500);
	set("jiali", 30);
	set("combat_exp", 120000);
	set("score", 6000);

	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("strike", 90);
/*
	set_skill("ding-force", 90);
	set_skill("wuxingbu", 90);
	set_skill("cuixin-zhang", 90);

	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("strike", "cuixin-zhang");
	map_skill("parry", "cuixin-zhang");

	prepare_skill("strike", "cuixin-zhang");
*/
	set("inquiry", ([
		"���ְ�" : "��Ϊ���ְ︰������ʮ���꾹�������³���",
		"˾ͽ��" : "��������������������֪Ҫ��ʲô���͹ŹֵĻ�������ĥ�ң�",
		"����"   : "��������������������֪Ҫ��ʲô���͹ŹֵĻ�������ĥ�ң�",
		"������" : "û���ҵĹ�Ͻ���������ۿ�Ҫ���ˡ�",
		"����ʯ" : (: ask_me :),
		"����"   : "��λ�����������ɰ������˼�˵���㡣",
	]));

	setup();
}
int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	if(!who->query_temp("book1131"))
	{
		message_vision("$N��$n˵���� ������֪�����˵�ˡ�\n",this_object(),who);
  
		return 1;	
	}

	  	if(((int)who->query("jinyong/book11")>=3))
	{
		message_vision("$N��$n˵���� ��л��ȣ�\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N��$n˵���� лл��������֮������\n",this_object(),who);
	message_vision("$N��$n˵���� ����ʯ��ıı��������Ȼ����ʯ���������ܡ���\n",this_object(),who);
who->set_temp("book1132",1);
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
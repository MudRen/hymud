// design by ���ֺ�(find) . all right reserved.

// sunzi.c

inherit NPC;

void create()
{
	set_name("С����", ({ "child"}) );
	set("gender", "����" );
	set("age", 4);
	set("long",
		"����һ���ֺ�����С���ޣ���ԼҲ���ġ����꣬���ཱུ�С���ǳ��ɰ���\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("bird",0);
	setup();
	carry_object(__DIR__"obj/doudou")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(!query("bird")) {
	command("say үү�����ҽ�����ҵ�С�����ˣ�үү�ٸ���Ūһֻ��");
	}
	else {
	command("say С����ɰ���");
	}
}

int accept_object(object who, object ob)
{
	if(ob->query("name") == "С��" && ob->query("id") == "bird") {
	if(query("bird")) {
		command("say ���Ѿ���С���ˡ�лл��");
		return 1;
		}
	if(!who->query_temp("tao_bird")) {
		command("say ������Ҷ�����ֻС��ԭ�����������ˡ�");
		return 1;
		}
	who->delete_temp("tao_bird");
	who->set_temp("gongjiang/bird",1);
	command("say ��ѽ��������һֻС��ѽ��̫���ˣ�����...");
	set("bird",1);
	return 1;
	}
	else return 0;
}
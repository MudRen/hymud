#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����",({"jiasan","jia san"}));
	set("nickname",YEL"��"+RED"Ǯ"+YEL"�ۿ�"NOR);
	set("title","��կ��");
	set("age",30);
	set("long","��Ұ��կ����կ����ר�Ÿ�����·���١�\n����ݺݵĵ����㡣\n");
        set("shen_type",-1);
	set("area_name","Ұ��կ");
	set("money_need",1000);
	set_skill("dodge",200);
	set_skill("unarmed",200);
	set_skill("parry",100);
	set_skill("axe",200);
set("max_neili",1900);set("neili",1900);set("max_qi",1900);set("max_jing",1900);
	set("combat_exp",150000);
        setup();
	carry_object(__DIR__"obj/jinbanfu")->wield();
	carry_object(__DIR__"obj/yinbanfu")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",10);
	carry_object(__DIR__"obj/gangjia")->wear();
}
	
void init()
{
        object ob,area;

	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_ask","ask");
}

int do_ask(string str)
{
	string banghui;
	object me;
	string sb,sth;
	if(! str)	return 0;
	me=this_player();
	if(! living(me))	return 0;
	if(sscanf(str,"%s about %s",sb,sth)!=2)	return 0;
	if(sb!=this_object()->query("id"))	return 0;
	if(sth!="��·Ǯ")			return 0;
	banghui=(string)me->query("banghui");
        if(! banghui || query("banghui")!=banghui)   {
		if(me->query_temp("have_asked"))	{
		message_vision("$Nһ���۵���"+me->query("name")+
		"���ʸ�û��û�ˣ������ǲ�����Ǯ����������ȥ���Ź����ʰɣ�\n",
		this_object());
		me->delete_temp("have_asked");
		kill_ob(me);
		me->fight_ob(this_object());
		return 1;
		}
		command("hehe");
		message_vision("$N˵������������"+me->query("name")+
		"�͸�(pay)��ʮ�������ɡ�\n",this_object());
		me->set_temp("have_asked",1);
		return 1;
	}
	message_vision("$N������$n�ļ��������ǰ����ֵܣ����Ļ�Ҫ��Ĺ�·���ء�\n",this_object(),me);
	return 1;
}

void greeting(object ob)
{
	string banghui;
	if( !ob || environment(ob) != environment() ) return;
	banghui=(string) ob->query("banghui");
        if(! banghui || query("banghui")!=banghui)   {
		say("���������е���߾����ɽ���ҿ��������ǰ��ԣ�Ҫ���·��������"+GRN"��·Ǯ"NOR+"��\n");
		return;
		}
	command("say ��λ"+RANK_D->query_respect(ob)+"����������ɺã�\n");
	return;
}


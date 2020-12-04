// design by ���ֺ�(find) . all right reserved.

// youfang_seng.c

#include <ansi.h>

inherit NPC;

string *make_msg = ({
    HIC "�η�����������ʵı�������ؿ��������� \n" NOR,
    HIC "�η�����˵�����������һ���������ʩ�����û�кܸ����е����ǰ�(ba)�������ġ�\n" NOR,
    HIC "����˵�˽��������ò�����ɽ��ǧ����������������ʮ���������ɡ� \n" NOR,
    HIC "���з����ޱȣ�����Ҳ�����ã�������(shou)���ֵı�����\n" NOR,
    HIC "����һ�Կ��ܲ��ܰγ�������\n" NOR,
    HIC "�η�������һ����ţ�˫Ŀ���գ����������дʣ�ͻȻһ����ȡ�\n\n" NOR,
});

string ask_me(object who);

void create()
{
        set_name("�η�����", ({ "youfang lama","lama"}) );
        set("gender", "����" );
        set("age", 45);
        set("str", 20);
        set("long", @LONG
һλ�����ƾ�ɮ�۵����
LONG
);
        set("attitude", "friedly");
        set("score",-20);
        set("combat_exp", 600);
	set("inquiry",([
	"����" : (: ask_me :)
]));
        setup();

        carry_object(__DIR__"obj/sengpao")->wear();
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
	if(ob->query_temp("xia_killer")) {
	message_vision( "�η������$N˵������л��λ" + RANK_D->query_respect(ob)
				+ "������ȡ�\n",ob);
	return;
	}
	else return;
}

string ask_me(object who)
{
	object me = this_player();
	if(me->query_temp("xia_killer"))
		return "Сɮ��ϰ����ʮ����,�����������С�\n";
	else return 0;
}

int accept_object(object me,object obj)
{
	if(!me->query_temp("xia_killer"))
		return 0;
	if(obj->query("id") != "qsword") return 0;
	me->start_busy(4);
	call_out( "make_stage", 1, me,0 );
	return 1;
}

void make_stage(object me, int stage)
{
	tell_object(me, make_msg[stage]);
	if( ++stage < sizeof(make_msg) )
	{
		call_out( "make_stage", 1, me, stage );
		return;
	}
	else
	{
		object ob;

		ob = present("qsword",this_object());
		if(!ob)
			return;
		ob->do_ba("qsword",this_object());
		command("give jian qiao to "+(string)me->query("id"));
		command("give jinghong sword to "+(string)me->query("id"));
		command("say ʩ�����и��е�֮�ˣ��������أ�Сɮ����ˡ�");
		me->delete_temp("xia_killer");
		destruct(this_object());
	}
	return;
}
// design by ���ֺ�(find) . all right reserved.

// grand_li.c

#include <ansi.h>

inherit NPC;

string *make_msg = ({
	HIC "��Ӫ��ʯ������һ�ξ�ʦ�����������������ģ���ʱ�һ��Ǹ�С���ӣ�\n" NOR,
	HIC "ʯ���Ǹ��ڹ����״���������Ǳ߹ش�Ӫ�����Ӫ�̣����겻����\n" NOR,
	HIC "�ڹ�β�;��������ڣ������������ڵ�·�ߣ��߷�������������ң�\n" NOR,
	HIC "��ʹ��ˣ�Ҳ�ǲ����ˣ������ڹ����צ�Ӻ������Ҫ��\n" NOR,
});

string ask_zhen(object who);

void create()
{
	set_name("���ү", ({ "grand li","li"}) );
	set("gender", "����" );
	set("age", 68);
	set("long",
		"���ү����һ�������Ĺ�������˵���ó����������\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", ([
		"ʯ��" : (: ask_zhen :),
	]) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int relay_say(object who,string arg)
{
	object env,*inv;
	int i;
	string name,gender;

	if(who->name() == "С����" && arg == "үү�����ҽ�����ҵ�С�����ˣ�үү�ٸ���Ūһֻ��")
	{
	command("sigh");
	command("say үү����������ˣ�����ȥ����ץС��ѽ��");
	}
	else if(who->name() == "С����" && arg == "��ѽ��������һֻС��ѽ��̫���ˣ�����...")
	{
	env = environment(this_object());
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++)
		{
		if(inv[i]->query_temp("gongjiang/bird")) {
			name = inv[i]->name();
			if(inv[i]->query("gender") == "����")
			gender = (inv[i]->query("age")<=29)? "����" : "����";
			else gender = (inv[i]->query("age")<=29)? "����" : "����";
			}
		}
	command("say ��лл��λ"+name+gender+"��");
	tell_object(env,CYN "С����˵����лл��\n" NOR);
	}
	return 1;
}

string ask_zhen(object who)
{
	object me = this_player();
	if(!me->query_temp("gongjiang/bird")) return "û��˵����";
	else
	{
	call_out( "make_stage", 1, me, 0 );
	me->delete_temp("gongjiang");
	return "���Ǻ�����ǰ�����ˡ�";
	}
}

void make_stage(object me, int stage)
{
     tell_object(me, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "make_stage", 1, me, stage );
         return;
     } else
    return;
}
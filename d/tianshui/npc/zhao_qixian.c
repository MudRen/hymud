// zhao_qixian.c

inherit NPC;

string *make_msg = ({
	"��֪��һ�����ܣ��͸����㣬�Ժ�ĳ����и�ʧ�֣����Ҫ�չ��չ��ҡ�\n",
	"������ܾ������⣬��ȥ����ɻ������������ҵĽ�ݴ�硣\n",
	"��˵��������ȥ�ģ����������������ܡ�\n",
});

void create()
{
	set_name("������", ({ "zhao qixian","zhao" }) );
	set("gender", "����" );
	set("age", 32);
	set("title","�߹ش�Ӫ����");
	set("long", "�������׳��һ��Ӣ�����š�\n");
	set("per", 25);
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set_skill("unarmed", 50);
	set_skill("parry", 70);

	set("inquiry", ([
		"��" : "�ԣ������������漸�ѡ�\n",
	]) );
	set("money_my",200);
	setup();
	add_money("silver", 2);
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_bet","bet");
}

void greeting(object ob)
{

        if( !query("bet_another_name") && ob && environment(ob) == environment() )
		say("������˵��������λ"+RANK_D->query_respect(ob)+"Ը��Ը����ҶԶ�����ѽ����\n");
}

int do_bet(string arg)
{
	int duzhu,a,b,c,pkar;
	object me,mtype;
	string decision;
	me = this_player();
	if(!arg)
		return notify_fail("bet big|small <amount>\n");
        sscanf(arg,"%s %d",decision,duzhu);
	if(!arg)
		return notify_fail("bet big|small <amount>\n");
        mtype = present("silver_money", me);
        if( !mtype)
		return notify_fail("������û�����ӡ�\n");
	 if( (int)mtype->query_amount() < duzhu)
		return notify_fail("������û����ô��" + mtype->query("name") + "��\n");
        if ( (decision != "big") && (decision != "small") )
                return notify_fail("��Ҫ�Ĵ��Ƕ�С��\n");
	if( duzhu < 1 )
		return notify_fail("��Ҫѹ���ٰ���\n");
	if( duzhu < 5 )
		return notify_fail("һ������Ѻ�������ӡ�\n");
	if( duzhu > 20 )
		return notify_fail("һ�����Ѻ��ʮ�����ӡ�\n");
	if( (int)query("money_my") <= 0 )
		return notify_fail("������˵����������Ǯ����û�ˣ��ܲ����Ƚ������������ӣ���\n");

	if(!query("bet_another_name"))
	{
	set("bet_another_name",me->name());
	set("bet_another_id",me->query("id"));
	}

	if(me->query("id") != query("bet_another_id") &&
		present((string)query("bet_another_id"),environment(this_object())))
		return notify_fail("������˵������һ�ȣ�������"+(string)query("bet_another_name")+"�Զġ�\n");
	if(!present((string)query("bet_another_id"),environment(this_object())))
	{
	set("bet_another_name",me->name());
	set("bet_another_id",me->query("id"));
	set("money_my",200);
	}

	pkar = me->query("kar");
	if(random(pkar)+random(20) >= 23){
	if(decision == "big")
		{
			a=random(3)+4;
			b=random(3)+4;
			c=random(3)+4;
			message_vision("����" + a + "   " + b + "   " + c + "   ��  ��\n", me);
			message_vision(me->query("name") + "Ӯ��" + chinese_number(duzhu) +
			mtype->query("base_unit") + mtype->query("name") + "��\n", me);
			mtype->set_amount((int)mtype->query_amount() + duzhu);
			mtype->move(me);
			add("money_my",-duzhu);
			if( (int)query("money_my") <= 0 ) {
				say("������˵����������������ˣ��ܲ����Ƚ������������ӣ���\n");
				me->set_temp("duchang/winner",1);
			}
			return 1;
		}
	if(decision == "small")
		{
			a=random(3)+1;
			b=random(3)+1;
			c=random(3)+1;
			message_vision("����" + a + "   " + b + "   " + c + "   ��  С\n", me);
			message_vision(me->query("name") + "Ӯ��" + chinese_number(duzhu) +
			mtype->query("base_unit") + mtype->query("name") + "��\n", me);
			mtype->set_amount((int)mtype->query_amount() + duzhu);
			mtype->move(me);
			add("money_my",-duzhu);
			if( (int)query("money_my") <= 0 ) {
				say("������˵����������������ˣ��ܲ����Ƚ������������ӣ���\n");
				me->set_temp("duchang/winner",1);
			}
			return 1;
		}
	}
	else {
	if(decision == "small")
		{
			a=random(3)+4;
			b=random(3)+4;
			c=random(3)+4;
			message_vision("����" + a + "   " + b + "   " + c + "   ��  ��\n", me);
			message_vision(me->query("name") + "����" + chinese_number(duzhu) +
			mtype->query("base_unit") + mtype->query("name") + "��\n", me);
			mtype->set_amount((int)mtype->query_amount() - duzhu);
			mtype->move(me);
			add("money_my",duzhu);
			return 1;
		}
	if(decision == "big")
		{
			a=random(3)+1;
			b=random(3)+1;
			c=random(3)+1;
			message_vision("����" + a + "   " + b + "   " + c + "   ��  С\n", me);
			message_vision(me->query("name") + "����" + chinese_number(duzhu) +
			mtype->query("base_unit") + mtype->query("name") + "��\n", me);
			mtype->set_amount((int)mtype->query_amount() - duzhu);
			mtype->move(me);
			add("money_my",duzhu);
			return 1;
		}
	}
}

int accept_object(object me, object obj)
{
	if(!me->query_temp("duchang/winner")){
		say("��λ"+RANK_D->query_respect(me)+"���ǿ����󷽣�лл�ˡ�\n");
	return 1;
	}
	if(!obj->value()){
		say("����ֻ���������������ա�\n");
	return 1;
	}
	if(obj->query("id") != "silver"){
		say("����ֻ���������¶�ע����......\n");
	return 1;
	}
	if(obj->value() < 20000){
		say("����ô��Ǯ�����ֲ��ǲ����㣬�ߡ�\n");
	return 1;
	}

	me->start_busy(3);

	tell_object(environment(),"������˵��������λ"+RANK_D->query_respect(me)+
		"�ļ��߳���������˴󷽣������С�ܽ�������������ˡ�\n");
	call_out( "make_stage", 1, me );

	return 1;
}

void make_stage(object who, int stage)
{
	tell_object(who, make_msg[stage]);
	if( ++stage < sizeof(make_msg) ) {
	call_out( "make_stage", 1, who, stage );
	return;
	} else

	tell_object(environment(),"������˵������������̫���ȥ��Ϣһ�»����֡�\n");
	tell_object(environment(),"�����������뿪��\n");
	who->delete_temp("duchang/winner");
	who->set_temp("duchang/zhao",1);
	destruct(this_object());
    return;
}
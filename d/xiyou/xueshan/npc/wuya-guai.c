// wuya-guai.c...weiqi, 97.09.15.

inherit NPC;

string give_map(object me);
string help_fly(object me);
int do_yes(string arg);

void create()
{
	set_name("��ѻ����", ({"wuya xiansheng", "wuya", "xiansheng"}));
	set("gender", "����" );
	set("age", 43);
	set("per", 112);//no rongmao description.

	set("long", "��λ��ѻ��������ңԶ�Ĵ�ѩɽ�����Ǵ����������������ĸ���֮һ��\n��Զ���������߽��˲ŷ��������ų�����һ����ѻ�졣\n");
	set("class", "yaomo");
	set("combat_exp", 100000);
        set("daoxing", 50000);

	set("attitude", "peaceful");
	create_family("��ѩɽ", 3, "����");
	

	set("max_kee", 700);
	set("max_sen", 600);
	set("force", 700);
	set("max_force", 700);
	set("mana", 700);
	set("max_mana", 700);	
	set("force_factor", 35);
	set("mana_factor", 20);

	set("eff_dx", -25000);
	set("nkgain", 150);

	set("inquiry", ([
		"name" : "��ʲô�ʣ������۾��ǿ��ģ������Դ�����ġ�\n",
		"here" : "��������Ǵ�ѩɽ��\n",
		"��ôȥ" : "�ɹ�ȥ��죬��Ҳ�ܵ���\n",
		"��ô��" : "����������ߡ�\n",
 
//		"��ѩɽ" : (: give_map :),
	]) );

	set("no_map", 0);

	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="��ѩɽ" ){
		if( (int)ob->query("family/generation") < 3  ){
			command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command("say �����" + RANK_D->query_rude(ob) + "������ǲ��ү���ˣ�\n");
		}
		else {
			command(":D");
			command("say �����" + RANK_D->query_rude(ob) + "��͸�������Ϊʦ�����Ǹ���ʦ��ʲô������...\n");
			command("recruit " + ob->query("id") );
                        ob->set("title", "��ѩɽ��ɽС��");
                        ob->set("class", "yaomo");
		}
	}

	else{
		command(":D ");
		command("say �ã������Ǵ�ѩɽ��ѧ�գ������˸���ʦ����ֻҪ�ܻ�������" + RANK_D->query_respect(ob) + "����˵��ǰ;��������\n");
		command("recruit " + ob->query("id") );
                ob->set("title", "��ѩɽ��ɽС��");
                ob->set("class", "yaomo");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

string help_fly(object me)
{
	me=this_player();
	if( me->query("combat_exp")<30000 ){
/*
		message_vision("��ѻ�����������Ͼͽ����...�����۾���\n", me);
		message_vision("ֻ����ѻ����������߶�˼��䣬һ������$N��ƨ�ɣ�$N���Ƽ������˳�ȥ...\n", me);
		me->move("/d/xiyou/xueshan/binggu");
		tell_room( environment(me),"ֻ����ž��һ����һ���˴ӿ��зɹ�����������ˤ�ڵ��ϡ�\n", ({me}));
		return "�ٺ٣�\n";
*/
		return "�Ͻ�ѧ�ɣ�\n";
	}
	else{
		return "������ͷ�Բ����ѣ���ˤ���ˣ�\n";
	}
}

string give_map(object me)
{
	me=this_player();
	me->set_temp("need_map", 1);
	return "��ѩɽ���ǿ��Ǹ��õط�������ȥ��(yes)��\n";
}


inherit NPC;

string say_position();
void create()
{
       set_name("��ʥ����", ({"wansheng gongzhu","gongzhu","princess"}));

        set("long","��ʥ��������ʥ������Ů����������˾�ͷ��Ϊ����\n");
       set("gender", "Ů��");
       set("age", 20);
        set("int", 25+random(5));
       set("attitude", "peaceful");
        set("combat_exp", 280000);
  set("combat_exp", 300000);

	set("eff_dx", -100000);
	set("nkgain", 400);
       set("rank_info/respect", "��������");
       set("class","dragon");
       set("per", 30);
       set("max_qi", 800);
       set("max_jing", 500);
       set("neili", 800);
       set("max_neili", 600);
       set("force_factor", 20);
       set("max_neili", 500);
       set("neili", 400);
       set("mana_factor", 10);
       set_skill("literate", 70);
	set_skill("stealing", 70);
       set_skill("unarmed", 70);
       set_skill("dodge", 160);
       set_skill("force", 70);
       set_skill("parry", 70);
       set_skill("spells", 70);
        set_skill("dragonfight", 70);
        set_skill("dragonforce", 70);
        set_skill("dragonstep", 70);
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("dodge", "dragonstep");
	set("inquiry",([
		  "����": "ʲô�����������ģ�\n",
		  "��": "����������������̶֮���ˣ�˭Ҳ�ò�����\n",
                  "��λ": (: say_position :),
                  ]));

        setup();
	carry_object("/d/qujing/bibotan/obj/clasp")->wear();
        carry_object("/d/obj/cloth/pinkskirt")->wear();
}


int recognize_apprentice(object who)
{	who= this_player();
	if( who->query("family/family_name")=="��ʯɽ�̲�̶" 
		&& who->query("can_learn_stealing") ) { 
        	return 1;
	}
	return 0;
}

string say_position()
{	object me =this_object();
	object who=this_player();

	if( me->is_fighting() || who->is_fighting() )
	return ("ʲô��λ����λ�ģ��Ҳ�����\n");



	if( me->query("talked") )
	return ("ʲô��λ����λ�ģ��Ҳ����Ѿ������㣡\n");
	me->set("talked", 1);
	call_out("tell_position", 1, who);
	return "";
}
void tell_position(object who)
{
	if( !who || environment(who) != environment()) return;
	switch (random(8)) {
		case 0:
			command("say ���շ�λ��Ǭλ��");
			who->set_temp("heard_position", "Ǭ");
		break;
                case 1:
                        command("say ���շ�λ����λ��");
                        who->set_temp("heard_position", "��");
                break;
                case 2:
                        command("say ���շ�λ�ڶ�λ��");
                        who->set_temp("heard_position", "��");
                break;
                case 3:
                        command("say ���շ�λ����λ��");
                        who->set_temp("heard_position", "��");
                break;
                case 4:
                        command("say ���շ�λ����λ��");
                        who->set_temp("heard_position", "��");
                break;
                case 5:
                        command("say ���շ�λ����λ��");
                        who->set_temp("heard_position", "��");
                break;
                case 6:
                        command("say ���շ�λ����λ��");
                        who->set_temp("heard_position", "��");
                break;
                case 7:
                        command("say ���շ�λ�ڿ�λ��");
                        who->set_temp("heard_position", "��");
                break;
	}
}
void kill_him(object who)
{
	object husband = present("jiutou fuma", environment(this_object()));
	
	if(husband)
	husband->kill_ob(who);
	::kill_ob(who);
}

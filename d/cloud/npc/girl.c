
// girl.c

inherit NPC;

void create()
{
	set_name("��ʦʦ", ({ "girl" }) );
	set("title", "����");
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 10);
	set("per", 30);
	set("long", @LONG
    ��ʦʦ������Ժ�����ˣ���ͨ�����黭����Χ������ӵ��ǳ�����
���ꡣ
LONG
);
	set("combat_exp", 10);
	set("attitude", "friendly");
    set("can_get",1);

        set("chat_chance_combat", 25);
        set("chat_msg_combat", ({
"��ʦʦ��ü΢����˵����ι��������������ˣ�������������ƴ��ƴ�\n",
	}) );

	set_skill("literate", 100);

	set("inquiry", ([
		"��ҹ": "���˿�Ҫ�����Ժð���",
		"�μ�": "���˿�Ҫ�����Ժð���",
		"ѧ��": "�����������",
	]) );

	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("marks/��ʦʦ") ) {
                say("��ʦʦ˵�����ף��Ҳ��ǵ�����......\n");
                return 0;
        }
        return 1;
}

int accept_object(object who, object ob)
{
	if( ob->value() ){
		command("say �Ҷ�Ǯû��Ȥ��");
                return 0;
        }

	if( (this_player()->query("per") < 15) 
		|| ( (string)this_player()->query("gender") == "Ů��") ){
		command("say �Ҷ���û��Ȥ��");
		return 0;
	}
	command("say �����๫����ʦ�������������ҡ�");
	who->set("marks/��ʦʦ", 1);
        return 1;
}

int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}


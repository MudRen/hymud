// teacher.c

inherit NPC;

void create()
{
	set_name("κ�޼�", ({ "teacher", "wey" }) );
	set("title", "��������");
	set("gender", "����" );
	set("age", 47);
	set("int", 26);
	set("long",
		"κ�޼��Ǹ���ѧ���ŵĽ���������������ʱ�����й����ˣ�����\n"
		"��Ϊ����ϲ�����ɶ���Ը���٣�κ�޼��Խ���Ϊҵ������㸶��\n"
		"һ��ѧ�ѣ��Ϳ��Գ�Ϊ���ĵ���ѧϰ����ʶ�֡�\n");
	set("inquiry", ([
		"ѧ��": "��....֪ʶ���޼۵ģ�������������ĵĻ�����ֻҪ200�����ӡ�\n",
		"����ʶ��": "�ԣ�����ʶ�֡�",
	]) );
	set("attitude", "peaceful");
	set_skill("literate", 120);
	setup();
	set("score",5);
}

int recognize_apprentice(object ob)
{
	if( !ob->query("marks/κ�޼�") ){
		say("κ�޼�˵�����ף��Ҳ��ǵ��չ������ѧ����....\n");
		return 0;
	}

	return 1;
}

int accept_object(object who, object ob)
{
	if( !who->query("marks/κ�޼�") ) {
		if( ob->value() >= 20000 ) {
			say("κ�޼����˵�ͷ��˵�����ܺã��ӽ���������ʱ�����������йض���ʶ��(literate)\n"
				"                      ���κ����⡣\n");
			who->set("marks/κ�޼�", 1);
			return 1;
		} else {
			say("κ�޼�˵������ĳ��ⲻ������Ǯ�����û�ȥ�ɡ�\n");
			return 0;
		}
	} else
		say("κ�޼����˵�ͷ��˵����Ŷ�������������ĵ�ѧ�������ǲ�������ú�Ŭ��\n"
			"                      �����ض�ǰ;������л�ˡ�\n");
	return 1;
}

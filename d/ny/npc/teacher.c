
// teacher.c

inherit NPC;

void create()
{
    set_name("��Τ��", ({ "teacher", "wu" }) );
    set("title", "˽������");
	set("gender", "����" );
	set("age", 47);
	set("int", 26);
	set("long",
        "��Τ���Ǹ���ѧ���ŵĽ�������  ������ʱ�����й�����  ����\n"
        "��Ϊ����ϲ�����ɶ���Ը����  ��Τ���Խ���Ϊҵ  ����㸶��\n"
		"һ��ѧ��  �Ϳ��Գ�Ϊ���ĵ���ѧϰ����ʶ�֡�\n");
	set("inquiry", ([
		"ѧ��": "��....֪ʶ���޼۵�  ������������ĵĻ�����ֻҪ�������ӡ�\n",
		"����ʶ��": "��  ����ʶ�֡�",
	]) );
	set("attitude", "peaceful");
	set_skill("literate", 40);
	setup();
}

int recognize_apprentice(object ob)
{
    if( !ob->query("marks/��Τ��") ){
        say("��Τ��˵��  ��  �Ҳ��ǵ��չ������ѧ����....\n");
		return 0;
	}

	return 1;
}

int accept_object(object who, object ob)
{
    if( !who->query("marks/��Τ��") ) {
		if( ob->value() >= 500 ) {
            say("��Τ�ĵ��˵�ͷ  ˵��  �ܺ�  �ӽ���������ʱ�����������йض���ʶ��(literate)\n"
				"                      ���κ����⡣\n");
            who->set("marks/��Τ��", 1);
			return 1;
		} else {
            say("��Τ��˵��  ��ĳ��ⲻ��  ��Ǯ�����û�ȥ�ɡ�\n");
			return 0;
		}
	} else
        say("��Τ�ĵ��˵�ͷ  ˵��  Ŷ  ������ô���ĵ�ѧ�������ǲ����  �ú�Ŭ��\n"
			"                      �����ض�ǰ;����  л�ˡ�\n");
	return 1;
}

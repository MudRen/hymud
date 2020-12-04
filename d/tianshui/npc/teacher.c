// teacher.c
// by Find.

inherit NPC;

void create()
{
	set_name("����Ң", ({ "teacher li","teacher","li"}) );
	set("title", "���齳");
	set("gender", "����" );
	set("age", 47);
	set("int", 26);
	set("long",
		"����Ң����һ��Ψһ��һ����ţ���ȡ����δ������鿿��\n"
		"΢����ѧ��Ϊ��������ľ��񶼰��ӵ�����ѧϰ����ʶ�֡�\n");
        set("inquiry", ([
		"ѧ��": "��....ÿ��ֻҪ�������ӡ�\n",
		"����ʶ��": "�ԣ��Ҿ��ǽ������",
        ]) );
	set("attitude", "peaceful");
	set_skill("literate", 80);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
        if( !ob->query_temp("school/����Ң") ){
                say("����Ң˵�����ף��Ҳ��ǵ��չ������ѧ����....\n");
                return 0;
        }

        return 1;
}

int accept_object(object who, object ob)
{
        if( !who->query_temp("marks/����Ң") ) {
                if( ob->value() >= 500 ) {
                        say("����Ң���˵�ͷ��˵�����ܺã��йض���ʶ��(literate)������;����ʰɡ�\n");
                        who->set_temp("school/����Ң",1);
                        return 1;
                } else {
                        say("����Ң˵������ĳ��ⲻ������Ǯ�����û�ȥ�ɡ�\n");
                        return 0;
                }
        } else
                say("����Ң���˵�ͷ��˵����Ŷ�������������ĵ�ѧ�������ǲ�������ú�Ŭ��\n"
                        "                      �����ض�ǰ;������л�ˡ�\n");
        return 1;
}
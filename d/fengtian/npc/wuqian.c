// wuqian.c

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("��ǫ", ({ "wu qian"}) );
        set("title", "���Ի�");
        set("gender", "����" );
        set("age", 59);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

	set("inquiry",([
	"����" : (: ask_me :),
]));

        set("long","����һλ������ɣ�����ߡ�\n");

        set("combat_exp", 100);
        set("attitude", "friendly");

        set("max_atman", 500);
        set("atman", 500);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 20);
        set("max_mana", 500);
        set("mana", 500);

        setup();
        
        carry_object("/clone/misc/cloth")->wear();
}

string ask_me(object who)
{
	if(who->query("gender") != "Ů��"
	|| !who->query_temp("feiyu_upgrade_quest/ask_my"))
                return 0;

	who->set_temp("feiyu_upgrade_quest/ask_liehu",1);

	call_out("leave",5);

	return "�Ƕ��Ǻ�����ǰ�������ˣ���ʵ��ֻ�����ɾ������ڱ���
          �����˵�ʱ���������ʱ�Ǹ������Ĵ��ż����󺺴Ҵ�æ
          æ��������ߣ���Ա�����������֮��Ҫ��ס����ˣ�˫
          �����������������Ա�������ˣ�����������ˡ��Ǽ���
          �Ժ�û����÷�Ա�����˵�Ǳ�����˱��������Ż��յ�
          �ˡ������뵱������ʢ�����ķ����֣�����Ǯ�ֻ��书��
          Ҳ�Ƿ�Բ�������쵱����������ϧѽ��������ȥԭ��
          ���Ҹ������������ɣ�Ҳ�����ж�ʮ��ǰ�Ǽ��µ�������";
}

private void leave()
{
	if(environment())
		message_vision("$N�Ҵ�ææ�����ˡ�\n",this_object());
	destruct(this_object());
}

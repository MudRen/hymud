
// monk_waiter.c

inherit NPC;

void create()
{
	set_name("֪��ɮ", ({ "monk waiter", "waiter" }) );
	set("gender", "����" );
	set("age", 46);
	set("str", 29);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
    ֪��ɮ�����ڷ���ǰ������յ�˫�����ƺ�͸��һ���ʴȶ�������
��â��
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"֪��ɮ˵���������徻��ʩ�����Ƿ��������ɣ�\n",
		"֪��ɮ˵������ס�ֲ��ڴˣ�ʩ�����������뿪�ĺã�\n",
		"֪��ɮ��������һ�����ջأ��ƺ���Щ���ǡ�\n",
		"֪��ɮ˵�����ҷ�ȱ���Ըʩ���������顣\n"
	}) );
	set("inquiry", ([
		"ɽ����": "�������ɽ���£�ʩ���кι��?",
	]) );

        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 800);
        set("max_force", 800);
        set("force_factor", 3);

        set("mana", 200);
        set("max_mana", 200);

        set("combat_exp", 10000);
        set("score", 1000);

        set_skill("staff", 60);
        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("literate", 50);

        set_skill("parry", 60);
        set_skill("magic", 30);





	setup();

        carry_object("/clone/misc/cloth")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say �����ӷ𣡳����˽��ǿ�񶷣�ƶɮ����Υ����档");
        else
                command("say ʩ����Ȼ�����գ�ƶɮ������ǣ�Ҳ���ؽ����ˡ�");
	return 0;
}



// monk_guard.c

inherit NPC;

void create()
{
	set_name("������ɮ", ({ "monk guard", "guard" }) );
	set("gender", "����" );
	set("age", 25);
	set("str", 30);
	set("cor", 20);
	set("cps", 22);
	set("int", 16);
	set("per", 20);
	set("spi", 22);
	set("kar", 22);
	set("con", 24);
	set("long", @LONG
    ֪��ɮ�����ڷ���ǰ������յ�˫�����ƺ�͸��һ���ʴȶ�������
��â��
LONG
);
	set("attitude", "heroism");
	set("inquiry", ([
		"ɽ����": "�������ɽ���£�ʩ���кι��?",
	]) );

        set("atman", 300);
        set("max_atman", 300);

        set("force", 300);
        set("max_force", 300);
        set("force_factor", 2);

        set("mana", 100);
        set("max_mana", 100);

        set("combat_exp", 6000);

        set_skill("staff", 50);
        set_skill("unarmed", 100);
        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("literate", 10);
        set_skill("parry", 50);

	setup();

        carry_object("/clone/misc/cloth")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say ����Ϊ��ҵ��ӣ�����Υ����棡");
        else
                command("say ����ʥ��Ҳ�ǿ�����ɧ�ŵ�ô��");
	return 1;
}


// pawnboss.c

inherit NPC;

void create()
{
	set_name("�Ƹ���", ({ "huang fugui" }) );

        set("gender", "����" );

	set("title","�����ƹ�");

        set("age", 38);

        set("long", "��ͬ�����̵Ĵ��ƹ�\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object("/clone/misc/cloth")->wear();
}
// he.c

inherit NPC;

void create()
{
	set_name("��ȫ��", ({ "he quanli" }) );
        set("gender", "����" );

	set("title","Ǯׯ�ϰ�");

        set("age", 38);
	set("str",88);
        set("long", "��ȫ�����Ǵ�ͬ���ͼ�Ǯׯ���ϰ塣\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        set_skill("dodge", 60);
        set_skill("unarmed", 60);
        setup();

	carry_object("/clone/misc/cloth")->wear();
}
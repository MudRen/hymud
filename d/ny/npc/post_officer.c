
// post_officer.c

inherit NPC;



void create()
{
	set_name("�ſ�", ({ "post officer", "officer" }) );
    set("title", "��Զ�䳤");
	set("gender", "����" );
	set("age", 43);
	set("long",
		"�ſ�����Զ����䳤�Ѿ���ʮ������  ��Ȼ�ڼ��м�����Ǩ��\n"
        "���ᵫ��������Ϊ�᲻���뿪���С�����������ȥ������ְ����Զ�ǵ�\n"
		"����Զſ�ķ����൱����  ������������վ�������졣\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
        "��վ" : "�ǰ�... ���������Զ��վ��Ҫ������  ",
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	setup();
	add_money("coin", 70);
}



// box_boss.c

inherit NPC;
//inherit F_VENDOR;

void create()
{
        set_name("���", ({ "waiter" }) );
        set("title", "�ײ���");
        set("gender", "����" );
        set("age", 35);
        set("long", "��һ����ͷɥ�������ӣ�һ����ù�ࡣ\n");
        set("str", 30);
	set("cor", 35);
        set("int", 14);
	set("max_kee",1000);
        set("combat_exp", 1000);
        set("attitude", "heroism");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 70);
	set_temp("apply/armor",25);

        setup();
        add_money("silver", 3);
        carry_object("/clone/misc/cloth")->wear();
}



// judge.c

inherit NPC;

void create()
{
        set_name("����", ({ "judge" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "�����ϵı���·��ǿ�������ڴ����Ǯһ�㡣\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        set("inquiry", ([
                "��" : "�͹�����Ǯ���Ҿ����ˡ�\n",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object("/clone/misc/cloth")->wear();
       // carry_object("/obj/example/dagger")->wield();
}


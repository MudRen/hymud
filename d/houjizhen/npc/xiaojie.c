// chunhua.c
// by dicky

#include <ansi.h>
inherit NPC;
int ask_huijia();

void create()
{
	set_name("��С��", ({"liu xiaojie", "xiaojie"}));
	set("long", "����һλ����Ǯ�˼ҵ�С�㣬�������м�����ɫ��\n");
	set("gender", "Ů��");
	set("attitude", "friendly");
	set("age", 18);
	set("per", 25);
	set("str", 28);
	set("con", 23);
	set("dex", 28);

	set("combat_exp", 2000);
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);

        set("inquiry", ([
		"�ؼ�":(: ask_huijia :),
        ]));

	setup();

        carry_object(__DIR__"obj/skirt1")->wear();
}

int ask_huijia()
{
	object ob;
	ob=this_player();

	if (!ob->is_fighting())
	{
	command("say лл"+RANK_D->query_respect(ob)+"��������ȣ�СŮ����һ�ر������ԼҴ�����������ϣ��"+RANK_D->query_respect(ob)+"�ܹ���ϧ��\n");
	new(__DIR__"obj/yupei")->move(ob);
	message_vision(
		"��С���$Nһ�����塣\n\n"
		"��С��Ҵ��뿪��\n",
                this_player(), this_object());
	destruct(this_object());
	return 1;
	}
	return notify_fail("�㻹���ȱ����Լ���˵�ɣ�\n");
}
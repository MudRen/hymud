// child.c
// edit by pian
inherit NPC;
void create()
{
        set_name("С��", ({ "child" }) );
        set("long", "һ�����������С��������һ˫��а���۾������㡣\n");
        set("gender", "����" );
        set("age", 6);
        set("chat_chance", 10);
        set("chat_msg", ({
                "С���е���ѽ �� �����\n",
                "С���е����� �� ����\n"
        }) );
        setup();
        carry_object("/d/xueting/obj/bamboo_sword")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        message_vision("С���˷ܵ���������ѽ�������䣡߳��\n", me);
        return 1;
}

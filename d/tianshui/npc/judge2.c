// judge2.c

inherit NPC;

void create()
{
        set_name("�Ĺ�С���", ({ "huoji" }) );
        set("gender", "����" );
        set("age", 17);
        set("long", "������һ˫����Ĵ��۾���һ������һ������͸����С������\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        setup();
        add_money("silver", 1);
        carry_object("/clone/misc/cloth")->wear();

}

// strongman.c
inherit NPC;
void create()
{
        set_name("·��", ({ "lu ren" }) );
        set("gender", "����" );
        set("age", 37);
        set("combat_exp", 2000);
        set("long", "    һ����ͨ�Ĺ�·�ˣ�����������һ�������·��������ʮ����\n");
        setup();
        add_money("silver", 2);
        carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

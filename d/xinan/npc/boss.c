
inherit NPC;



void create()
{
        set_name("������ͷ", ({"lao tou", "old" }) );
        set("gender", "����" );
        set("age", 67);
        set("str",60);
        set("long", "����һλ��̬���ӵĿ�����ͷ��\n");
        set("combat_exp", 50000);      
        set("max_kee", 400);
        set("qi", 400);
        set("attitude", "friendly");

		setup();
	    add_money("coin",30);
	    carry_object(__DIR__"obj/cloth2")->wear();
}


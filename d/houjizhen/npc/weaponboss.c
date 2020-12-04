// weaponboss.c
// by dicky

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�������ϰ�", ({ "weapon boss", "boss" }) );
	set("gender", "����" );
	set("age", 40);
	set("long", "�������ϰ��������һ���˰������ˣ�һЦ����������졣\n");
	set("combat_exp", 30000);
	set("attitude", "friendly");
	set("max_qi",1000);
	set("max_neili",1000);
	set("force_factor",40);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);
	set_skill("parry", 120);
	
	set("sell_all_day",1);
	set("inquiry", ([
		"����" : "����ר�����ֳ��̱���", 
	]) );

        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        }));

	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
// banker.c
// by dicky

inherit NPC;
inherit F_BANKER;


void create()
{
        set_name("��һ��", ({ "long yimen","long","boss"}) );
        set("title", "Ǯׯ�ϰ�");
        set("gender", "����" );
        set("age", 29);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("long",
"��һ���Ǹ��������ǳ���Ĭ���ˣ���ʱ�����Щ
�Ĳ����ɵ����ӣ����ľ���Ի�������������
������Ī��ĸо����Ͼ���ǰ���Ǹ������ˣ�����
һ������书��\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");

	set("max_atman", 500);
	set("atman", 500);
	set("max_neili", 2000);
	set("max_qi", 2000);
	set("max_sen", 2000);
	set("neili", 2000);
	set("force_factor", 20);
	set("max_mana", 500);
	set("mana", 500);
  set("no_get",1);
	set_skill("sword", 100);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	setup();
        
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();

        add_money("silver", 5);
}

int accept_fight(object me)
{
        command("say ����������˭�ĵ��̣���������Ұ����");
        command("heihei "+ me->query("id"));
        kill_ob(me);
        return 1;
}

void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}

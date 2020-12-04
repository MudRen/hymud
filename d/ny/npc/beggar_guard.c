
// beggar_guard.c

inherit NPC;

void create()
{
	set_name("ؤ���ߴ�����", ({ "beggar guard", "guard" }) );
	set("gender", "����" );
	set("age", 36);
	set("str", 29);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
��ؤ���ű�վ���Ƕ�,����Ц��!
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"��ؤ˵��������ؤ���ܶ�,���Ǻ��ǵ�!\n",
		"��ؤ˵������С�Ӳ�Ҫ����,����ؤ���ܶ���Ұ��\n",
		"��ؤ��������һ�����ջأ��ƺ���Щ���ǡ�\n",
		"��ؤ˵�������һ�����ɱ��,�Ͽ�����ȥ�ɡ�\n"
	}) );
	set("inquiry", ([
		"�ܶ�": "�������ؤ���ܶ棬ʩ���кι��?",
	]) );

        set("atman", 300);
        set("max_atman", 300);

        set("force", 600);
        set("max_force", 600);
        set("force_factor", 0);


        set("mana", 300);
        set("max_mana", 300);

        set("combat_exp", 20000);
        set("score", 2000);

        set_skill("staff", 30);
        set_skill("unarmed", 60);
        set_skill("force", 40);
        set_skill("dodge", 30);
        set_skill("parry", 40);



	
	setup();
	
	carry_object("/clone/misc/cloth.c")->wear();
	carry_object(__DIR__"obj/stick.c")->wield();
}



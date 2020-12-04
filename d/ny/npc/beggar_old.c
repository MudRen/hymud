
// beggar_old.c

inherit NPC;

void create()
{
	set_name("ؤ��Ŵ�����", ({ "beggar old","old", }) );
	set("gender", "����" );
	set("age", 50);
	set("str", 35);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
�������ڴ��ߣ��������ż�ҳ�ŷ���˫ü���壬��¶����֮ɫ!
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

        set("atman", 800);
        set("max_atman", 800);

        set("force", 1500);
        set("max_force",1500);
        set("force_factor", 0 );

        set("mana", 800);
        set("max_mana", 800);

        set("combat_exp", 55000);
        set("score", 10000);

        set_skill("staff", 70);
        set_skill("unarmed", 70);
        set_skill("force", 60);
        set_skill("dodge", 70);
        set_skill("parry", 60);


	
	setup();
	
	carry_object("/clone/misc/cloth.c")->wear();
	carry_object(__DIR__"obj/stick.c")->wield();
}

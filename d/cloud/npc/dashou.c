
// dashou.c

inherit NPC;

void create()
{
	set_name("����", ({ "dashou" }) );
	set("gender", "����" );
     set("shen_type",-1);
	set("age", 30);
     set("str", 15);
     set("cor", 30);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
    set("con", 30);
	set("long", @LONG
   ����վ�����ǰ��,˫�ֲ���,�޺޵ص�����. 
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 15);
	set("inquiry", ([
		"ɽ����": "�������ɽ���£�ʩ���кι��?",
	]) );

        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 800);
        set("max_force", 800);
        set("force_factor", 3);

        set("mana", 200);
        set("max_mana", 200);

        set("combat_exp", 10000);
        set("score", 1000);

        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);


	setup();


        carry_object(__DIR__"obj/cloth")->wear();
}

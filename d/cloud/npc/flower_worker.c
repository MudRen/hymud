
// flower_worker.c

inherit NPC;

void create()
{
        set_name("����", ({ "flower worker", "worker" }) );
        set("gender", "����" );
        set("age", 32);
        set("long", "��������æµ�š�\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
          set("str",15);
          set("con",30);
          set("cor",30);
          set("max_kee",300);
          set("max_force",500);
          set("force",500);
          set("kee",300);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
	set_skill("dodge", 30);
	set_skill("throwing", 10);

        set("inquiry", ([
		"�̺�����" : "��Ҫ��������ȥ�ʡ�", 
        ]) );

	setup();
	add_money("coin", 15);
        carry_object("/clone/misc/cloth")->wear();
}


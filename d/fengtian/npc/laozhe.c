// laozhe.c

inherit NPC;

void create()
{
	set_name("����", ({"old man"}));
        set("long", "����һλ��С�ݸɵ����ߣ����������
��ʱ�����������ż����һ̧ͷ���۾���
ȴ͸¶��ֻ���ڹ����ֲŻ��еľ��⡣\n");
        set("gender","����");

        set("age",50);
        set("con",30);
        set("str",30);
	set("kar",30);
	set("cor",35);



	set("max_atman",2000);
	set("atman",2000);
	set("max_mana",2000);
	set("mana",2000);
	set("max_kee",1500);
	set("max_gin",1500);
	set("max_sen",1500);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",50);

	set("attitude","peaceful");
	set("no_exp_gain",1);

	set("chat_chance_combat",20);
	set("chat_msg_combat",({
		(: perform_action, "unarmed.zui" :),
}));

        set("combat_exp",1500);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}


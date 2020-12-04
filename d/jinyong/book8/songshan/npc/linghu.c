// linghu.c �����

inherit NPC;
int ask_me();

void create()
{
	set_name("�����", ({ "linghu chong", "linghu", "chong" }));
	set("nickname", "��ʦ��");
	set("long", 
"�����Ľ��ݣ�����Ũü���ۣ������Ѱ�������ͬ���������ϴ�\n"
"�ǻ�ɽ������һ���еĶ�����֡�\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 12800);
	set("max_qi", 12800);
	set("jing", 11600);
	set("max_jing", 11600);
	set("neili", 12400);
	set("max_neili", 12400);
	set("jiali", 60);

	set("combat_exp", 1800000);
	set("score", 100000);
set_skill("chongling-jian", 380);
	set_skill("blade", 60);
	set_skill("cuff", 60);
	set_skill("feiyan-huixiang", 120);
	set_skill("hand", 60);
	set_skill("finger", 60);
	set_skill("strike",60);
	set_skill("claw", 60);
	set_skill("unarmed",125);
	set_skill("force", 150);
	set_skill("zixia-shengong", 320);
	set_skill("dodge", 180);
	set_skill("parry", 140);
	set_skill("sword", 190);
	set_skill("huashan-sword", 250);
	set_skill("lonely-sword",160);
	set_skill("literate", 80);
//	set_skill("chongling-jianfa", 60);

	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	map_skill("sword", "chongling-jian");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
(: perform_action, "sword.ai" :),
(: perform_action, "sword.jianzhang" :),	
(: perform_action, "sword.jie" :),	
(: perform_action, "sword.jm" :),	
(: perform_action, "sword.wudui" :),				
        }) );
	create_family("��ɽ��", 14, "����");

  	set("inquiry", ([
		"����" : (: ask_me :),
	]));	 

	setup();	 	
	carry_object("/d/heimuya/npc/obj/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_me()
{
	object me = this_player();
	message_vision("$N˵������ɽ�����ֻ��Ӧ����ϯ����������֮�⣬��λ"+ RANK_D->query_respect(me)+"���Ա㣡\n",this_object());
	me->set_temp("jinyong/book8/wuyue_henshan",1);
	destruct(this_object());
	return 1;
}
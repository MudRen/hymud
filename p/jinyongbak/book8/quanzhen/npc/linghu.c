// linghu.c �����

inherit NPC;
int ask_me();

void create()
{
	set_name("�����", ({ "linghu chong", "linghu", "chong" }));
	set("nickname", "��ʦ��");
	set("long", 
"�����Ľ��ݣ�����Ũü���ۣ������Ѱ�������\n"
"ͬ���������ϴ��ǻ�ɽ������һ���еĶ�����֡�\n");
	set("gender", "����");
	set("age", 28);
	set("class", "swordsman");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("qi", 3800);
	set("max_qi", 3800);
	set("jing", 3600);
	set("max_jing", 3600);
	set("neili", 3400);
	set("max_neili", 3400);
	set("jiali", 60);
	
	set("combat_exp", 2500000);
	set("score", 100000);
	set_skill("chongling-jian", 180);
	set_skill("blade", 180);
	set_skill("cuff", 180);
	set_skill("feiyan-huixiang", 180);
	set_skill("hand", 180);
	set_skill("finger", 180);
	set_skill("strike",180);
	set_skill("claw", 180);
	set_skill("unarmed",180);
	set_skill("force", 180);
	set_skill("zixia-shengong", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("huashan-sword", 180);
	set_skill("literate", 120);
	
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "huashan-sword");
	map_skill("sword", "chongling-jian");
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ai" :),
		(: perform_action, "sword.jianzhang" :),	
		(: perform_action, "sword.jie" :),	
		(: perform_action, "sword.jm" :),	
		(: perform_action, "sword.wudui" :),				
	      }) );
	create_family("��ɽ��", 14, "����");

	set("inquiry", ([
	     "�������": (: ask_me :),
       	]) );
       
	setup();	 	
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/clone/cloth/cloth")->wear();
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	object hong = present("hong renxiong",where);
	if(hong)
	{
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�����ȴ�����ǰ��λ�ɣ�\n",this_object(),who);
		return 1;
	}

  	if(((int)who->query("jinyong/book8")>=1))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	
	command("bow " + who->query("id"));
	message_vision("$N��$n˵���� ʲô������㣬�ҿ���������ޣ�ƽ�����޶�����\n",this_object(),who);
	message_vision("��˵��θ����ھ�����ͷ��ƽ֮·����ƽɱ�������������׺��Ķ��ӣ�����ɼ���ȫ����ȥ�˸�����Ҫ����\n",this_object());
	message_vision("��ʵ�ҿ�������С�£������ּҵĽ��ײŴ��¡�\n",this_object());
	message_vision("��γ����������ˣ���ȥ��Ҫ��ʦ����ȥ˼�����ˡ�\n",this_object());
	command("sigh");
	
	i = random(800);
	who->set("jinyong/book8",1);
	who->add("combat_exp",i+6800);
	who->add("potential",i*8);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
	tell_object (who,"��Ӯ����"+chinese_number(i+6800)+"�㾭��"+
	           chinese_number(i*8)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
	return 1;
}
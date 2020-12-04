// shi.c

inherit NPC;
int ask_me();

void create()
{
	set_name("ʷ��ͷ", ({ "shi biaotou", "shi" }));
	set("gender", "����");
	set("age", 45);

	set("combat_exp", 7000);
	set("shen_type", 1);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);

	set("inquiry", ([
	     "��ƽ֮": (: ask_me :),
       ]) );
       
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

int ask_me()
{
	if((int)this_player()->query("jinyong/book8")!=1)
	{
		message_vision("$N��$n˵���� ��ƽ֮������������ͷ�ˡ�\n",this_object(),this_player());
		return 1;
	}
	message_vision("$N��$n˵���� ��ƽ֮������������ͷ�ˣ������·����ƽɱ�������������׺��Ķ��ӡ�\n",this_object(),this_player());
	message_vision("��׺��ɳ�����ɺ���ǰ��Ѱ������ͷΪ�˱�ס�ּ�Ѫ�����Ѿ����˽�����ͷ�ͳ����⡣ \n",this_object(),this_player());
	this_player()->set_temp("jinyong/book8/biaoju_ask",1);
	return 1;
}

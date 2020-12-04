// Last Modified by Sir on May. 22 2001
// lin.c
inherit NPC;
int ask_me();

void create()
{
	set_name("����", ({ "yi lin", "lin" }) );
	set("long", 
	"�����Ƕ���ʦ̫����С��ͽ�ܣ�Ҳ�Ǻ�ɽ����С�ĵ��ӡ���һ˫���ۣ�\n"
	"�������������������Ȫ��һ�������������ף���������˼��̻�����\n"
	"ֻ�ǿ������м�����������Щ���ݡ�\n");
	set("gender", "Ů��");
	set("class", "bonze");
	set("age", 16);
	set("attitude", "peaceful");
	set("per", 30);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 3400);
	set("max_neili", 3400);
	set("jiali", 30);
	set("max_qi", 3500);
	set("max_jing", 3800);
	set("combat_exp", 600000);
	set("shen_type", 1);
	
	set_skill("unarmed", 50);
	set_skill("sword", 70);
	set_skill("force", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("strike", 50);
	set_skill("hand", 50);
	set_skill("buddhism", 100);
	set_skill("baiyun-xinfa",80);	
	set_skill("hengshan-jian", 200);
	set_skill("chuanyun-shou",100);
	set_skill("tianchang-zhang",70); 
	set_skill("lingxu-bu", 100);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");
	prepare_skill("strike", "tianchang-zhang");
	prepare_skill("hand", "chuanyun-shou");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yuyin" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),		
		(: exert_function, "recover" :),
	}) );
	
	set("inquiry", ([
	     "�����": (: ask_me :),
       	]) );
       	
	create_family("��ɽ��", 14, "����");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}

int ask_me()
{
	int i;

	object who = this_player();
	object where = environment(who);
	object tian = present("tian boguang",where);
	if(tian)
	{
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�����ȴ�����ǰ��λ�ɣ�\n",this_object(),who);
		return 1;
	}
	  	if(((int)who->query("jinyong/book8")>=3))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	command("wanfu " + who->query("id"));
	message_vision("$N��$n˵���� �����类�����ŷ����˼������������˼���¡�\n",this_object(),who);
	
	i = random(1000);
	who->set("jinyong/book8",3);
	who->add("combat_exp",i+12000);
	who->add("potential",i*10);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
	tell_object (who,"��Ӯ����"+chinese_number(i+12000)+"�㾭��"+
	           chinese_number(i*10)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
	return 1;
}
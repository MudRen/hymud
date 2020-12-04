// feng.c ������

inherit NPC;
int ask_me();

void create()
{
	set_name("������", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "��ɽ��ʮ�������ڳ���");
	set("long", 
"����ǵ������𽭺��Ļ�ɽ���޷�������������ۣ��������������ֽ��
����ݳ���ü���һֱ������һ�ɵ�����������ɫ����Ȼ�Ե���Ľ�������
֮��һֱ����������\n");
	set("gender", "����");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 70);
	set("int", 70);
	set("con", 70);
	set("dex", 70);
	
	set("qi", 39800);
	set("max_qi", 39800);
	set("jing", 38600);
	set("max_jing", 38600);
	set("neili", 54400);
	set("max_neili", 54400);
	set("jiali", 200);

	set("combat_exp", 15050000);
	set("score", 200000);

	set("fengset",1);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 380);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 380);
	set_skill("zixia-shengong", 380);
	set_skill("zixia-shengong", 380);
	set_skill("ziyunyin", 380);
	set_skill("zhengqijue", 380);
	set_skill("fanliangyi-dao", 380);
	set_skill("huashan-sword", 380);
	set_skill("hunyuan-zhang", 380);
	set_skill("lonely-sword", 380);
	set_skill("feiyan-huixiang",380);
	set_skill("literate", 200);
        set_skill("zhengqijue",380);
        set_skill("hunyuan-zhang", 380);
        set_skill("poyu-quan", 380);        
        set_skill("huashan-neigong", 380);        
        set_skill("chongling-jian", 380);
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("��ɽ��", 12, "����");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.wanjian" :),
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );

	set("inquiry", ([
	     "����": (: ask_me :),
       ]) );
       
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

int ask_me()
{
	int i;

	object who = this_player();
  	if(((int)who->query("jinyong/book8")>=4))
	{
		message_vision("$N��$n˵���� ����˵ʲô����\n",this_object(),who);
		return 1;	
	}
	say("��������������ɽ���������ĳ���˵��������ɽ��������Ϊ�������ڡ���\n");
	say("�����ڷ���Ϊ�����Խ�Ϊ���������˽����޼᲻�ݡ��������򷴵������ؽ�\n");
	say("���������ڸ��ּ���������ˮ���ݣ�ͬ�Ųٸ꣡������������Ⱥ��������\n");
	say("��֧����������Ұ�ģ������ʵ���ǰ����ɽ�μ��������ȥ�ˡ�����������\n");
	say("���ⲻƽʱ�����ػ�ɽ����֮λ����˵�Ѿ��������µ���ǰ������׼���ء�\n");
	say("ɱ����Ⱥһ���ˡ���������֮������һ������������ô���������أ���\n");
	i = random(1200);
	who->set("jinyong/book8",4);
	who->add("combat_exp",i+14000);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);
	//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
	tell_object (who,"��Ӯ����"+chinese_number(i+14000)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();
	return 1;
}

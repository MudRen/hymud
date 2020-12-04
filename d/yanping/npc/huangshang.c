// huangshan.c ����
// Last Modified by winder on Aug. 18 2002

inherit NPC;
string ask_book();
string ask_jing();

void create()
{
	set_name("����", ({ "huang shang", "huang", "shang" }));
	set("long","
�������ѣ������ˣ������١�����ɽ�������겻�ꡣ
��������Ϊ����ʱ�����п�����֮־��������״����ҽ�̶֮������ţ֮
�⣬�������գ�����֮�ţ�ʱ�б��֡�����������ƣ�����ȡ����ɳ���� 
���Ƿ�������ꡣ��Ԫ�����꣨1081������֮���ţ���Ϊ��������������
��֮����ʫ������������ҹ�ƿ�֦�������칫�����ޣ�Ī�������ټ�����
�Ž�ͷ������顣�����꣬���ѶԲߣ���Ϊ���µ�һ�������ڶԻ���֮��
�¼�Ϊϲ뼣������ʿ���л��������������Բߣ�ǰ��λ�Բ�������֮
�⣬���ڵȻ��������֣���δ�ײ�ʼ����������ߪΪ��һ�����������ʧ
ʵ��������
��������Ϊ���������ˡ����ͼ䣨1111��1118����֪���ݣ���Ϊ�����ɣ�
Ǩ���顣��ʱ���ᷨʵ�У�������Ϊ���˽�����Զ�����ٲ����ϣ��˸���
��ƶ�����������ڿƾ�֮�ơ������������ʮ���꣬���С���ɽ������ʮ
����������
    ��ʷ�ϣ�������һ��������������Ե��

");
	set("gender", "����");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "scholar");
	set("str", 128);
	set("int", 128);
	set("con", 128);
	set("jiuyin/full",1);
	set("jiuyin/shang",1);
	set("jiuyin/xia",1);
	set("jiuyin/emei",1);
	set("dex", 128);
  set("kar",58);	
	set("max_jing", 300000);
	set("max_qi", 500000);
	set("neili", 500000);
	set("max_neili", 50000);
	set("jiali", 50);
	set("combat_exp", 500000000);
	set("score", 60000);
	set("inquiry", ([
		"�ؼ�" : (: ask_jing :),
		"jing" : (: ask_jing :),
		"book" : (: ask_book :),
		"�����澭" : (: ask_jing :),
		"���ٵ���" : (: ask_book :),
	]));
	set_skill("jiuyin-zhengong",600);
	set_skill("jiuyin-shenfa",600);
	set_skill("jiuyin-shenzhua",600);
	set_skill("jiuyin-shenzhang",600);
	set_skill("dafumo-quan",600);
	set_skill("xuanyin-jian",600);
	set_skill("yinlong-bian",600);
	set_skill("daode-jing",600);
       set_skill("cuixin-zhang",600);

	map_skill("dodge", "jiuyin-shenfa");
	map_skill("force", "jiuyin-zhengong");

	map_skill("claw", "jiuyin-shenzhua");
	map_skill("strike", "jiuyin-shenzhang");
	map_skill("parry", "cuixin-zhang");
	map_skill("cuff", "dafumo-quan");
	map_skill("sword", "xuanyin-jian");
	map_skill("whip", "yinlong-bian");

	prepare_skill("strike","jiuyin-shenzhang");
	prepare_skill("claw","jiuyin-shenzhua");
	
set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield bian") :),
                (: perform_action, "sword.xuanyin" :),
                (: perform_action, "sword.xuanyin" :),
                (: perform_action, "sword.zhan" :),
                (: perform_action, "whip.chanrao" :),
                (: perform_action, "whip.feilong" :),
                (: perform_action, "claw.sanjue" :),
                (: perform_action, "strike.cuixin" :),
                (: perform_action, "dodge.huanyinbu" :),
                (: perform_action, "cuff.posha" :),
                (: perform_action, "cuff.fumo" :),
	}) );
        set_temp("apply/attack",150);
        set_temp("apply/defense",150);
        set_temp("apply/armor",600);
        set_temp("apply/damage",600);

	set("book_count", 1);
	set("jing_count", 1);
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city2/obj/hlbian");
}

string ask_book()
{
	mapping fam; 
	object ob, me = this_player();

	if (query("book_count") < 1)
		return "��ô���ص��飬"+RANK_D->query_respect(me)+ "Ҫ������ɶ�ã�";
	if (me->query_skill("taoism",1) < 100)
		return "�ⲿ���ٵ���̫�����"+RANK_D->query_respect(me)+ "���¶������գ�";
	add("book_count", -1);
	ob = new(__DIR__"obj/daojing");
	if (ob->violate_unique())
	{
		destruct(ob);
		return "��ô���ص��飬"+RANK_D->query_respect(me)+ "Ҫ������ɶ�ã�";
  }
	ob->move(environment(me));
	command("rumor "+me->query("name")+"�õ����ٵ�������\n");
	tell_room(environment(me), "����ת����ȥ��������ϱ���һ�����飬���ڵ��ϡ�\n", ({ob}));
	return "�ðɣ��ⲿ�����ٵ��ء����û�ȥ�ú����С�";
}

string ask_jing()
{
	mapping fam; 
	object ob, me = this_player();
	mixed sks;
	string skl;
	
	if (query("jing_count") < 1)
		return "�������澭�����Ҽ�ʮ����Ѫ��פ�����������";
	if ( !me->query("xkd/skill") )
		return "�������澭�������书�����"+RANK_D->query_respect(me)+ "���¶������գ�";
	if ( me->query("kar") != query("kar") && !wizardp(me))
		return "������Ե��ѧϰ�书Ҳ�������ģ��㿴���ܲ��ɣ���Ҫ�ġ������澭�����˽���δ����";
	add("jing_count", -1);
	ob = new(__DIR__"obj/9book");
	if (ob->violate_unique()) 
	{
		destruct(ob);
		return "�������澭�����Ҽ�ʮ����Ѫ��פ�����������";
	}
	sks = me->query("xkd/skill");
	if (arrayp(sks))
		skl = sks[random(sizeof(sks))];
	else	if (stringp(sks))
		skl = sks;
//	ob->set("skill/name", me->query("xkd/skill") );
	ob->set("skill/name", skl );
	ob->set("skill/exp_required", 1000000);
	ob->set("skill/jing_cost", 50);
	ob->set("skill/difficulty", 50);
	ob->set("skill/min_skill", 300);
	ob->set("skill/max_skill", 350);
	ob->move(me);
	command("rumor "+me->query("name")+"�õ������澭ԭ������\n");
	return "�Ȿ�������澭������ȥ�ú����У����н��档";
}

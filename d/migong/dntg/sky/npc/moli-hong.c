//modified by vikee for xlqy for NK_DX
//2000-11-23 16:18




inherit NPC;
void create()
{
        set_name("ħ���", ({ "moli hong", "guangmu tianwang", "hong", "tianwang" }) );
        set("gender", "����" );
	set("long",
		"ħ���Ľ�֮һ��ʹһ�˷��컭ꪣ�����һ��ɡ����Ի������Ԫɡ����\n"
                "ɡ�����鴩�ɣ�����ĸ�̣���ĸ�̣�ҹ���飬�ٳ��飬�ٻ��飬��ˮ\n"
                "�飬�����飬�����飬�����飬�����顣�������鴩�ɡ�װ��Ǭ����\n"
                "���֣����ɡ���ҳţ��ſ�ʱ���ذ��������޹⣬תһתǬ���ζ���\n"
	);
	set("age",50);
	set("title", "��Ŀ����");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_qi",3100);
	set("qi",3100);
	set("max_jing",3100);
	set("jing",3100);
	set("combat_exp",3000000);
        set("daoxing",3000000);
	set("neili",2500);
	set("max_neili",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 120);
	set("mana_factor",120);


        set("eff_dx", 1500000);
        set("nkgain", 800);

	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
	set("inquiry", ([
		"name" : "���¹�Ŀ����ħ��죬��ʥ�Ͱ��������š�",
		"here" : "�������������, ���ھ�������ˡ�",
	]) );

	setup();
	carry_object(__DIR__"obj/dragonstick")->wield();
	carry_object(__DIR__"obj/jinjia")->wear();
}


int accept_fight(object me)
{
        object ob=this_object();

    if( living(ob) )
      {
        message_vision("$N˵����ҲҪ��֪����������������\n", ob);
      }
        return 1;
}

void kill_ob (object me)
{
        object ob=this_object();

    if( living(ob) )
      {
        message_vision("$N˵�������������죡\n", ob);
       }
        ::kill_ob(me);

}


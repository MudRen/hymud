//sgzl

inherit NPC;

void create()
{
set_name("��ͯ",({"yun tong","yun shen","tong"}));
set("gender", "����");
set("age", 15);
set("long", "    \n�칬�и������Ƶ��������俴��ȥ������ᣬȴ\n�ƹ����������е��Ʋʡ�\n");

set("attitude", "heroism");
set("class", "xian");

    set("combat_exp", 800000);
  set("daoxing", 80000);


  

set("qi", 500);
set("max_qi", 500);
set("jing", 550);
set("max_jing", 550);
set("neili", 700);
set("max_neili", 700);
set("mana", 900);
set("max_mana", 900);
set("force_factor", 20);
set("mana_factor", 30);
set("per", 22);


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
  "����"   : "��������������ƣ����Ҳ��ܸ��㡣",
  "cloud"   : "��������������ƣ����Ҳ��ܸ��㡣",
  "name"   : "��������",
  "here"   : "��������칬��",
]));


setup();

carry_object(__DIR__"obj/xianpao")->wear();
carry_object(__DIR__"obj/yunlingfu");

}
���

// /d/yixing/npc/luzhengping.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("����ƽ", ({ "lu zhengping", "lu"}));
	set("title", HIC "�쵶��������" NOR);
	set("long", "ֻ����һ�Ź��ַ���������һ����ף��������������û�ˡ�\n");
	set("gender", "����");
	set("age", 41);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("combat_exp", 4000000);
set("jing", 24000);
	set("max_jing", 24000);
	set("qi", 24000);
	set("max_qi", 22000);
	set("neili", 25000);
	set("max_neili", 25000);
	set("jiali", 90);



	set_skill("force", 251);
	set_skill("parry", 180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 150);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	//map_skill("whip",  "riyue-bian");
	map_skill("parry", "ranmu-daofa");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 200);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);
	set_skill("yijinjing", 301);
	set_skill("ranmu-daofa", 300);
	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 190);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 190);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 190);
	set_skill("zui-gun", 190);
	set_skill("buddhism", 200);
	map_skill("blade", "ranmu-daofa");
	map_skill("claw", "longzhua-gong");
	//map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	//map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	//map_skill("sword", "fumo-jian");
     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "blade.huo" :),
                (: perform_action, "blade.fenxin" :),
                (: perform_action, "blade.fentian" :),
                            }) );
	set("chat_chance", 8);
	set("chat_msg", ({
		"����ƽ˵�������ְ��˾ͽ����밳���й����Ľ��飬����ȥ�ݷ������˼ҡ�\n",
	}) );

	set("inquiry",([
		"������" : "�´���������������������ȫ�����ʮ������",
		"���ְ�" : "��Ҳ��Ҫ�����ְ��ɽ��",
		"˾ͽ���" : "˾ͽ�����¾����ֵ��ҵ��¡�",
		"˾ͽ��" : "��˵���ְ�ļ������ҷ��Ϻ���������",
	]));

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
carry_object("/clone/misc/cloth")->wear();
}

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;


who->set_temp("book91121",1);
		
		

		
		
	::die();

}                        
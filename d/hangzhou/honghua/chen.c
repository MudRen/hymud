// chen.c �¼���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�¼���", ({ "chen jialuo", "chen","jialuo" }));
	set("title", HIR "�컨��"HIG"�ܶ���" NOR);
	set("long", 
"��һ��ģ��ֱ�Ǹ������˼ҵ������ӵܣ���������Ŀ�����ǣ���
�ۻ���������ҡ��һ�����ȣ���ɷ���������ţ�����˹�ġ���
��ٲȻ�Ǹ���鹫�ӡ�\n");
	set("nickname", HIY"��������"NOR);
	set("gender", "����");
	set("class", "scholar");
	set("age", 22);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
		set("max_qi", 52000);
	set("max_jing", 51000);
	set("neili", 50000);
	set("max_neili", 50000);
	set("jiali", 100);
	set_skill("force", 300);
	set_skill("honghua-shengong", 380);
	set_skill("dodge", 200);
	set_skill("youlong-shenfa", 380);
	set_skill("hand", 300);
	set_skill("benlei-shou", 380);
	set_skill("cuff", 200);
	set_skill("baihua-cuocuff", 380);
	set_skill("strike", 200);
	set_skill("heisha-zhang", 380);
	set_skill("throwing", 200);
	set_skill("wuying-feidao", 380);
	set_skill("blade", 200);
	set_skill("qiuge-dao", 380);
	set_skill("sword", 200);
	set_skill("luohua-jian", 380);
	set_skill("zhuihun-jian", 380);
	set_skill("parry", 200);
	set_skill("literate", 100);
	set_skill("medicine", 380);
		set_skill("painting", 380);


 set_skill("bainiao-jian", 380);
	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("cuff", "baihua-cuocuff");
	map_skill("hand", "benlei-shou");
	map_skill("strike", "heisha-zhang");
	//map_skill("throwing", "wuying-feidao");
	map_skill("sword", "bainiao-jian");
	//map_skill("blade", "qiuge-dao");
	map_skill("parry", "baihua-cuocuff");
	prepare_skill("cuff", "baihua-cuocuff");
	prepare_skill("hand", "benlei-shou");
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",2500);
	set_temp("apply/damage",2500);

	set("no_get",1);
	set("chat_chance_combat", 90); // ս���������������
	set("chat_msg_combat", ({
				(: command("wield changjian") :),
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.jiujian" :),
(: perform_action, "sword.qijian" :),				
		(: perform_action, "sword.taiji" :),
(: perform_action, "dodge.yunlong" :),				
				(: command("unwield changjian") :),
		(: perform_action, "cuff.cuo" :),
		(: perform_action, "hand.yunkai" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	set("env/wimpy", 60);

 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}


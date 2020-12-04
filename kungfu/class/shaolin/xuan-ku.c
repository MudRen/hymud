// Npc: /kungfu/class/shaolin/xuan-ku.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("�����ʦ", ({
		"xuanku dashi",
		"xuanku",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�������ݸߣ�\n"
		"�����������ƣ��ֱ۴������¶���ƺ��þ���˪��\n"
	);


	set("nickname", "�޺�������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 5500);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 220);
	set_skill("hunyuan-yiqi", 220);
	set_skill("dodge", 220);
	set_skill("shaolin-shenfa", 220);
	set_skill("parry", 220);
	set_skill("cuff", 220);
	set_skill("staff", 220);
	set_skill("blade", 220);
	set_skill("sword", 220);
	set_skill("wuying-jian", 220);
	set_skill("luohan-quan", 220);
	set_skill("weituo-gun", 220);
	set_skill("xiuluo-dao", 220);
	set_skill("fumo-jian", 220);
	set_skill("buddhism", 220);
	set_skill("literate", 220);
set_skill("damo-jian", 250);
set_skill("riyue-bian", 250);
set_skill("weituo-zhang", 250);
set_skill("shaolin-tantui", 250);
set_skill("jingang-zhang", 250);
set_skill("jimie-zhua", 250);
set_skill("duoluoye-zhi", 250);
set_skill("mohe-zhi", 250);
set_skill("boluomi-shou", 250);
set_skill("yijinjing",200);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "luohan-quan");
	map_skill("cuff", "luohan-quan");
	map_skill("staff", "weituo-gun");
	map_skill("blade", "xiuluo-dao");
	map_skill("sword", "fumo-jian");

	prepare_skill("cuff", "luohan-quan");

	create_family("������", 36, "����");

	set("inquiry", ([
		"ʮ���޺���"       : (: ask_me :),
		"�޺�����"	   : (: ask_me :)
	]));

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

#include "/kungfu/class/shaolin/xuan-ku.h"





inherit NPC;
#include <ansi.h>
void create()
{
	set_name("��֤��ʦ", ({
		"fangzheng dashi",
		"fangzheng",
		"dashi",
	}));
	set("long",
		"����һλ�����ü����ɮ����һϮ��˿������ġ�\n"
		"������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);

	set("nickname", "�����·���");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	set("jiali", 150);
	set("combat_exp", 10000000);
	set("score", 500000);

	set_skill("force", 450);
	set_skill("hunyuan-yiqi", 450);
	set_skill("dodge", 450);
	set_skill("shaolin-shenfa", 450);
	set_skill("finger", 450);
	set_skill("strike", 450);
	set_skill("hand", 450);
	set_skill("claw", 450);
	set_skill("parry", 450);
	set_skill("nianhua-zhi", 450);
	set_skill("sanhua-zhang", 450);
	set_skill("fengyun-shou", 450);
	set_skill("longzhua-gong", 450);
	set_skill("buddhism", 500);
	set_skill("literate", 300);
	set_skill("weituo-zhang", 450);
	set_skill("shaolin-tantui", 450);
	set_skill("jingang-zhang", 450);
	set_skill("jimie-zhua", 450);
	set_skill("duoluoye-zhi", 450);
	set_skill("mohe-zhi", 450);
	set_skill("boluomi-shou", 450);
	set_skill("yijinjing",450);
	
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 44, "����");

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void unconcious()
{
	die();
}
void die()
{
        object who = this_object()->query_temp("last_damage_from");
        if(who) {
		message_vision("$N˵���������ӷ����ּ���ս�ܣ�����Ȩ������ӯӯʩ�����Ժ����Ļ����˽���ʩ���ͻأ�ʩ�������Ա㡣\n" NOR,this_object());
	}
	destruct(this_object());
}
// chen.c �½���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_weiwang();
int ask_tuihui();
string ask_me();

void create()
{
	set_name("�½���", ({ "chen jinnan", "chen","jinnan" }));
	set("title", HIR "��ػ�"HIM"�ܶ���"NOR );
	set("nickname", HIC "Ӣ���޵�" NOR);
	set("long", 
		"\n����һ����ʿ����������������ɫ�Ͱ���\n"
		"������������������ػ��ܶ����½��ϣ�\n"
		"��˵ʮ�˰����գ�������ͨ��\n"
		"ż������߿��������پ���Ŀ����磬Ӣ�����ˡ�\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 130);
	set("int", 130);
	set("con", 130);
	set("dex", 130);
	
	set("max_qi", 432000);
	set("max_jing", 431000);
	set("neili", 433000);
	set("max_neili", 433000);
	set("jiali", 100);
	set("combat_exp", 18000000);
	set("score", 500000);

	set_skill("literate", 1000);
	set_skill("force", 1000);
	set_skill("dodge", 1200);
	set_skill("unarmed", 1200);
	set_skill("parry", 1000);
	set_skill("whip", 1300);
	set_skill("blade", 1300);
	set_skill("sword", 1000);
	set_skill("hand", 1200);
	set_skill("claw", 1200);
	set_skill("houquan", 1300);
	set_skill("yunlong-xinfa", 980);
	set_skill("yunlong-shengong", 980);
	set_skill("wuhu-duanmendao", 980);
	set_skill("yunlong-jian", 980);
	set_skill("yunlong-shenfa", 980);
	set_skill("yunlong-bian", 980);
	set_skill("yunlong-shou", 980);
	set_skill("yunlong-zhua", 980);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	create_family("������",1, "��ɽ��ʦ");
	set("book_count", 1);
        set("inquiry", ([
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ������ػᣬ�������λ����ѧ���ա�\n",
                "���帴��" : "ȥ�ײĵ�ͻش�����ϸ���ưɣ�\n",
                "����" : "�����£�\n",
                "�п�" : "�����£�\n",
                "����" :  (: ask_weiwang :),
                "��������" : (: ask_weiwang :),
		"��������" : (: ask_me :),
		"�˻�" : (: ask_tuihui :),
		"tuihui"   : (: ask_tuihui :),
	]) );
	set("env/wimpy", 60);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		"\n�½���ҡͷ̾�����۵��������������������������Ǻο���?\n",
		(: command("smile") :),
		(: command("poem") :),
		(: command("nomatch") :),
		(: command("haha") :),
		(: command("chat ��λ" + RANK_D->query_respect(this_player())+",������ԩ�޳𣬺α����?\n") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "blade.duan" :),
                (: perform_action, "blade.duan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
                (: perform_action, "unarmed.pofuchenzhou" :),
                (: perform_action, "blade.duan" :),                
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("wield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
		(: command("unwield blade") :),
	}) );
 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
    carry_object("/p/item/ritemtz3/wsword18")->wield();
    carry_object("/p/item/ritemtz3/ahands19")->wear();
	carry_object("/d/city2/obj/wwhip18");
	carry_object("/d/city/obj/wblade19");
}


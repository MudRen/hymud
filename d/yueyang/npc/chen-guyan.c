// chen-guyan.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�¹���", ({"chen guyan", "chen", "guyan"}));
	set("nickname", "ؤ�����ϳ�����");
	set("gender", "����");
	set("age", 50);
	set("long","����һ�������ֱ����������ߡ�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 9000);
	set("max_qi", 9000);
	set("jing", 10000);
	set("max_jing", 10000);
	set("neili", 13000);
	set("max_neili", 12000);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 190); // �����ڹ�
	set_skill("huntian-qigong", 190); // ��������
	set_skill("blade", 220); // ��������
	set_skill("liuhe-dao", 220); // �������ϵ�
	set_skill("hand", 185); // �����ַ�

	set_skill("dodge", 195); // ��������
	set_skill("xiaoyaoyou", 185); // ��ң��
	set_skill("parry", 190); // �����м�

	set_skill("strike",185);  // �����Ʒ�

	set_skill("xianglong-zhang",185);
        set_skill("liuhe-dao",300);
	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("blade", "liuhe-dao");
	map_skill("parry", "liuhe-dao");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.lianhuan" :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),              
                             
        }) );
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 10, "����");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

void attempt_apprentice(object ob)
{
	command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");
}
#include "/kungfu/class/gaibang/gaibang.h"

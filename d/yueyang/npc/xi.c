// xi.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�ɳ���", ({"xi zhanglao", "xi", "zhanglao"}));
	set("nickname", "ؤ������");
	set("gender", "����");
	set("age", 50);
	set("long", "����һ����İ��ֵ����ߣ��ֳ�һ�����ȣ�����ֱ�ʣ��Ǳ�����Ҹ��֡�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 12000);
	set("max_qi", 12000);
	set("jing", 12000);
	set("max_jing", 12000);
	set("neili", 13000);
	set("max_neili", 12000);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 90); // �����ڹ�
	set_skill("huntian-qigong", 90); // ��������
	set_skill("staff", 200); // �����ȷ�
	set_skill("fengmo-zhang", 200); // ��ħ��
	set_skill("hand", 85); // �����ַ�

	set_skill("dodge", 95); // ��������
	set_skill("xiaoyaoyou", 85); // ��ң��
	set_skill("parry", 90); // �����м�

	set_skill("strike",85);  // �����Ʒ�
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	map_skill("force", "huntian-qigong");

	map_skill("staff", "fengmo-zhang");
	map_skill("parry", "fengmo-zhang");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");
set_skill("force", 295);            // �����ڹ�
	set_skill("huntian-qigong", 290);   // ��������
	set_skill("hand", 290);             // �����ַ�

	set_skill("staff", 290);            // �����ȷ�

	set_skill("dodge",290);            // ��������
	set_skill("xiaoyaoyou", 295);       // ��ң��
	set_skill("parry", 285);            // �����м�
	set_skill("staff", 290);            // ��������
	set_skill("strike",285);  // �����Ʒ�

	set_skill("xianglong-zhang",185);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

		set_skill("fengmo-zhang",280);
	set_skill("liuhe-zhang",280);
	set_skill("strike",290);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 280);   // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 280);       // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 280);            // ��������
	set_skill("dagou-bang", 280);        // �򹷰���
	set_skill("begging", 280);          // �л�����
	set_skill("checking", 280);         // ����;˵
	set_skill("training", 280);        // Ԧ����
	
	map_skill("force", "huntian-qigong");

	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                        
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 10, "����");

	setup();

	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	command("say �Ϸ���ͽ�ܣ�" + RANK_D->query_respect(ob) + "������ذɡ�");
}
#include "/kungfu/class/gaibang/gaibang.h"

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
message_vision("$N˵�����Ƿ���������������......\n" NOR,this_object());
who->set_temp("killtlbb12",1);
	::die();
}
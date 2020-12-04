// xu.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�쳤��", ({"xu zhanglao", "xu", "zhanglao"}));
	set("gender", "����");
	set("age", 85);
	set("long", "����Ʈ��������һ�������۵����£��Ǹ���ͼ��ߵ���ؤ��\n");

	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 22000);
	set("max_qi", 22000);
	set("jing", 21000);
	set("max_jing", 21000);
	set("neili", 31500);
	set("max_neili", 31500);
	set("jiali", 100);

	set("combat_exp", 1200000);
	set("score", 20000);
	
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
	set_skill("force", 100);             // �����ڹ�
	set_skill("huntian-qigong", 280);   // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 280);       // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 260);            // ��������
	set_skill("dagou-bang", 260);        // �򹷰���
	set_skill("begging", 260);          // �л�����
	set_skill("checking", 260);         // ����;˵
	set_skill("training", 260);        // Ԧ����
	
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
	create_family("ؤ��", 8, "����");

	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
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
who->set_temp("killtlbb13",1);
	::die();
}
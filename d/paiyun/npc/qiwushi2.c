// xi.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({"han zhanglao", "han", "zhanglao"}));
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

	set("qi", 15000);
	set("max_qi", 15000);
	set("jing", 15000);
	set("max_jing", 15000);
	set("neili", 35000);
	set("max_neili", 35000);
	set("jiali", 100);
	
	set("combat_exp", 1000000);
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
set_skill("force", 195);            // �����ڹ�
	set_skill("huntian-qigong", 190);   // ��������
	set_skill("hand", 190);             // �����ַ�

	set_skill("staff", 190);            // �����ȷ�

	set_skill("dodge",190);            // ��������
	set_skill("xiaoyaoyou", 195);       // ��ң��
	set_skill("parry", 185);            // �����м�
	set_skill("staff", 190);            // ��������
	set_skill("strike",185);  // �����Ʒ�

	set_skill("xianglong-zhang",185);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

		set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
	set_skill("strike",190);
	set_skill("force", 200);             // �����ڹ�
	set_skill("huntian-qigong", 180);   // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	
	set_skill("dodge", 160);      	     // ��������
	set_skill("xiaoyaoyou", 180);       // ��ң��
	set_skill("parry", 160);             // �����м�
	set_skill("staff", 180);            // ��������
	set_skill("dagou-bang", 220);        // �򹷰���
	set_skill("begging", 180);          // �л�����
	set_skill("checking", 180);         // ����;˵
	set_skill("training", 180);        // Ԧ����
	
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
	set("party/rank", RED"��������"NOR);
	set("party/level", 6);
	create_family("ؤ��", 11, "����");
          set_temp("apply/attack", 100);
        set_temp("apply/defense",100);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 800);
	setup();

	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
}


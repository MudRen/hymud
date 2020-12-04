// song.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�γ���", ({"song zhanglao", "song", "zhanglao"}));
	set("nickname", "ؤ������");
	set("gender", "����");
	set("age", 50);
	set("long", "����һ���������ߣ��Ǳ���������ű������֡�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 12000);
	set("max_qi", 12000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 13000);
	set("max_neili", 12000);
	set("jiali", 100);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 290); // �����ڹ�
	set_skill("huntian-qigong", 290); // ��������
	set_skill("hand", 185); // �����ַ�

	set_skill("dodge", 195); // ��������
	set_skill("xiaoyaoyou", 255); // ��ң��
	set_skill("parry", 190); // �����м�

	set_skill("strike",185);  // �����Ʒ�

	set_skill("xianglong-zhang",255);

	map_skill("unarmed","xianglong-zhang");
	map_skill("strike","xianglong-zhang");
	prepare_skill("strike","xianglong-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("hand", "suohou-hand");
	map_skill("parry", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", RED"�Ŵ�����"NOR);
	set("party/level", 9);
	create_family("ؤ��", 10, "����");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
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
who->set_temp("killtlbb11",1);
	::die();
}
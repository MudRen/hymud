// gaibang npc code
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ȫ����", ({"quan guanqing", "quan", "guanqing"}));
	set("title", "ؤ��˴�����");
	set("gender", "����");
	set("age", 35);
	set("long", 
		"����λ��Ĭ����ȴ�����ļƵ�������ؤ��˴����ӡ�\n");
	set("attitude", "peaceful");
        set("beggarlvl",8);
        set("class", "beggar");
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("max_qi", 9360);
	set("max_jing", 9300);
	set("neili", 9710);
	set("max_neili", 9710);
	set("jiali", 36);
	
	set("combat_exp", 169000);
	
	set_skill("force", 175); 
	set_skill("huntian-qigong", 252); 
	set_skill("unarmed", 175); 
	set_skill("xianglong-zhang", 255); 
	set_skill("dodge", 168); 
	set_skill("xiaoyaoyou", 250); 
	set_skill("parry", 170); 
	set_skill("staff", 211); 
	set_skill("begging", 170); 
	set_skill("training", 160);
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
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 19, "����");
	setup();
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
message_vision("$N˵�����Ƿ��ǹ�����......\n" NOR,this_object());
who->set_temp("killtlbb7",1);
	::die();
}
// huangzhong-gong.c
inherit NPC;
#include <ansi.h>;

void create()
{
        set_name("���ӹ�", ({ "huangzhong gong", "gong" }));
        set("title", "÷ׯ��ׯ��");
        set("long",
                "������÷ׯ��λׯ�����е�һ�Ļ��ӹ���\n"
                "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
                "����������Ѯ������еȣ����ݺͰ����ס�\n");
        set("gender", "����");
        set("age", 62);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 38);
        set("int", 38);
        set("con", 38);
        set("dex", 38);
        
        set("max_qi", 100000);
        set("max_jing", 100000);
        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 50);
        set("combat_exp", 6000000);
        set("shen", 15000);
        set("score", 60000);
        
	set_skill("songshan-jian", 380);
	set_skill("luoyan-jian",380);
	set_skill("shiba-pan",380);
	set_skill("liuhe-dao",380);
	set_skill("hengshan-jian",380);
	set_skill("force", 400);
	set_skill("luteplaying", 350);  
	set_skill("wuzheng-xinfa", 400);
	set_skill("dodge", 400);
	set_skill("piaoyibu", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("wuyun-jian", 400);
	set_skill("daya-sword", 400);
	set_skill("xuantian-zhi", 400);
	set_skill("pomopima-jian", 400);
	set_skill("jiangjun-zhang", 400);
	set_skill("shigu-bifa", 400);
	
	set_skill("literate", 220);
	set_skill("kuihua-xinfa", 400);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	map_skill("force", "wuzheng-xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jian");
	
	map_skill("finger", "xuantian-zhi");
	prepare_skill("finger", "xuantian-zhi");
	
	map_skill("sword", "wuyun-jian");

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
		(: perform_action, "sword.jue" :),
		(: perform_action, "sword.meng" :),                	
		(: perform_action, "sword.shan" :),
		(: perform_action, "sword.zhu" :),
		(: perform_action, "sword.yin" :),
		(: perform_action, "dodge.wuguyuehua" :),
		(: perform_action, "finger.sixiao" :),
		(: exert_function, "shield" :),
		(: exert_function, "power" :),
        }) );

	if (random(2)==0)
	{
		map_skill("sword", "daya-sword"); 
		map_skill("parry", "daya-sword"); 
		set("chat_chance_combat", 99);
		set("chat_msg_combat", ({
		(: perform_action, "sword.daya" :),
		(: perform_action, "sword.qijian" :),                	
		(: perform_action, "sword.sha" :),
		(: perform_action, "finger.sixiao" :),
		(: perform_action, "dodge.wuguyuehua" :),
		(: exert_function, "shield" :),
		(: exert_function, "power" :),
 	}) );

}
        create_family("÷ׯ", 1, "ׯ��");
        setup();
        carry_object("clone/weapon/changjian")->wield();
}

void unconcious()
{
	die();
}
void die()
{
        object who = this_object()->query_temp("last_damage_from");
	if(who) {
		message_vision("$N̾�������������ǳ���������ǰ�ˣ������ˣ����ˣ������е�����Ҳ���ٲ����ˡ�\n" NOR,this_object());
	}	
	destruct(this_object());
}
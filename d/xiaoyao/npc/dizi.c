// qingyun.c
// shilling 97.2

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("��ͯ", ({ "shi tong", "shitong" }));
	set("long", 
		"���Ǻڰ�����ʿ��һ��ʮ���������������\n");
	set("gender", "����");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("str", 35);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	
	set("max_qi", 11000);
	set("max_jing", 11000);
	set("neili", 11000);
	set("max_neili", 11000);
	set("jiali", 100);
	set("combat_exp", 1200000);
	set("score", 50000);
set("title","��ң������");
	set_skill("blade",200);
	set_skill("ruyi-dao",200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("lingboweibu", 200);
	set_skill("beiming-shengong",200);
	set_skill("liuyang-zhang", 200);
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "dodge.lingbo" :),
                (: exert_function, "strike.zhong" :),                
                (: exert_function, "strike.zhong" :),                
	}) );
	map_skill("unarmed", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");


	create_family("��ң��", 4, "����");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();

}


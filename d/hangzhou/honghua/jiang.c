// jiang.c ���ĸ�

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���ĸ�", ({ "jiang sigen", "jiang","sigen" }));
	set("title", HIR "�컨��"HIG"ʮ������" NOR);
	set("nickname", HIY "ͭͷ����" NOR);
	set("long", 
"ͭͷ���㽯�ĸ��ڻ�������ʮ���ѽ��Σ�������������\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 21);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 21100);
	set("max_jing", 22800);
	set("neili", 21000);
	set("max_neili", 21000);
	set("jiali", 100);
	set("combat_exp", 1500000);

	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("unarmed", 180);
	set_skill("parry", 180);
	set_skill("club", 180);
	set_skill("houquan", 180);
	set_skill("yunlong-shengong", 180);
	set_skill("zui-gun", 120);
	set_skill("yunlong-shenfa", 180);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("club", "zui-gun");
	map_skill("parry", "zui-gun");
	set("env/wimpy", 20);

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiejiang")->wield();
}


// zhou.c ����Ӣ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����Ӣ", ({ "zhou zhongying", "zhou","zhongying" }));
	set("title", HIC "����ׯׯ��" NOR);
	set("nickname", HIW "����" NOR);
	set("long", 
"���׷�Ʈ�����������壬�����������ֵ�����������������Ӣ��\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 61);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 18000);
	set("max_jing", 13000);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 100);
	set("combat_exp", 3500000);
	set("score", 500000);

	set_skill("force", 280);
	set_skill("dodge", 280);
	set_skill("unarmed", 280);
	set_skill("parry", 280);
	set_skill("throwing", 280);
	set_skill("mantian-xing", 280);
	set_skill("hunyuan-yiqi", 280);
	set_skill("jingang-quan", 280);
	set_skill("shaolin-shenfa",280);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "hunyuan-yiqi");
	map_skill("throwing", "mantian-xing");
	map_skill("parry", "jingang-quan");
	map_skill("unarmed", "jingang-quan");

	set("env/wimpy", 20);
	create_family("������", 51, "�׼ҵ���");
 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiedan")->wield();
}


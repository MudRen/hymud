// shi.c ʯ˫Ӣ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ʯ˫Ӣ", ({ "shi shuangying", "shi","shuangying" }));
	set("title", HIR "�컨��"HIG"ʮ������" NOR);
	set("nickname", HIG "�����" NOR);
	set("long", 
"�����ʯ˫Ӣ�ڻ�������ʮ���ѽ��Σ�ִ�����ã�������˽���ĺ���
�������˹����ľ����ӵ����ĺ��ǣ���Ҳ������ץ�����̣�ԭ�����ݺ�
��������������ֵܷ��˴������һʱ��Ϳ���˺���Ļ��򣬿��ڿ�
����ִ��֮ǰ�������ü⵶�ڴ�����������������������Դ���������
��ν��������������Ȼ����ùܶ�����ִ��������ˡ���������ᷢ�䣬
�����������س��Բ�����ˡ�����Ժ컨�������ֵܣ��ᵽ�����ʱ�޲�
�Ȼ��\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 26);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 21500);
	set("max_jing", 2700);
	set("neili", 21000);
	set("max_neili", 21000);
	set("jiali", 100);
	set("combat_exp", 2000000);

	set_skill("force", 290);
	set_skill("dodge", 290);
	set_skill("unarmed", 290);
	set_skill("parry", 290);
	set_skill("sword", 290);
	set_skill("taiji-quan", 295);
	set_skill("taiji-shengong", 290);
	set_skill("taiji-jian", 290);
	set_skill("tiyunzong", 290);

	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji-shengong");
	map_skill("unarmed", "tianji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	set("env/wimpy", 20);
	create_family("̫����",8, "����");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}



// Obj: /d/nanshaolin/obj/kongchan.c
// Last Modified by winder on May. 29 2001

inherit NPC;
void create()
{
	set_name("����ʯ��", ({ "kongchan shiren", "kongchan", "shiren" }));
	set("long", "�����Զ���޷�����������֮��ò��\n"
		"�����Ŀ���ߴ�ͦ�Σ����˾��ľ������䡣\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 200);
	set_skill("force", 140);
	set_skill("yijinjing",140);
	set_skill("damo-jian", 140);
	set_skill("dodge", 140);
	set_skill("shaolin-shenfa", 140);
	set_skill("leg", 140);
	set_skill("parry", 140);
	set_skill("buddhism", 140);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("leg", "damo-jian");
	map_skill("parry", "damo-jian");
	prepare_skill("leg", "damo-jian");
	setup();
}
#include "chan.h"
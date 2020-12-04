// /d/yixing/npc/fanyifei.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("��һ��", ({ "fan yifei", "fan"}));
	set("title", HIB "�ױ���������" NOR);
	set("long", "����һ�����ݵ����ߣ�һ�ź�������������й�
�ʣ��˳ơ��ɶ��ס���\n");
	set("gender", "����");
	set("age", 51);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("combat_exp", 4000000);
	  set("max_qi", 32000);
        set("max_jing", 32000);
        set("neili", 32000);
        set("max_neili", 32000);
        set("jiali", 80);
        set("combat_exp", 5000000);
        set("shen", 15000);
        set("score", 60000);

set_skill("painting", 320);
        set_skill("force", 220);
        set_skill("wuzheng-xinfa", 220);
        set_skill("dodge", 200);
        set_skill("piaoyibu", 210);
        set_skill("parry", 220);
        set_skill("dagger", 300);
        set_skill("shigu-bifa", 340);
        set_skill("literate", 330);
set_skill("jiangjun-zhang",300);
set_skill("kuihua-xinfa", 300);
        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "shigu-bifa");
        map_skill("dagger", "shigu-bifa");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",2500);
	set_temp("apply/damage",2400);


	set("chat_chance", 3);
	set("chat_msg", ({
		"��һ��˵�������ְ��˾ͽ����밳���й����Ľ��飬����ȥ�ݷ������˼ҡ�\n",
	}) );

	set("inquiry",([
		"������" : "�´�������������������������ҪѨ����һ�㡣",
		"���ְ�" : "��Ҳ��Ҫ�����ְ��ɽ��",
		"˾ͽ���" : "˾ͽ�����¾����ֵ��ҵ��¡�",
		"˾ͽ��" : "��˵���ְ�ļ������ҷ��Ϻ���������",
	]));
	setup();
	carry_object("/d/meizhuang/npc/obj/panguan-bi")->wield();
	carry_object("/clone/misc/cloth")->wear();
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


who->set_temp("book91124",1);
		
		

		
		
	::die();

}  
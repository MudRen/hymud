// xuanruhui.c �����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"�����"NOR, ({"xuan ruhui", "xuan"}));
       set("long", "������һ�������ʦ����ͶԵ��ϧ�����ಡ�����书���ߡ�\n");
       set("title", HIC"��һ��"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 63);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "�ϵ���");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 120);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

    

	create_family("����ɽ", 3, "��");
	
	set("inquiry", ([
	"name"     : "��������Ǵ�����ʦ���µ��������ӡ�\n",
	"here"     : "������ʦΪ����ѹ��ħ���������￪ɽ���̣�����������\n",
	"����"     : "���������һ����������ɽ�ǽ��أ��㲻Ҫ��ȥ����\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/bagua");
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}


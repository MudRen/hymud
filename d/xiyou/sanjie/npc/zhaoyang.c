// zhaoyang.c ������ʦ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIR"������ʦ"NOR, ({"master zhaoyang", "master"}));
       set("long", "��һ�����Ŵ�ʦ�֣��¸�¡�أ���Ϊ����������\n");
       set("title", HIC"��һ��"NOR);
       set("per", 40);
       set("gender", "����");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "�ϵ���");
       set("max_kee", 1500);
       set("max_gin", 100);
       set("max_sen", 1500);
       set("force", 1800);
 

	
	create_family("����ɽ", 2, "��");
	
	set("inquiry", ([

	"name"     : "������һ�������ƽ̴���ӣ�����Գƺ��ҳ�����ʦ��\n",
	"here"     : "��������һ��������·�ˣ�\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}


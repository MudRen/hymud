// huanwangzi.c ������

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"������"NOR, ({"huan wangzi", "huan"}));
       set("long", "ϲ���ٻ����󣬲����޵���ƶ��Ͷ��ħ����Ϊ��������\n");
       set("title", HIC"��һ��"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 65);
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
       set("max_mana", 1200);
       set("mana", 1200);
       set("mana_factor", 120);
       set("combat_exp", 1200000);
     

	create_family("����ɽ", 3, "��");
	
	set("inquiry", ([
	"name"     : "����Խ��һ����ӡ�\n",
	"here"     : "���ﲻ�Ǻõط���������ٻ����󣬿��Ը���һ���ߡ�\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}

// juseng.c ��ɮ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"��ɮ"NOR, ({"ju seng", "ju"}));
       set("long", "���߾��ɣ��������ͣ��㿪ɽ������\n");
       set("title", HIC"������"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 400);
       set("max_force", 400);
       set("force_factor", 20);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("staff", 80);  
        set_skill("force", 80);   

	set("inquiry", ([
	"name"     : "������˧���¾Ŵ����֮һ��\n",
	"here"     : "��������������\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
// 41          carry_object("/d/xiyou/sanjie/obj/nine-ring")->wield();
}

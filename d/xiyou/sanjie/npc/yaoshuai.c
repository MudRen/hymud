// yaoshuai.c ��˧

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"��˧"NOR, ({"yao shuai", "yao"}));
       set("long", "������Ψһ���ˣ������оŴ���֡�\n");
       set("title", HIC"������"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 50);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("max_kee", 1500);
       set("max_gin", 100);
       set("max_sen", 1500);
       set("force", 1800);
       set("max_force", 1800);
       set("force_factor", 180);
     
        create_family("����ɽ", 2, "��");

	set("inquiry", ([
	"name"     : "������˧�����������ˡ�\n",
	"here"     : "��������������\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/bintiegun")->wield();
}


// wiuxuke.c ����

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"����"NOR, ({"qiu xuke", "qiu"}));
       set("long", "���׿��޵���ѧϰ�����������ڴ�ʦ�֣����޹��뿪ʦ�ţ���Ѷȫ�ޣ�\n");
       set("title", HIC"��һ��"NOR);
       set("per", 30);
       set("gender", "����");
       set("age", 35);
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
       set("combat_exp", 1400000);
       set("daoxing", 1500000);

        set_skill("dodge", 80);
 
	create_family("����ɽ", 3, "��");
	
	set("inquiry", ([
	"name"     : "�ҽ����ͣ������ҵ���������������㲻��Ҳ�ա�\n",
	"here"     : "���Ǻ�ɽ���أ�û����׼���ܽ������������Ȼ�Ե���Ҳ�����Ե�֡�\n",
	"����"     : "����İ���ͼ����ͨ����һ�ɸ�����������û��������֣���Ҫ��Ե�ˡ�\n",
	]));
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}

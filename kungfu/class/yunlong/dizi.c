// xuanzhen.c �������

#include <ansi.h>
inherit NPC;


void create()
{
	set_name("����", ({ "yl dizi", "dizi" }));
	set("gender", "����");
	if (random(2)==0) set("gender", "Ů��");
	set("title", HIR "��ػ�"HIG"�ܶ�"NOR"����");
	set("long", "\n��λ��Ĭ���Ե��ˣ�������ػ���ľ�û�����\n"+
		"��ػ�ѵ���ĺ��֣�һ������ʹ�ó����뻯��\n");
	set("age", random(30)+20);
	set("class", "taoist");
	set("int", 30);
	set("per",random(40));
	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("shen_type", 1);

	set("combat_exp", 2200000);
	set("attitude", "friendly");

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 100);
	set_skill("whip", 80);
	set_skill("hand", 70);
	set_skill("claw", 70);
	set_skill("yunlong-shengong", 170);
	set_skill("yunlong-shenfa", 170);
	set_skill("yunlong-xinfa", 170);
	set_skill("yunlong-bian", 170);
	set_skill("yunlong-jian", 280);
	set_skill("yunlong-shou", 150);
	set_skill("yunlong-zhua", 250);
	set_temp("apply/attack", 170);
	set_temp("apply/defense", 170);
	set_temp("apply/damage", 160);

	map_skill("force", "yunlong-shengong");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-jian");
	map_skill("sword", "yunlong-jian");
	map_skill("hand", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand", "yunlong-shou");
	prepare_skill("claw", "yunlong-zhua");
	create_family("������",3, "����");
	set("book_count", 1);
        set("inquiry", ([
		"�½���" :  "\n��������ֵ�ﵽ70�Ϳ��԰��ܶ���Ϊʦ��\n",
		"��ػ�" :  "\nֻҪ��Ӣ�ۺú���������������ػ�(join tiandihui)��\n",
		"���" :  "\nֻҪ��������ػᣬ��������и�λ����ѧ�书��\n",
                "���帴��" : "ȥҩ�̺͹ײĵ���ϸ���ưɣ�\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({

                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
                      }) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
        
}


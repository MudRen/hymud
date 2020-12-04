// zhang3.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

int do_skills(string arg);
int do_join(string arg);

void create()
{
	set_name("������", ({ "zhang laosan", "zhang" }));
	set("title", HIY"������"NOR"СͷĿ");
	set("gender", "����");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "����һ��������ͷ,һ˫С�۾��������⡣\n");
	set("combat_exp", 25000);
	set("score", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");

set("max_qi", 28000);
	set("max_jing", 28000);
	set("neili", 28000);
	set("max_neili", 28000);
//	set("jiali", 100);
	set("combat_exp", 5500000);
	set("score", 2400000);
        set_skill("claw", 100);
        set_skill("strike", 100);
	set_skill("dulong-shenzhua", 250);
	set_skill("xuanming-zhang", 250);
        set_skill("force", 150);
	set_skill("shenlong-xinfa", 150);
        set_skill("dodge", 150);
	set_skill("yixingbu", 200);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 200);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 200);
        set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("zhaosheshu", 150);
        set_skill("yangsheshu", 150);
	set_skill("shedao-qigong", 250);
	set_skill("literate", 190);

	create_family("������",2,"����");
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "juehu-shou");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "juehu-shou");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("hand", "juehu-shou");


	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.luanhuan" :),
                (: perform_action, "parry.juehu" :),
                (: perform_action, "parry.juehu" :),                
                (: perform_action, "parry.juehu	" :),                
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
	set("inquiry", ([
		"������" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "\nһ�������벻���������̵�(join shenlongjiao).\n",
		"�鰲ͨ" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
		"����" :  "\n����Ƣ������,Ҫ�������Ĳźá�\n",
		"�ں�" : "\n���겻��!�����ɸ�!��������!������ʥ!\n",
	]) );
	set("chat_msg", ({
"�����������е�:������ѵ,ʱ������,�����˵�,���²���!\n",
"�����������е�:��־���Ŀɳɳ�,���������ޱ���!\n",
"�����������е�:��������������,���������ǰ˷�!\n",
"�����������е�:�˷����˳�Ӣ��,������ͬ���¹�!\n",
"�����������е�:���������ɸ�,��������!\n",
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_join","join");
}

int recognize_apprentice(object ob)
{
	if (ob->query("party/party_name") == HIY "������" NOR)
	{
		message_vision("$Nҡ��ҡͷ��\n",this_object());
	command("tell "+ob->query("id")+"�����ز���ʶ������ʲôҪ�����أ� \n"); 
		return 0;
	}
	return 1;	
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	who->add_temp("book723",1);
	::die();
}

#include "/kungfu/class/shenlong/shenlong.h";

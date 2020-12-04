// shou.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);

void create()
{
	set_name("��ͷ��", ({ "shou toutuo", "shou" ,"toutuo"}));
	set("title", HIY"������"NOR"�һ���");
	set("nickname",HIR "�ɶ�������" NOR);
	set("long", "��ͷ������氫, �����ֵó���, �����˾ͻ�������һ���󶬹�.\n��������Դ��ϵ���һ��ͭ�����, ���ӷǳ�����.\n" );
	set("gender", "����");
	set("age", 44);
	set("str", 35);
	set("dex", 20);
		set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("combat_exp", 500000);
        set_skill("claw", 100);
        set_skill("strike", 100);
	set_skill("dulong-shenzhua", 180);
	set_skill("xuanming-zhang", 180);
        set_skill("force", 150);
	set_skill("shenlong-xinfa", 180);
        set_skill("dodge", 150);
	set_skill("yixingbu", 200);
        set_skill("hand", 200);
	set_skill("shenlong-bashi", 180);
        set_skill("strike", 200);
	set_skill("huagu-mianzhang", 180);
        set_skill("parry", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("zhaosheshu", 180);
        set_skill("juehu-shou", 150);
        set_skill("yangsheshu", 180);
	set_skill("shedao-qigong", 180);
	set_skill("literate", 190);

	
	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "juehu-shou");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "juehu-shou");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
(: perform_action, "strike.bujue" :),
(: perform_action, "strike.hua" :),
(: perform_action, "strike.lianhuan" :),
                (: perform_action, "strike.bujue" :),
                                (: perform_action, "strike.hua" :),
                (: perform_action, "strike.lianhuan" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.shewu" :),
                (: perform_action, "hand.flower" :),
                (: perform_action, "hand.meinu" :),                
                (: perform_action, "hand.yingxiong" :),                
                      }) );
	create_family("������",2,"����");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 30);
	set_temp("apply/damage", 50);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
        set("inquiry", ([
		"������" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"���" :  "һ�������벻���������̵�(join shenlongjiao).\n",
		"�鰲ͨ" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"����" :  "����Ƣ������,Ҫ�������Ĳźá�\n",
		"�ں�" : "���겻��!�����ɸ�!��������!������ʥ!\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 30);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "������" NOR ) {
		command("say �㲻�Ǳ��̽���, ����������!");
		return;
	}
	if ((int)ob->query("shen") > 0  ) {
		command("say �������������������������������ְ׵�����򽻵�������ذɣ�");
		return;
	}
	command("say �ܺã��ܺá�");
	command("recruit " + ob->query("id"));
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	who->add_temp("book752",1);
	::die();
}

#include "/kungfu/class/shenlong/shenlong.h"; 

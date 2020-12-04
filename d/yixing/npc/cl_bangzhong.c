// /d/yixing/npc/cl_bangzhong.c ����
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("����", ({ "changle bangzhong", "bangzhong" }));
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "������");
	set("long", "����һ������Ϊ�������ĳ��ְ��ڡ�\n��������ת���ƺ�������ʲô�����⡣\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

 set("max_qi",1300+random(1690));
  set("max_jing",1300+random(1890));
  set("max_sen",1300+random(1890));
  set("max_neili",2300);
  set("max_mana",1300+random(1890));
  set("eff_neili",1300+random(1390));
  set("neili",2300);
        set("per", 28);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(2000000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),

        }) );
        set_skill("force",200);
        set_skill("taiji-shengong",200);
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 180+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        map_skill("force", "taiji-shengong");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 80);

	set("inquiry", ([
		"���ְ�" : "������ǳ��ְ��ܶ����ڵء�",
		"˾ͽ��" : "�Ҷ����ǰ������˼ҵľ���֮�飬�������Ͻ�ˮ���಻����",
		"������" : "�������Դ����������κ�һ��ǧ�",
		"������" : "��������Ӵ����ˡ�",
		"��ɽ��" : "��������Ӵ����ˡ�",
		"����" : "��λ�����������ɰ������˼�˵���㡣",
		"����ʯ" : "������ڱװ��Ϳ๦�ߣ��ĵð������Ρ�",
		"����" : "�ҼҰ���˾ͽ��ү�������ϵġ������족Ҳ��",
	]));

	setup();

 	carry_object("/clone/weapon/changjian")->wield();
}

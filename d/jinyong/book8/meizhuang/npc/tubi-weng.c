// tubi-weng.c
inherit NPC;
#include <ansi.h>;

void create()
{
        set_name("ͺ����", ({ "tubi weng", "weng" }));
        set("title", "÷ׯ��ׯ��");
        set("long",
                "������÷ׯ��λׯ�����е�����ͺ���̡�\n"
                "��һ���ɸɾ����İ�ɫ���ۡ�\n"
                "����������Ѯ����İ�С�����Ϲ��, һ����֪���Ǹ����׶�ŭ���ˡ�\n");
        set("gender", "����");
        set("age", 52);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 100000);
        set("max_jing", 100000);
        set("neili", 100000);
        set("max_neili", 100000);
        set("jiali", 50);
        set("combat_exp", 6000000);
        set("shen", 15000);
        set("score", 60000);
        
	set_skill("painting", 320);
	set_skill("force", 400);
	set_skill("wuzheng-xinfa", 400);
	set_skill("dodge", 400);
	set_skill("piaoyibu", 400);
	set_skill("parry", 400);
	set_skill("dagger", 400);
	set_skill("shigu-bifa", 400);
	set_skill("literate", 130);
	set_skill("jiangjun-zhang",400);
	set_skill("kuihua-xinfa", 400);
        map_skill("force", "wuzheng-xinfa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "shigu-bifa");
        map_skill("dagger", "shigu-bifa");
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        create_family("÷ׯ", 1, "ׯ��");

        setup();
        carry_object(__DIR__"obj/panguan-bi")->wield();
}

void unconcious()
{
	die();
}
void die()
{
        object who = this_object()->query_temp("last_damage_from");
	if(who) {
		message_vision("$N̾�������������ǳ���������ǰ�ˣ������ˣ����ˣ������е�����Ҳ���ٲ����ˡ�\n" NOR,this_object());
	}
	destruct(this_object());
}

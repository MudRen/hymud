// Npc: /kungfu/class/nanshaolin/fangtong.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("��ͨ", ({ "fang tong", "fang", "tong"}));
	set("long", "����һλ���Ʋ����ĵ�����ɮ�ˡ���������δ�ѣ�����ȴ����\n"
		"���ýݣ������ƺ�ѧ��һ���书��\n");
	set("nickname", "֪��ɮ");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
    set_max_encumbrance(100000000);   
    set("per", 20);
    set("str", 200);
	set("int", 20);
	set("con", 20);
	set("dex", 200);
	set("qi", 90000);
	set("jing", 90000);
	set("max_qi", 90000);
	set("max_jing", 90000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 0);
	set("combat_exp", 950000);
	set("score", 100);
	set_skill("hunyuan-yiqi", 160);
	set_skill("zhanzhuang-gong", 160);
	set_skill("shaolin-cuff", 160);
	set_skill("shaolin-leg", 160);
	set_skill("yiwei-dujiang", 160);
	set_skill("boluomi-hand", 160);
	set_skill("jingang-strike", 160);
	set_skill("wuxiang-finger", 160);
	set_skill("literate", 150);
	set_skill("buddhism", 150);
	set_skill("parry", 150);
	set_skill("force", 130);
	set_skill("yijinjing", 130);
	set_skill("dodge", 130);
	set_skill("shaolin-shenfa", 130);
	set_skill("cuff", 130);
	set_skill("hunyuan-yiqi", 130);
	set_skill("leg", 130);
	set_skill("zui-gun", 130);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "hunyuan-yiqi");
	map_skill("leg", "zui-gun");
	map_skill("parry", "hunyuan-yiqi");
	prepare_skill("cuff", "hunyuan-yiqi");
	prepare_skill("leg", "zui-gun");

	create_family("��������", 21, "����");

        set_temp("apply/defense", 200);
        set_temp("apply/damage", 100);
                set_temp("apply/armor", 900);
	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
}

int accept_object(object who, object ob,object me)
{
	mapping fam; 
	me=this_object();
	if (!wizardp(this_player()) && (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "��������"))
	{
		command("hehe "+who->query("id"));
		command("say ����Ҷ�����ʲô��ͼ����");
		return 0;
	}
	if(!who->query_temp("lunzhi"))
	{
		command("say ��������������ģ���ֵ����õ�����ʦ������");
		return 0;
	}
	if(ob->query("name")=="��ֵ��")
	{
		command( "say �ðɣ����Ȼ�д���ʦ�����ƣ�����������������һ�������ɡ�");
//		who->apply_condition("sl_lunzhi",random(5)+15);
		who->apply_condition("sl_lunzhi", 11);
		who->set_temp("lunzhied",1);
		return 1;
	}
	        call_out("destroying", 1, ob);
	return 1;
}
#include "fang.h";

void destroying(object obj)
{
        destruct(obj);
        return;
}
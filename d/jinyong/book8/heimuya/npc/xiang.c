// xiang.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "xiang wentian", "xiang"}));
	set("nickname", HIR "��������" NOR );
	set("gender", "����");
	set("title", "������̹�����ʹ");
	set("long", "������������̵Ĺ�����ʹ��Ϊ�˼�Ϊ��ˬ��\n");
	set("age", 45);
	set("shen_type", -1);
	
	set("str", 21);
	set("per", 28);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("chat_chance", 1);

	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 9000);
	set("max_jing", 9000);
	set("neili", 9500);
	set("max_neili", 9500);
	set("jiali", 350);
	
	set("combat_exp", 6500000);
	set("score", 0);
	
	set_skill("force", 210);
	set_skill("hunyuan-yiqi", 210);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 210);
	set_skill("finger", 210);
	set_skill("strike", 210);
	set_skill("hand", 210);
	set_skill("claw", 210);
	set_skill("parry", 210);
	set_skill("nianhua-zhi", 210);
	set_skill("sanhua-zhang", 210);
	set_skill("fengyun-shou", 210);
	set_skill("longzhua-gong", 210);
	set_skill("buddhism", 110);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 500);
	set_temp("apply/damage", 200);
	set_temp("apply/attack", 200);
	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
	//create_family("�������", 2, "������ʹ");
	
	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
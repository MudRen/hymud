// zhang.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������", ({ "zhang zhaozhong", "zhang", "zhaozhong"}) );
	set("title", "���־�����Ӫ����");
	set("nickname", HIR"�����й�"NOR);
	set("gender", "����");
	set("age", 43);
	set("long",
"�������˳ơ������й١�����Ŀ��࣬��һ�Զ̺��ӡ�����ʢ
�ԡ�����һǹ��Ī��һ�š�����ָ���ˡ������Թ�����»��Ͷ
��͢�����˰�����������Щ������������ֱ�ϡ�\n");
	set("combat_exp", 750000);
        set("shen_type", -1);
	set("attitude", "heroism");
        set("qi", 18000);
	set("max_qi", 18000);
	set("jing", 18000);
	set("max_jing", 18000);
	set("neili", 25000);
	set("max_neili", 25000);
	set("jiali", 100);
	set("combat_exp", 6000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 300);
	set_skill("force", 350);
	set_skill("taiji-shengong", 300);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 300);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 300);
	set_skill("juehu-shou", 300);
	set_skill("raozhi-roujian", 300);
	set_skill("wudang-mianzhang", 300);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 300);
	set_skill("shenmen-jian", 300);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
set("count",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);

        create_family("�䵱��", 13, "����");
	setup();

        carry_object(__DIR__"obj/green_sword")->wield();
        carry_object("/d/city/obj/tiejia")->wear();

	add_money("silver", 30);
}
void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;


who->set_temp("book941",1);
		message_vision("$N˵������������ ���Ѿ��������Ź��ؽ��ˣ����Ǿ͵��������ɡ�\n",this_object(),who);
		

		
		
	::die();

}                         
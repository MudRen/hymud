 // ashui.c
inherit NPC; 
#include <ansi.h>
void create()
{
        set_name("��ˮ", ({ "a shui","shui" }) );
        set("gender", "����" );
        set("age", 26);
        set("title","����"+HIR" ��Ѫ�̿�"NOR);
        set("long",
"һ��ƽ�����ˣ��Ƿ�Ҳ��һ����ƽ���Ĺ��£�\n" );
        set("chat_chance", 1);
        set("chat_msg", ({
            "��ˮ��Ȼ�������ڻ���ɽ�������滹��������\n",
            }) );
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set("per",100);
        set("str", 40);
        set("force",2000);
        set("max_neili",2000);
        set("force_factor",50);
	set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);

	set_skill("construction", 380);
	set_skill("painting", 380);


	        set_skill("songshan-sword", 380);
        set_skill("songshan-jian", 380);
        set_skill("songshan-qigong", 380);
        set_skill("dodge", 290);
        set_skill("zhongyuefeng", 380);
        set_skill("strike", 290);
        //set_skill("songyang-zhang", 380);
        set_skill("hanbing-zhenqi", 380);
        set_skill("parry", 290);
        set_skill("sword", 290);
        set_skill("songshan-jian", 380);
        //set_skill("songyang-zhang", 380);
        //set_skill("songyang-shou", 380);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 380);
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_skill("songshan-sword", 380);
	set_skill("songyang-strike", 380);
	set_skill("poyun-hand", 380);
	set_skill("hanbing-zhenqi", 380);
	set_skill("fuguanglueying", 380);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");

	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: command("haha") :),
//		(: command("unwield sword") :),
//		(: command("wield sword") :),
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "strike.junji" :),	
		(: perform_action, "hand.chanyun" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/loulan/obj/sword")->wield();
} 
/*void die()
{
        object ob;
   //command("cry");
        message_vision("\n$N����һ����ҧ���гݵ������Դ����氳����ģ�\n", this_object());
        message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
        //this_object()->move("/d/fy/church");
        //create();
        destruct(this_object());
}     
*/
// Npc: /u/zqb/tiezhang/npc/mayi.c
// Date: zqb 97/06/17

#include <ansi.h>

inherit NPC;

void create()
{
    set_name("���³���", ({
    "mayi zhanglao",
    "mayi",
    "zhanglao",
	}));
	set("long",
    "����һ����Լ��Ѯ�����ߣ���ͷ���������ް߰ס�\n"
    "�������̫��Ѩ�߸߹���΢�յ�˫Ŀ��ʱ�����������������ƺ���������\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");

	set("age", 60);
	set("shen_type", 1);
	set("str", 28);
	set("int", 23);
	set("con", 23);
	set("dex", 28);
	set("max_qi", 24000);
	set("max_jing", 23000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
	set_skill("unarmed",300);
	set_skill("hammer",380);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 180);
	set_skill("literate", 100);
	set_skill("axe", 380);
	set_skill("duanyun-fu", 350);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 350);
	set_skill("tongbi-zhang", 350);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
        set_temp("apply/attack", 200);

	setup();
	carry_object(__DIR__"obj/hammer");
	carry_object(__DIR__"obj/black-cloth")->wear();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("tiezhang ling", ob) 
        && ( (fam = ob->query("family")) && fam["family_name"] != "���ư�" ) 
        && (int)ob->query("combat_exp", 1) >= 10000 ) 
	{
		if( !ob->query_temp("warned") ) {
        command("say վס���㲻�����ư���ӣ������ڴ˾�������");
        command("say �㻹�������뿪�˵ذɣ���Ȼ�����Ҫ���㲻�����ˣ���");
        command("hehe");
			ob->set_temp("warned", 1);
		}
          else if( ob->query_temp("stay") < 3 ) ob->add_temp("stay", 1);
                else {
                	command("say ���ò��ͷ��ˣ����ҵ����ư�����Ұ������\n");
			remove_call_out("hiting_ob");
                     	call_out("hiting_ob", 1, ob);
		}
	}       

}
int hiting_ob(object ob)
{
	object me;
	me=this_object();
	ob->kill_ob(me);
        me->fight_ob(ob);
}

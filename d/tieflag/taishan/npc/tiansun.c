 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
//int give_hint();
string sysmsg;
void create()
{
        set_name(HIG"����"NOR, ({ "tian sun", "tiansun" }) ); 
        set("gender", "����");
        set("age", 40);
        set("long",
 "\n�����ǵ��񽭺��������ص���֯�����ڡ���ͷ�죬�������źܶ��˵����ˡ�\n");
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("str", 2000);
        set("cor", 30);
        set("int", 40);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
//                "��������㹰�˹��ֵ�������λӢ�ۣ�������������ĳ������ң���\n",
        }) );
        set("inquiry", ([
//                "����" : (: give_hint:),
//                "tianzong" : (: give_hint:) 
        ]));
	set("neili", 22400);
	set("max_neili", 22400);
	set("max_qi", 22000);
	set("max_jing", 21200);
	set("combat_exp", 8000000);
	set("shen_type", 1);

	set_skill("strike", 150);
	set_skill("kuaihuo-strike", 310);
	set_skill("sword", 350);
	set_skill("taishan-sword", 320);
	set_skill("shiba-pan", 320);
	set_skill("force", 150);
	set_skill("panshi-shengong", 350);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("fengshenjue", 310);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );        set_temp("apply/attack",100);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/damage",100); 
        set("title", "�޹�ɽׯ ��ׯ��");
        set("nickname", HIR"������˫"NOR);
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/mask")->wear();
        //create_organization("����",1,"а");
}
int accept_fight(object me)
{
        command("say �ߣ���û������й���");
        return 0;
}
  
// wujiang.c �佫
#include <ansi.h>
inherit NPC;


void create()
{
	set_name("�ܻ���", ({ "cao huachun", "cao" }));
//	set("nickname", "");
	set("long", 
        "ԭ�ǳ�͢�Ļ¹٣���������̰������������͢����ʱ�������ˡ�\n");set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);

  set("title", HIR"��ǧ��"NOR);
  	set("shen_type", 1);
	set("attitude", "peaceful");

	set("combat_exp", 2810000);
	set("shen_type", 1);

          set("qi", 44000);
    set("max_qi", 44000);
    set("jing", 41000);
    set("max_jing", 44000);
    set("neili", 68500);
    set("max_neili", 68500);
    set("jiali", 200);

    set("combat_exp", 24500000);
    set("score", 0);

    set_skill("cuff", 250);
    set_skill("strike", 250);
    set_skill("force", 380);             // �����ڹ�
    set_skill("finger", 250);            // ����ָ��
    set_skill("unarmed", 250);           // ����ȭ��
    set_skill("dodge", 380);             // ��������
    set_skill("parry", 380);             // �����м�
    set_skill("sword", 380);             // ��������
    set_skill("pixie-jian", 380);        // ��а����
    set_skill("changquan", 300);         // ̫�泤ȭ
    set_skill("literate", 100);          // ����ʶ��
    set_skill("kuihua-xinfa", 380);      // �����ķ�
    set_skill("kuihua-dafa", 380);      // ������
    set_skill("kuihua-feiying", 380);      // ������
   set_skill("tmzhang", 180);
        set_skill("staff", 180);
         set_skill("tmjian", 180);
         set_skill("tmdao", 180);
         set_skill("pmshenfa", 180);
          set_skill("cuff",180);
         set_skill("blade", 180);
         set_skill("tmdafa", 180);
set_skill("tmquan", 180);       
    map_skill("force", "kuihua-xinfa");
    map_skill("sword", "kuihua-dafa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "kuihua-feiying");
    map_skill("parry", "pixie-jian");


        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tonggui" :),
                (: perform_action, "sword.pi" :),
                	(: perform_action, "sword.yinrou" :),
                (: perform_action, "sword.po" :),
                (: perform_action, "sword.gui" :),
                (: perform_action, "parry.cimu" :),
                (: perform_action, "parry.huanying" :),
                (: perform_action, "parry.sanlianci" :),
                (: perform_action, "dodge.kuihuashenzhang" :),
                (: perform_action, "dodge.feiying" :),
                (: perform_action, "dodge.jue" :),
                (: perform_action, "unarmed.yuhuan" :),
                (: exert_function, "powerup" :),
                (: exert_function, "kuihuawudi" :),
                (: exert_function, "powerup" :),                
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2900);
        set_temp("apply/damage", 2100);
        set_temp("apply/attack", 200);
    setup();
    carry_object("/d/heimuya/npc/obj/qijue")->wield();
    carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
    
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

// dongjinkui.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����", ({ "dong jinkui", "dong" ,"jinkui"}));
	set("gender", "����");
	set("title", HIC"������̫��"NOR);
	set("age", 26);
	set("per", 20);
	set("long", "һ��׳˶���ӣ�ͦ��͹�ǣ�������Ϊ���ơ�\n");

set("qi", 14000);
    set("max_qi", 14000);
    set("jing", 14000);
    set("max_jing", 14000);
    set("neili", 28500);
    set("max_neili", 28500);
    set("jiali", 200);

    set("combat_exp", 24500000);
    set("score", 0);

    set_skill("cuff", 250);
    set_skill("strike", 250);
    set_skill("force", 380);             // �����ڹ�
    set_skill("finger", 250);            // ����ָ��
    set_skill("unarmed", 250);           // ����ȭ��
    set_skill("dodge", 280);             // ��������
    set_skill("parry", 280);             // �����м�
    set_skill("sword", 280);             // ��������
    set_skill("pixie-jian", 280);        // ��а����
    set_skill("changquan", 300);         // ̫�泤ȭ
    set_skill("literate", 100);          // ����ʶ��
    set_skill("kuihua-xinfa", 280);      // �����ķ�
    set_skill("kuihua-dafa", 280);      // ������
    set_skill("kuihua-feiying", 280);      // ������
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
	
	set_temp("apply/attack", 135);
	set_temp("apply/defense", 135);
	set_temp("apply/damage", 120);



	setup();
	add_money("silver", random(10));
	carry_object(__DIR__"obj/tjcloth")->wear();
}


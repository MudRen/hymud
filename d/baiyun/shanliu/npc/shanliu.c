 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
//int give_hint();
string sysmsg;
void create()
{
        set_name(WHT"������"NOR, ({ "mysterious man", "man" }) ); 
        set("gender", "����");
        set("age", 40);
        set("long",
 "\n����������ɽ����������û����֪��������ʵ��ݺ�������\n");
        set("attitude", "peaceful");
        set("quest_npc", 1);
        set("npc_difficulty", 10);
        set("str", 2000);
        set("cor", 30);
        set("int", 40);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );
        set("inquiry", ([
        ]));
        set("force", 4000);
        set("max_neili", 80000);
        set("force_factor", 500);
        set("atman",1000);
        set("max_atman",1000);
        set("combat_exp", 100000000);
        set_skill("unarmed", 500);
        set_skill("force", 500);
        set_skill("iron-cloth", 200);
        set_skill("dodge",500);
        set_skill("yiqiforce",100);
        map_skill("force","yiqiforce");
        map_skill("iron-cloth","yiqiforce");
        map_skill("unarmed","yiqiforce");
        set_temp("apply/attack",100);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/damage",100); 
        set("title", "ɽ�� ����");
        set("nickname", HIR"ƽ������"NOR);
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
	command("smile");
        command("say ��������æ�����в��㡣");
        return 0;
}

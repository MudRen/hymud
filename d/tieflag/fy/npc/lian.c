 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
int give_hint();
string sysmsg;
void create()
{
        set_name(HIG"�����"NOR, ({ "lian", "lian cheng bi", "chengbi" }) ); 
        set("gender", "����");
        set("age", 29);
        set("long",
"������������һ���е����䣬�޹�ɽׯ��������������Ľ�ľ������\n");
        set("attitude", "peaceful");
        set("str", 40);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������㹰�˹��ֵ�������λӢ�ۣ�������������ĳ������ң���\n",
        }) );

        set("neili", 4000);
        set("max_neili", 80000);
        set("force_factor", 40); 
        set("combat_exp", 10000000);
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set_skill("unarmed", 180);
        set_skill("force", 100);
        set_skill("iron-cloth", 100);
        set_temp("apply/attack",300);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
   set_temp("apply/damage",300); 
        set("title", "�¸�����");
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        command("say �������书���ã�����ĳ��Ӧ���㣬��ȭ�����飬��С���ˣ�");
        return 1;
}

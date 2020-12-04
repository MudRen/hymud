 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
int give_silk();
inherit NPC;
void create()
{
        set_name("��ʵ����", ({ "lao shi", "lao"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", 
"��ʵ�����������񲣬��������ģ����Ĺ���Ҳ����ˣ�
��ʵ���д�����˵�ѻ������Ե�������ʵ���У�\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set_skill("unarmed", 5+random(350));

        set_skill("dodge", 40);
        set_skill("force",4);

        set("neili",10);
        set("force_factor",2);
        set("max_neili",100);
        set("chat_chance", 5);
        set("chat_msg", ({
"��ʵ����̾��������淣�ң�����ȥ����ǧ��¥��\n",
"��ʵ���д��˴��Լ���ͷ���������˾�����ڿ�\n",
"��ʵ����������������������ü���������ֵĲ����ָ����ң�\n",
                (: random_move :),
        }) );
        set("inquiry", ([
                "�߲�˿�д�" : (: give_silk:),
                "silk" : (: give_silk:) 
        ]));
        
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
}
int give_silk()
{
if( (int)query("given") >= 7 )
{
command("say �����ˣ��������ˣ�����\n");
return 1;
}
command("say ��Ҳ������Բ֮ҹ��ȥ�����Ͻ�֮�۵Ŀ�����ս��\n");
command("say ���ҵÿ����㣬���㹻������\n");
if (this_player()->query_temp("marks/laoshi_win")) this_player()->delete_temp("marks/laoshi_win");
this_player()->set_temp("marks/laoshi",1);
return 1;
} 
void win_enemy(object loser)
{
command("say ��λ" + RANK_D->query_respect(loser)+ "���㻹������\n");
}
void lose_enemy( object winner)
{
object silk;
command("say ��λ" + RANK_D->query_respect(winner)+ "����Ĺ��򲻴�\n");
if (!winner->query_temp("marks/laoshi_win"))
{
silk = new(__DIR__"obj/silk");
silk->move(this_object());
        if(!winner->query("m_success/�߲�˿�д�"))
        {
                winner->set("m_success/�߲�˿�д�",1);
                winner->add("score",100); 
        }
command("give silk to " + winner->query("id"));
add("given",1);
winner->set_temp("marks/laoshi_win",1);
}
} 
int accept_fight(object me)
{
        if(me->query_temp("marks/laoshi"))
        {
        command("say �ã���Ӯ���ң���˿��������ģ�\n");
        me->delete_temp("marks/laoshi");
        return 1;
   }
        else
        {
        command("say �����ӷ�ƶɮ�书��΢��ʩ����Ҫ��������Ц��\n");
        return 0;
        }
}
void reset()
{
delete("given");
}      

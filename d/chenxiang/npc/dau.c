 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int tell_him();
void create()
{
        set_name("��Ա���Ů��", ({ "jianu" }) );
        set("gender", "Ů��" );
        set("age", 15);
        set("combat_exp", 5);
        set("attitude", "friendly");
        set("per",30);
        set("chat_chance", 3);
        set("chat_msg", ({
                "��Ա���Ů���ʵ�������˭ѽ��\n",
                "��Ա���Ů���������ǲ����ҵ��ĺ����ѣ�\n",
        }) );
        set("inquiry", ([
                "��Ա��" : (: tell_him :),
                "jia" : (: tell_him:),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int tell_him()
{
 object me;
 me = this_player();
 if(me->query_temp("marks/cured_jia")) {
 tell_object(me,"��Ů�����ҵ����Ǹ���Ϊ��������ܱ������ˣ�����������й����
�Ļ�����������ˣ���һ������취ɱ����ġ�\n");
  me->set_temp("marks/asked_jianu",1);
 } else  
 tell_object(me,"��Ů���������ҵ�ѽ���⻹���ʣ�\n"); 
return 1; 
}      

 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("��ҩ���ϰ�", ({ "medman" }) );
        set("gender", "����" );
        set("age", 75);
        set("long",
                "
һ����æ�ò��ɿ�������ҩ���ϰ壬������������
\n");
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("per",1);
        set("inquiry", ([
                "���鲹Ѫ����" : "�����Ҫ�򣺱��Σ���ɽ�����Σ���ӣ��͵��飮\n",
                "soup" : "�����Ҫ�򣺱��Σ���ɽ�����Σ���ӣ��͵��飮\n",
        ])); 
        setup();
        set_temp("apply/damage",300);
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object me, object obj)
{
 if((int)me->query("combat_exp") < 500000) return 0;
 if((string)obj->query("marks") == "special_coin")
 {
  message_vision("$N����$nһ�ۣ�ָ��һ��С��¯��\n",this_object(),me);
  message_vision("$N��ԥ��һ�£������ϵ�һ��Ǯ����С��¯�С�\n",me);
  message_vision("ͭǮ�ϵ��Ѻ���ð��һ�����̣�������ͭǮȾ�ɱ��̣�\n",me);
  obj->set("marks","special_green_coin");
  obj->set("long","����һö���̵�ͭǮ��ͭǮ����һ��ǳǳ���Ѻۡ�\n");
  return 0;
 }
 return 0;
}   

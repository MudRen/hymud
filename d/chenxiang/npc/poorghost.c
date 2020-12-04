 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int tell_him();
void create()
{
    set_name("�Ȼ۶�", ({ "gu huier", "huier" }) );
    set("gender", "Ů��" );
    set("age", 24);
    set("attitude","friendly");
    set("force_factor", 20);
    set("long", "\n");
    set("combat_exp", 100);
    set("inquiry", ([
        "��������" : (: tell_him :),
        "sierfuhuo" : (: tell_him:),
        ]));
    setup();
    carry_object("/clone/misc/cloth")->wear();
}
int is_ghost() { return 1; }  
void init()
{
    object ob;
    ::init();
    if( interactive(ob=this_player()) && ob->visible(this_object())
        && !ob->query_temp("marks/huier"))
    {
        call_out("greeting", 1, ob);
    }
}
void greeting(object ob)
{
    tell_object(ob,"�Ȼ۶���������Ұɣ�������һ�����Ͼͳ�����\n");
    tell_object(ob,"��֪��֪������ȥ�ľ�ү�ƹ�����ĳ��������и�ӡ�������Ʒ����\n"); 
    ob->set_temp("marks/huier",1);
}  
int tell_him()
{
    object me;
    me =this_player();
    if(me->query_temp("marks/qingbo") &&
       me->query_temp("marks/yuanji") &&
       me->query_temp("marks/jiuye")) {
        tell_object(me,"������ʶ����ˣ���˵��һ��ҩ����yaofang��������ҩ����ȥ����
���������ǹ������컹�ܸ��\n");
        me->set_temp("marks/yaofang",1);
        return 1;
    }
    return 0;
}  
int accept_object(object me, object obj)
{
    if(obj->query("huier")) {
        command("say ���лл���ˣ�����ҿ����Ʒ�����ˣ�\n");
        me->set_temp("marks/jiuye",1);
        return 1;
    }
    return 0;
}    

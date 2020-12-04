 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("�ϰ���", ({ "boss" }) );
        set("gender", "Ů��" );
        set("age", 52);
        set("long",
                "�ϰ����Ƴ����·������������·����ι̶��Ҳ��ѿ���\n");
        set("combat_exp", 50);
        set("str",20);
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
 //       add_action("do_bu","bu");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "�ϰ���Ц������λ" + RANK_D->query_respect(ob)
                                + "�������������������Ҫ��һ���ˡ�\n");
                        break;
                case 1:
                        say( "�ϰ���˵������λ" + RANK_D->query_respect(ob)
                                + "��������������˿����ˣ�����һ�°ɡ�\n");
                        break;
   }
} 

 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
#include <ansi.h>
inherit NPC;
object ob; 
void create()
{
        set_name("������", ({ "furen" }) );
        set("gender", "����" );
        set("title", HIR "����ʦ"NOR);
        set("age", 52);
        set("long",
                "�����˲����ļҵ�̫̫�����������幬��һ���շ������˵��ϵ�ʿ��\n�˵������������£���������˼�����\n");
        set("combat_exp", 50000);
    set("str",30);
        set("attitude", "friendly");
        set("busy", 0);
        setup();
        add_money("gold", random(2));
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{       
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
 //       add_action("do_ji","ji");
//        add_action("do_answer", "answer");
        //if (!objectp(environment(this_object())->query("processing"))
        //      environment(this_object())->set("processing", ob);
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (present("hell sword", ob)) {
                if (ob->query("����A") || ob->query("����B")){
                   if(ob->query("stone_mark/pstone")){
                                message_vision("\n$N΢��˫�ۿ��˿�$n����ڤ���齣���������ε�����ڤ���齣����ֻ��һ�ѣ���һ�Ѷ�Ϊ��Ʒ��\n",
                                                this_object(), ob);
                                return;
                        }
                        message_vision(HIY"\n$N������͸�����еĹ⣬������ڤ���齣���૵�˵�����������ǧ������\n"NOR, this_object());
                        message_vision(HIY"����ڤ�Ͼ����ɵİ�����ϧұ��֮�˲����䷨�������˵ظ�֮�䡣��\n"NOR, this_object());
                        message_vision("\n$N˵�������" + RANK_D->query_respect(ob) 
+ "Ը���԰ٽ��������ҿ��԰���ڤ�Ͼ�������ԭ����\n" +
"���������򡡣���󣯣�� ��\n", this_object()); 
                        ob->set_temp("furen_yes_no", 1);
                } else {        
                        message_vision(YEL"$N���۹�ɨ��$n����ڤ���齣���۹�������ĥ��͸��\n"NOR, this_object(), ob);
                }
        } else {
                switch( random(5) ) {
                        case 0:
                                say( "������Ц������λ" + RANK_D->query_respect(ob)
                                        + "����ı��п���������ҪѪ��һ���ˡ�\n");
                                break;
                        case 1:
                                say( "������˵������λ" + RANK_D->query_respect(ob)
                                        + "����ı���ɱ�����㣬��Ѫ��һ�±��аɡ�\n");
                                break;
                }
        }
}

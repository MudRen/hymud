 // waiter.c
inherit NPC;

#include <ansi.h>
void create()
{
        set_name("����", ({ "huagu" }) );
        set("gender", "Ů��" );
        set("age", 31);
        set("title", HIM "��ĵ��"NOR);
        set("long",
                "��λ�ϰ�������¶�������Ц�ݡ�\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("per",30);

        set_skill("unarmed",5);
        set_skill("dodge",5);
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
        add_action("do_vendor_list", "list");
        add_action("assign_delivery","delivery");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
message_vision("$NЦ��˵�����ղ������Ļ����ϣ���ɡ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$NЦ�����˵������λ"+RANK_D->query_respect(ob)+
"Ҫ��ʲô������\n",this_object(),ob);
                        break;
        }
} 


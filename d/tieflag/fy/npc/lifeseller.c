 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("Ѧ����", ({ "xue" }) );
        set("gender", "����" );
        set("age", 69);
        set("long",
                "��λ�������ð׶���ٵ�˫�۶�����\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",200);
        set_skill("dodge",200);
                set("vendor_goods", ({
                __DIR__"obj/baozi1",
                __DIR__"obj/baozi2",
                __DIR__"obj/baozi3",
                __DIR__"obj/baozi4",
                "/d/xinjiang/npc/obj/baozi", 
        }));
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
        add_action("do_buy", "buy");add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
message_vision("$N�ð׶���ٵ��۾�����$nһ�ۣ�\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N���˴��Լ����ӱ�˵������λ"+RANK_D->query_respect(ob)+
"Ҫ��ʲô��\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N�ߵ�������ӻ����򣮣�����\n",this_object());
        }
}  
int accept_object(object who, object ob)
{
        int val;
        object paper; 
        val = ob->value();
        if( !val )
                return 0;
        else 
                if( val >= 2000) {
                paper = new(__DIR__"obj/baozhizhi");
                if( paper) {
                        paper->set("targetprice", val);
                        paper->move(who);
                            }
        }
        say( "Ѧ����˵������л��λ" + RANK_D->query_respect(who) + "��������û�õ������ˣ�\n"); 
        return 1;
} 

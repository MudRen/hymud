 inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("��ǧ��", ({ "duqianli" }) );
        set("gender", "����" );
        set("age", 91);
        set("title", CYN "�Ÿ߰˶�"NOR);
        set("long",
                "��λ�ϰ岻���Ÿ߰˶������һ��ǵ����̫�ӵ���ʦ��\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ({
                __DIR__"obj/book",
                __DIR__"obj/book3",
                __DIR__"obj/book4",
                __DIR__"obj/book5",
                __DIR__"obj/book6",
                __DIR__"obj/book7",
                __DIR__"obj/book8",
        }));
        set_skill("unarmed",50);
        set_skill("dodge",50);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
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
message_vision("$Nҡͷ���Եص���������ʱ���������������������Ӫ��·�࣮����\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����$nһ�ۣ��ͺߵ����ᷢΪ���ޣ����������ɡ������ڽ�Ϧ������\n",this_object(),ob);
                        break;
        }
} 


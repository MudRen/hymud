 inherit NPC;
inherit F_VENDOR; 
#include <ansi.h> 
int show_me(); 
void create()
{
        set_name("����", ({ "pusheng" }) );
        set("gender", "����" );
        set("age", 31);
        set("title", GRN "������"NOR);
        set("long",
                "��λ�������ϰ��书��ҽ����տ����������������\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("per",30);
        
        set("inquiry", ([
                "����" :        (: show_me :),
                "�ձ����ʽ" :  (: show_me :),
                "ҩ��" :        "��ÿ�쿪��ҩ���ɰ���ǧ�����ʵ�����һ�ţ�\n",
                "������" :      (: show_me :),
                "ҩ����" :      "��ÿ�쿪��ҩ���ɰ���ǧ�����ʵ�����һ�ţ�\n",
        ]));
        
        
        set("vendor_goods", ({
                __DIR__"obj/sendrug",
                __DIR__"obj/keedrug",
                __DIR__"obj/gindrug", 
        }));
        set_skill("unarmed",50);
        set_skill("dodge",150);
        set_skill("changquan",150);
        map_skill("unarmed", "changquan");
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
        switch( random(20) ) {
                case 0:
message_vision("$N����$nһ�ۣ�����˵��������Ƽ��ݣ���ˮ���գ��Ƿ񣮣������ȣ�\n",this_object(),ob);
                        break;
        }
}  
int show_me() {
        command("say Ŷ�����ʵ���������ǰ�����Ǹ��հ�ʽ��ҩ���ɣ�������ʮ�ֺ�����ֻ������ز��С�");
        command("say ������һ���˲����������㣬���ǽ���Ϊ�������㡱��");
        return 1;
} 

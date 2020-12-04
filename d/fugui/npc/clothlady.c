
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int tell_him();
void create()
{
        set_name("������", ({ "ji lingyan", "ji" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("title",WHT "������˫"NOR);
        set("long",
"���������羵�������볤�������裬һ�Ų԰׵������Լ�һ˫����\n����ã���۾�������˫���������֣���������������˫�֣�����\n�˷��Ƴ����������·���\n");
        set("combat_exp", 50000);
    set("str", 20);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set("inquiry", ([
                "Ǯ��" : (: tell_him :),
                 ])); 
	set("vendor_goods", ({
                __DIR__"obj/m_cloth1",
                __DIR__"obj/g_gloves",
                __DIR__"obj/m_cloth2",
                __DIR__"obj/m_cloth3",
                __DIR__"obj/m_cloth4",
                __DIR__"obj/m_boots1",
                __DIR__"obj/m_boots2",
                __DIR__"obj/w_skirt1",
                __DIR__"obj/w_skirt2",
                __DIR__"obj/w_skirt3",
                __DIR__"obj/w_skirt4",
                __DIR__"obj/w_girth1",
                __DIR__"obj/w_girth2",
	}));
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) 
        {
                case 0:
                        say( " ������Źֵ�Ц��Ц����λ"
                                + RANK_D->query_respect(ob)
                                + "������û�ж���Ǯ���� \n");
                        break;
                case 1:
                        say( " ������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "��������Щ�·����ֹ�����������˫�ģ������� \n");
                        break;
                                case 2:
                        say ( " ������Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "������Ķ����������������⡣���� \n");
                       break;
        }
} 
                                  
int tell_him()
{
    object me;
    me =this_player();
        
    tell_object(me,"�����������գ��գ�۾�������ǰ������ǰ���ɽ����񵽸��ľ��µ�Ǯ���������Ҫ�����������������ɡ���\n");
               
    return 1;
} 

int accept_object(object who, object ob)
{
	    object obj;
                if( (int)ob->value() >= 3000000 ) {
                        say( name()+"���˵�����������Ȼ��С�ĵؽ�"+ob->name()+"���뻳�ڡ�\n");
                    message_vision(NOR"$N���������ҳ�һ��Ǯ����$n��\n\n"NOR, this_object(),this_player());

                    //    say ("\n$N���������ҳ�һ��Ǯ����$n��\n",this_object(),this_player());�
                    obj = new(__DIR__"obj/notecase");
                    obj->move(this_player());


                        return 1;
                } else {
                        command("say ��ЩǮ����������������������·��ء�");
                        return 0;
                }
        return 0;
}  
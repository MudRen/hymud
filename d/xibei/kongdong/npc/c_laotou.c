inherit NPC;


void create()
{
        set_name("������ͷ", ({ "tiaocai laotou","laotou" }) );
        set("gender", "����" );
        set("age",60);
        set("inquiry", ([
                "·" : "һֱ����ʯ���ϵ���ͷ�����ˡ�\n",
                        ]) );
        set("social_exp",2000);
        set("combat_exp",10000);
        set("force",200);
        set("max_force",200);
        set("force_factor",10);

        setup();
        carry_object(__DIR__"obj/linen")->wear();
}

void init()
{
        object ob;
        ::init();
        if(interactive(ob=this_player()) && !is_fighting()){
            remove_call_out("greeting");
            call_out("greeting",1,ob);
            }
}

void greeting(object ob)
{
        if(!ob||!present(ob,environment(this_object())))return;
        say("������ͷ����֣�����µ�˵��"+RANK_D->query_respect(ob)
            +"����˵�����ɽ�Ͽ�������ѽ��\n");
        }

 //


inherit NPC;
inherit F_DEALER;

int bamboo();
void create()
{
        set_name("С����", ({ "danfan", "dan fan" }) );
        set("gender", "����" );
        set("age", 25);
        set("long",
                "һ�����ŵ��ӣ�������飩����������С�������ӷ��������Եĵ�����ͷ����
��ɫ��Ʒ�������ڶ�������ʳƷ�����Ǯ��Ȼ�Թ���Щ�����Ƕ���������\n");
        set("combat_exp", 5);
        set("chat_chance", 1);
        set("chat_msg", ({
                "С����ҡ�������еĲ��˹ġ�\n",
        }) );
                set("inquiry", ([
                        "��Ͳ" : (: bamboo :),
                        "zhutong" : (: bamboo :),
                ]));
        set("attitude", "friendly");
	set("vendor_goods", ({
                __DIR__"obj/dumpling",
                        __DIR__"obj/chicken_leg",
	                        __DIR__"obj/yanzhi",
	}));
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
void init()
{
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
} 
int bamboo(){
        object me, ob;
        
        me = this_player();
        if(me->query("marks/����") && environment(this_object())->query("item_bamboo")){
           message_vision("$N��$n��������Ȼ��λ" + RANK_D->query_respect(me) + "ϲ�������͸���ѡ���\n",
                                this_object(), me);
                message_vision("$N��������һ��С��Ͳ�ݸ�$n��\n", this_object(), me);
                ob = new(__DIR__"obj/bamboo_cont");
                if(objectp(ob)){
                        ob->move(me);
                }
                environment(this_object())->set("item_bamboo", 0);
        } else {
                message_vision("$Ņͷ����$n��������λ�͹ٻ��ǿ��������Ʒ�ɡ���\n", this_object(),me);
        }
        return 1;
}   

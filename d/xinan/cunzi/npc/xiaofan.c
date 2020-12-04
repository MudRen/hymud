
inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("С��", ({ "xiao fan","fan" }) );
        set("gender", "����" );
        set("age", 35);
        set("long",
          "���Ǹ��ٽ�ɽ�ϵ�С�������������ӽ���Щɽ����������Ʒ��\n"
        );
        set("combat_exp", 4000);

        set("chat_chance", 1);
        set("chat_msg",({
"�������и���ҩ�ģ��������ʵġ���һ���\n",
"����������Ҫ�ĸ���������Ʒȫ�У����ʲô?\n",
        }) );
        set("talk_limit",([
            "social_exp" : 200,
            "age"        : 15,
        ]));
        set("talk_msg",({
"ɽ����꣬����������㽪�����ǰ��ɽ�������ȥ��.\n",
"��������ܲ�һ������Դ���.\n",
        }));
	set("vendor_goods", ({
		 __DIR__ "obj/jiang",
		__DIR__ "obj/chaidao",
		__DIR__ "obj/lajiao",
		__DIR__ "obj/gouqi",
		__DIR__ "obj/wine",
		__DIR__ "obj/yougao",
		__DIR__ "obj/bag",  
		"/d/city/npc/obj/baozi",								
	}));


        setup();
        carry_object(__DIR__"obj/cloth1")->wear();
}
void init()
{
        ::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


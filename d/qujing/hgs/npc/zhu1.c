
inherit NPC;
inherit F_DEALER;
void create()
{
       set_name("���ϴ�", ({"bamboo man", "man"}));
       set("long", "���ϴ��С���񣬿�����ı����
�������˶��������ϴ󣬰��������������ˡ�\n");
       set("gender", "����");
        set("combat_exp", 5000);
	set("per", 18);
       set("age", 56);
       set("attitude", "peaceful");
	set("max_qi", 400);
	set("max_jing", 400);
       set("shen_type", 1);
       set_skill("unarmed", 15);
	set_skill("dodge", 15);
       set("vendor_goods", ({
               "/d/obj/misc/kuang",
        }));

        setup();
       add_money("silver", 1);
        carry_object("/d/obj/cloth/linen")->wear();
}
int accept_fight(object me)
{	me=this_player();
	if((int)this_player()->query("combat_exp") < 15000) {
	this_object()->set("combat_exp", (int)this_player()->query("combat_exp")+500);
	}
        return 1;
}

void init()
{
        add_action("do_buy", "buy");add_action("do_list", "list");
}


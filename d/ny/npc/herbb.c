
// herbalist.c
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;


void create()
{
    set_name("���ƹ�", ({ "herbalist" }) );
    set("title", "�ּ�����");
        set("gender", "����" );
        set("age", 54);
        set("long",
        "���ƹ����⸽���൱�����Ĵ����ˣ�����ʩ���ҩ��������ҩǮ������\n"
                "����������ҽ��Ҳ��������ʱ��������ɽ���µ����Ǻ���ѧҽ��һ��\n"
                "���˺�С��ֱ��������ҩ�Ա�ҽ�����顣\n" );
        set("combat_exp", 130000);
        set("attitude", "friendly");
        set("inquiry", ([

                "�ⶾ": 
"��Ӵ���㲻˵�ҵ����ˣ���������һ��ȥ�����Ǵ�ʦ���......\n",
        ]) );

        set_skill("literate", 70);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/yangjing",
		"/clone/misc/wuchangdan",
		"/clone/misc/zhujingchan",
		"/clone/misc/dust",
		"/clone/misc/yaodan",
                "/clone/misc/neilidan",
		"/d/shenlong/obj/xionghuang",
	}));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 10);
}
void init()
{
        object ob;

        ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");


}
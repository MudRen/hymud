
//tea_vendor.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����ˮ�Ĵ���", ({ "tea vendor", "vendor" }) );
        set("gender", "Ů��" );
        set("age", 47);
        set("per", 18);
//        set("where","south");
        set("long", "�������Ĵ������΢΢һЦ��˵�����Լ��ֵĲ裬��һ���ɣ�\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");

//        set("chat_chance", );
        set("chat_msg", ({
                "����ˮ�Ĵ���ߺ�ȵ�����ˮ���������ɣ�\n",
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();

}




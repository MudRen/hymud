
// blacksmith.c ����ʦ��
#include <ansi.h>

inherit NPC;
inherit F_VENDOR;



void create()
{
            set_name("����", ({ "blacksmith" }) );
            set("long","�����õġ������ĵ��������ˡ���ô�;����������ɡ�\n");

                set("age", 14);
                set("attitude", "friendly");

                set("max_gin", 2000);
                set("max_kee", 3000);
                set("max_sen", 1000);

                set("str", 33);
                set("cor", 40);
                set("spi", 40);
                set("int", 60);
        set("vendor_goods",({
                   "/d/city/obj/changjian",
                   "/d/city/obj/hammer",
                   "/d/city2/obj/tudao",
		"/d/city/obj/dagger",
                  "/d/xingxiu/obj/tiegun",
                  "/d/city/obj/gangdao",
        }));
        set("force",800);
        set("max_force",800);

                set("combat_exp", 1000);
          
                setup();
                carry_object("/clone/misc/cloth");
                       
}


void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

//guan5.c  ����ʹ��.
//date:1997.8.27
//by dan      

#include <ansi.h>

inherit NPC;

void create()
{
    set_name(RED"����ʹ��"NOR, ({ "shi jie" }) );
    set("gender", "����" );
    set("combat_exp", 100000);
    set("max_qi", 400);
    set("max_sen", 300);
     set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 180+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
        }) );

    set("attitude", "friendly");
    set("env/attack", 78);
    set("chat_chance", 50);
    set("chat_msg", ({
    "ʹ�ںܲ��޵�˵:������̫�����ˣ������������Ӵ�����Ҳû�У��������Ҳ����ʹ���\n",
    }));
    setup();
    carry_object(__DIR__"obj/cloth3")->wear();
}








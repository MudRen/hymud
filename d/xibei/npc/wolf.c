#include <ansi.h>
inherit NPC;
void create()
{
        set_name(BLU "����" NOR, ({ "chai lang", "lang","wolf" }) );
        set("race", "Ұ��");
        set("age", 8);
        set("long", "һֻ�����˵Ĳ��ǣ����������ĵĶ�����......\n");
        if(random(2) == 1)
           {  set("attitude","aggressive");}
        set("str", 30);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 3000);

        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
             "������һ�������ĵ��۾�������......",
        }) );
        
        set("chat_msg_combat", ({
                RED "����ͻȻ��ͷ���У��ƺ����ٻ�ͬ��......\n" NOR,
        }) );
        setup();
}


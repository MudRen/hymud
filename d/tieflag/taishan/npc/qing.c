#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "qing qing" }) );
        set("gender", "Ů��");
        set("age",25);
        set("env/wimpy",90);
        set("combat_exp", 1000000);
        set("long",
                "һ����ĺ�������Ů�ˣ���������ɫ�����ѣ����þ���ͼ���е���Ů��\n"
        );
        set_skill("move",300);
        set_skill("dodge", 50);
        set_skill("unarmed",30);
        set("chat_chance", 15);
        set("chat_msg", ({
        (: random_move :),
        }) );
        setup();
}
void init()
{
        if(userp(this_player()) && !random(3))
        {
                message_vision("$N�����������ֱ��������ģ�$n�����������ˣ���������������ˣ�\n",
                this_object(),this_player());
                this_player()->apply_condition("unknown",random(10)+5);
        } 
}   

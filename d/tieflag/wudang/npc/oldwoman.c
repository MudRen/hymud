#include <ansi.h>
inherit NPC; 
int send_fan(); 
void create()
{
        set_name("�ϸ���", ({ "old woman", "woman" }) );
        set("gender", "Ů��");
        set("age", 49);
        set("long",
                "�ϸ�������æ��������\n"
        );
        set("attitude", "peaceful");
        set("combat_exp", 10);
        set("env/wimpy", 100);
        set("inquiry", ([
                "��" : (: send_fan :),
                "����" : (: send_fan :),
                "�ϰ�" : "������ׯ�ҵ���ɻ���������˳ԡ�"
        ]) );
        setup();
    carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/basket2");
} 
int send_fan()
{
        object bag, me, rice, vege, chop; 
        me = this_player();
        say("�ϸ���˵�������������з��ˣ���λ" + RANK_D->query_respect(me) +
                "����һЩ�ɡ�\n");
        if( bag = present("basket", this_object())) {
                say("�ϸ���ͣ��һ����˵��������λ" + RANK_D->query_respect(me) +
                        "����������ϰ���ȥ����\n");
                rice = new(__DIR__"obj/rice");
                vege = new(__DIR__"obj/vege");
                chop = new(__DIR__"obj/chopstick");
                rice->move(bag);
                vege->move(bag);
                chop->move(bag);
                bag->move(me);
                message_vision(HIY "$N��һ�����½�����$n��ת����ȥ�����ˡ�\n"NOR, this_object(), me );
   }
        return 1;
}      

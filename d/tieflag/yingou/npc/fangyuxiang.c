 // garrison.c
#include <ansi.h> 
inherit NPC;
#define LOWER_LIMIT 2000
#define DUMP_PLACE  AREA_LAOWU"road0.c"
void create()
{
        set_name("������", ({ "xiang", "fangyuxiang" }) );
        set("long",
"��λ�����������ӷ���ɵ�����\n");
        set("attitude", "heroism");
        set("title", HIW "������"NOR);
        set("str", 20+random(10));
        set("cor", 26);
        set("gender", "Ů��");
        set("cps", 25);
        set("per", 30);
        set("age",16);
        set("combat_exp", 100000); 
        set_skill("unarmed", 70+random(100));
        set_skill("sword", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100); 
        setup(); 
        carry_object(__DIR__"obj/goldcloth")->wear();
} 
int accept_object(object me, object obj)
{
        object real;
        if( (string) obj->query("name") == "��ɲ��")
        {
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) +
"��������Ҵ�æ��������㣮");
        me->set("marks/����˪",0);
        real = new(__DIR__"obj/realjade");
        if(!me->query("m_success/��ɲ��"))
        {
                me->set("m_success/��ɲ��",1);
                me->add("score",300); 
        }
        if( real )
        real->move(me); 
        return 1;
        }
        return 0;
}        

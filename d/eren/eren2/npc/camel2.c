 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("�������", ({ "female camel","camel" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 3);
        set("long", "һƥ��Į�г����ĵ������գ����ں���ЪϢ��\n");
        set("max_qi", 5000);
        set("max_jing", 6000);
        set("max_jing", 5000);
        set("int",40);
        set("cor",80);
        set("str",50);
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "hoof"}) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
                "�����ս�ͷ�������յ������˼��£������ܵ����ӡ�\n",
        }) );
        set("combat_exp", 2500000);
        set_temp("apply/attack", 300);
        set_temp("apply/armor", 100);
        set_temp("apply/dodge",300);
        set_temp("apply/damage",200);
        setup();
        carry_object(__DIR__"obj/an")->wear();
}  
void    die_next(){
        object ob=this_object();
        call_out("die_next_2",6,ob);
        
} 
void    die_next_2(object ob) {
        if (objectp(ob) && ob)
                message_vision(HIR"\n����ǰϥ���£�������ҵ�˻�������ۿ����ƺ��������¡���\n"NOR,ob);
        die();
}

 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("��������", ({ "male camel","camel" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 3);
        set("long", "һƥ��Į�г����ĵ������գ����ں���ЪϢ��\n");
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("max_jing", 3000);
        set("int",40);
        set("cor",80);
        set("str",50);
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "hoof"}) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
                "���յ���ͷȥ���˼�����ݣ�ת�״������㼸�ۣ�������Ȥ��\n",
        }) );
        set("combat_exp", 2000000);
        set_temp("apply/attack", 300);
        set_temp("apply/armor", 100);
        set_temp("apply/dodge",300);
        set_temp("apply/damage",200);
        setup();
        carry_object(__DIR__"obj/an")->wear();
}  
void die(){
        object spouse;
        
        if (spouse=present("female camel",environment(this_object())))
        if (!userp(spouse)) {
                spouse->die();
        }
        ::die();
} 

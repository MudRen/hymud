#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("������", ({ "jin wuwang","jin" }) );
        set("gender", "����" );
        set("long",
"һϮ���£����ޱ��飬�����ɽһ�㡣��Ŀ��ת��֮�䣬�������˵����ϡ�\n�˿����������ʹ֮��ʹ��רΪ������Ѽ����ڲƱ���\n"
                );
        create_family("�����", 1, "��ʹ");
        set("attitude", "peaceful");
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
//                    (:perform_action,"blade.shiwanshenmo":),
                      (:perform_action,"dodge.huanyinqianchong":),
        }));
        set("age", 34);
//        set("str", 100);
        set("cps", 40);
        set("int", 10);
        set("per", 4);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 1000000);
/*        set("force", 5000);
        set("max_force", 6000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("max_kee", 4000);
        set("max_gin", 2000);
        set("max_sen", 2000);  
        set("force_factor", 80);  */
        set_temp("apply/armor",50);
        set_temp("apply/damage",50); 
        set("chat_chance", 1);
        set("chat_msg", ({
                "������˫Ŀ΢�أ��ݷ���ɮ�붨��һ��������\n",
                }) ); 
        set_skill("unarmed", 160);
        set_skill("blade", 160);
        set_skill("bat-blade", 130);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("move", 200);
        set_skill("meng-steps", 150);
        set_skill("nine-moon-claw", 140);
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup(); 
//      carry_object("/clone/weapon/gangdao")->wield();
        carry_object(__DIR__"obj/foxcloth")->wear();
} 
int accept_object(object who, object obj)
{       
        if( (int) obj->value() >= 100 * 10000)
        {
                message_vision("$N���������$n���˵�ͷ��\n",this_object(),this_player());
                who->set_temp("marks/give_jin_gold",1);
                return 1;
        }
        else
        {
                message_vision("$N������ү��ϲ�£�����̫��Ͳ��س������������ˡ�\n",this_object());
                return 0;
        }
}  

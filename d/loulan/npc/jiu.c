#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("����", ({ "han ling","han" }) );
        set("gender", "����" );
        set("long",
"������ʮ���£�������ɫ��ϸüС�ۣ����ż���ɽ����ӣ����Ű��²���\n�ĺ�Ƥ�����˿����������ʹ֮��ʹ��רΪ����Ѱ�������ơ�\n"
                );
        create_family("�����", 1, "��ʹ");
        set("attitude", "peaceful");
        set("class","bat");
        set("reward_npc", 1);
        set("difficulty", 2);
        
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                (:perform_action,"dodge.huanyinqianchong":),
        }));
        
        set("age", 65);
        set("cps", 40);
        set("int", 10);
        set("per", 4);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 1200000);
        set("force", 1000);
        set("max_force", 1000);
        set_temp("apply/armor",100);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "���������ۻ��׵�ɽ����ӣ�����̾�˿�����\n",
                "����üͷ΢�壬̾������������ү����֮ǰ��������⡾��ȸ����������
��֪����ν�����",
                }) );
        set("inquiry", ([
                "��ȸ����" : "��׹������ǡ���������������˵�⡾��ȸ����������Ҫ������
�����Ƶ�����ɣ�ʲô���ų��ա������Ǿơ�������Ҷ�ࡻ����Ů���졻��
�������ơ��������ϴ����������ơ������һʱȥ���Ұ��� \n",
                "wine" : "��׹������ǡ���������������˵�⡾��ȸ����������Ҫ������
�����Ƶ�����ɣ�ʲô���ų��ա������Ǿơ�������Ҷ�ࡻ����Ů���졻��
�������ơ��������ϴ����������ơ������һʱȥ���Ұ��� \n",
        ]) );
        
        set_skill("unarmed", 140);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("move", 120);
        set_skill("meng-steps", 120);
        set_skill("nine-moon-claw", 120);
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup(); 
        carry_object(__DIR__"obj/foxcloth")->wear();
} 
int accept_object(object who, object ob)
{       
        if (ob->query("name")==HIC"����ȸ������"NOR && ob->query("liquid/name")=="��ȸ����")
        {
                if (ob->query("liquid/remaining") > 95)
                {
                        message_vision("$N���׵�üͷ����һ����Ц����������������лл$n,��ү����\n��������Ͳ���������ߡ�\n",this_object(),this_player());
                        who->set_temp("marks/give_han_wine",1);
                }
                else
                {
                        message_vision("$N���׵�üͷ��������Ц����������������ǡ���ȸ������������\n���챻�ȹ��ˣ�����ô�����أ�\n",this_object());
                }
                return 1;
        }
        else
        {
                message_vision("$N��ͷҡ�����˹�һ�㣬��������ʲô����ȱ������ȱ�Ǹ�ʲô����ȸ��������\n",this_object());     
                return 0;
        }
}     

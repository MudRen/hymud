#include <ansi.h>
//inherit NPC;
inherit NPC;

//
void create()
{
        set_name("����·",({"fishman wang","fishman","wang"}));
        set("title","һ����");
        set("long","�������Ϊ�����ƺ�����˼�飬����·�ı��£������ܴӸ����������������������\n");
        set("gender","����");
        set("age",42);
                
        set("combat_exp",2500000);  
        set("attitude", "friendly");
        
        set("class","beggar");
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 160);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("staff",150);
                        
                 set("chat_chance_combat", 100);
         set("chat_msg_combat", ({

            (: perform_action, "staff.tianxiawugou" :),
            }) ); 
        
        
        set("inquiry", ([
                "������" :      "ʲô�����㣬û��˵����\n",
                "������" :      "�����㰡���ٺ٣�����֪����ô���������ض�����ͺ������\n",
                "���" :        "������ú���򾣬����������ô������������������أ��ⲻ�����ҵ�����ô��\n",
                "���" :        "�ţ������ҵ������Ͳųɣ�ʮ���ƽ���˵�����͸һ�ѡ�\n",
                "bait" :        "������ú���򾣬����������ô������������������أ��ⲻ�����ҵ�����ô��\n",
                "fishpole" :    "�ţ������ҵ������Ͳųɣ�ʮ���ƽ���˵�����͸һ�ѡ�\n",
                "��С·" :      "С·���ҵ�˫��̥�ܵܣ�Ҳ�Ǹ���򣬲������������ӱ��Ҳ�Զ�ˡ�\n",    
        ]));
        
        set("death_msg",CYN"\n$N̾����˵������������ȥ��һ���㡣�� \n"NOR);
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n����·�е������˰���ɱ����������\n",
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "����·���������˵����������ܴ�����ص���������\n",
        }) );                   
        
   
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/staff")->wield();  
    
}  
int accept_object(object who, object ob)
{
        object fishpole;
        
        if (ob->value()>=100000) {
                command("grin "+who->get_id());
                command("say �ðɣ��Ҿ͸һ��");
                fishpole=new(__DIR__"obj/staff");
                message_vision("$N��һ��װ������͵Ĵ����ӣ��������һ���Ӹ��㡣\n",this_object());
                if (fishpole) fishpole->move(who);
                return 1;               
        }
        return 0;
}       

#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{
        set_name("��С·",({"fishman wang","fishman","wang"}));
        set("title","����һ��");
        set("long","��С·�Ǵ������������ˣ������������ֺǺǵģ�����ʱ���þ��գ����Ե���
����ŽС�����һ�桱����\n"); 
        set("gender","����");
        set("age",42);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("class","beggar");

        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",90);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        set("inquiry", ([
                "������" :      "ʲô�����㣬û��˵����\n",
                "������" :      "�����㰡��ֻ��������ظ������ܵ�������\n",
                "���" :        "����ͬ������ò�ͬ�����������Ҫ��һ�֣�\n",
                "���" :        "�Լ�ȥ��һ���������׵ġ�\n",
                "bait" :        "����ͬ������ò�ͬ�����������Ҫ��һ�֣�\n",
                "fishpole" :    "�Լ�ȥ��һ���������׵ġ�\n",
                "�����" :      "������ҶԵط��ˣ��⸽���ݵ�����кܶ࣬���Լ�ȥ�ھͳ��ˡ�\n",         
                "����·" :      "��·���ҵ�˫��̥��磬Ҳ�Ǹ����\n",         
        ]));
        
        set("death_msg",CYN"\n$N̾����˵������������ȥ��һ���㡣�� \n"NOR);
        
        set("nb_chat_chance", 100);
           set("nb_chat_msg_combat", ([
                10:     "\n��С·�е������˰���ɱ����������\n",
        ]) );           


        set("chat_chance",1);
        set("chat_msg",({
                "��С·˵������Ҫ����һ�棬����ϸˮ������\n",
        }) );                   
        

        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/staff")->wield();  
        
    
}

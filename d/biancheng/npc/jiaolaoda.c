#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("���ϴ�",({"jiao laoda","jiao","laoda"}));
//      set("title","Ҫ����");
        set("long","���ϴ�����ʦ��������һ��������һ��������ȫ�����������öȹ��ģ�����
����һ���������£�ȫ����ĥ���������е����ϡ�������˫
������������Ҳ����Щ���ˣ�һ˫�������������۾��ѱ��Ӿ��ݵ÷��졣
ÿ����˯��������Ӳ��ľ���ϸ������Լ������ϵ��ϼ�ʱ����Ҳ���뵽��
��ȥ��һ������������û�б�ĵط���ȥ����Ϊ���ĸ�Ҳ���������á�
��\n");
        set("gender","����");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$N�ں޵�˵�����ҵĽ��������ǡ������εá���̫������������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
             
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}

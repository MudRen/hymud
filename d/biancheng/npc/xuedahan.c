#include <ansi.h>
//inherit "/d/taiping/npc/smart_npc";  
inherit NPC;
void create()
{
        set_name("Ѧ��",({"xue dahan","xue","dahan"}));
        set("title","���ֺú�");
        set("long","һ����߰˳ߵı��δ󺺣���򼸺���ƽ����������һ˫���Ȱ�Ĵ��ִ������������Ѹǹ���ϥ�ǣ�����ȧ�Ǹ��ʣ���������
ɨ����Ũü��һ�Ŵ��졣�����ϴ����·���Ȼ�������ƣ���һվ��
�����������ݣ����˿��ź��¡�\n");
        set("gender","����");
        set("age",32);
                
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
        set("class","shaolin");
           set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) );

        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4500000);  
        set("attitude", "friendly");
        
        
        set("death_msg",CYN"\n$NЦ�����һ��Ѫ����ɱ�����������������ĳ��ˡ���ͷ��������\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({
                "Ѧ�󺺻��Ƴ�����������ʮ���µ�ͷ���µ�ͷ��Ѫ��������������Ӣ���ᣬɱ�����ĳ���ͷ������\n",
           }) );                   
        
//        CHAR_D->setup_char(this_object());
//        auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}     

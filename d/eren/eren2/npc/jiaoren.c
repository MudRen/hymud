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


        set("chat_chance",1);
        set("chat_msg",({
                "Ѧ�󺺻��Ƴ�������������ʮ���µ�ͷ���µ�ͷ��Ѫ��������������Ӣ���ᣬɱ�����ĳ���
ͷ������\n",
           }) );                   

        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}     

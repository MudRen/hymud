#include <ansi.h>
#include <command.h>
inherit NPC; 
void create()
{ 
        set_name("����",({"zhang tie","zhang"}));
        set("title",RED"����ӧñ�Ĺٲ�"NOR);
        set("long", "
��������������һ�����֣����������ϣ�ȴֻ��һ������������ġ�
���ĵ���������δ���ʣ����������������С�������ط�����������
��ʲô���������������ǰѵ��뿪�����֡�\n");
        set("age",37);
        set("combat_exp", 3500000);
        set("attitude", "friendly");     
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30); 
        set("inquiry", ([
                 "����": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
                 "tie hen": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
                 "tiehen": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
        ]));
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
        
        ]) );           
        

        set_skill("iron-cloth",150);
                
        setup();
   carry_object(__DIR__"obj/o_cloth3")->wear();
        carry_object(__DIR__"obj/redhat")->wear();
}  
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        return;
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        message_vision(CYN"�������˸���˵��������������¥��ЪϢ�������¿�ȥ��Ժ���ƴ��ֶ�����\n"NOR,ob);
        return;
}       

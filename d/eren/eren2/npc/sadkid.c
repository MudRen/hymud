 inherit NPC;
#include <ansi.h> 
int give_mission(); 
void create()
{
        set_name("С��", ({ "sad kid","kid" }) );
        set("gender", "����");
        set("age", 12);
        set("long",
                "һ��ʮ�������С�������Ʋ��ֵ������﹡�ϡ�\n"
        );
        set("chat_chance", 1);
        set("chat_msg", ({
                "С��˵����С����ô�����ˣ���\n",       
        }) );
        set("inquiry", ([
                "С��" : (: give_mission :),
                "xiaoyan" : (: give_mission :),
        ]));  
        set("combat_exp",1000);
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int give_mission()      {
        object ob;
        ob=this_player();
        if (ob->query("m_success/������")||ob->query("marks/bandit_result")) {
                if (ob->query("marks/bandit_result")==1) {
                        command("say С�����ˣ���Ҳ��������ˡ�");
                        return 1;
                        } else {
                                command("say С�����ˣ���Ҳ��������ˡ�");      
                                return 1;
                        }
                }
        if (!ob->query_temp("eren/bandit_1")) {
                command("say С�����ҵĺ����ѣ��ղ����ǻ������ֱ߶������棬һ�ξͲ����ˡ�");
                ob->set_temp("eren/bandit_1",1);
        } else command ("say �㿴��С���������ܰ����ҵ������Һܵ��ġ�");
        return 1;
   
}       
                        
                        
void init() {
        
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        object flower;
        
        if( !ob || environment(ob) != environment() ) return;
        if (ob->query("m_success/������")) return;
        
        if (ob->query("marks/bandit_result") && !ob->query_temp("eren/kid_result")) {
                command("say С�����ˣ���Ҳ��������ˡ�");      
                message_vision(CYN"$N˵������仨������һ���ڲݵ����ڵ��ģ����˾����ģ�����ȥ�ɡ�\n"NOR,this_object());
                ob->set_temp("eren/kid_result",1);
                flower=new(__DIR__"obj/flower");
                message_vision(CYN"$N����һ�仨��\n"NOR,this_object());
                flower->move(ob);       
        }
        return;
}

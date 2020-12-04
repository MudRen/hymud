#include <ansi.h>
#include <command.h>  
inherit NPC; 
int show_me();
int ask_tie(); 
void create()
{ 
        set_name("�����ѵ�С����",({"redgirl","girl"}));
        set("title","����¥");
        set("long", "�����׺����ѵ�С���һ˫���Ӻ�����ᡣ\n");
        set("age",40);
        set("combat_exp", 7000000);
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",120); 
        set("str",40);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "Τ����" :      (: show_me :),
                "wei qiniang" : (: show_me :),
                "tie hen" :     (: ask_tie :),
                "����" :        (: ask_tie :),
        ]));
        
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
   
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
             
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
        
        }) );    
        
        
        setup();
        
        carry_object(__DIR__"obj/redskirt")->wear();
        carry_object(__DIR__"obj/needle")->wield();
}  
void init(){
        ::init();
        add_action("do_look", "look");
}  
int do_look(string arg) {
        if(arg == "redgirl" || arg == "girl"){
                write("�����׺����ѵ�С���һ˫���Ӻ�����ᡣ\n");
                write("��������Լʮ���ꡣ\n");
                write("�����Ĳ��ֲ��ݣ��书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ\n");
                write("�����������������۷�״̬��\n");
                write("�������ȹ(Red skirt)\n");
                return 1;
        }
   return 0;
} 
int accept_object(object who, object ob)
{
        if( ob->name()==HIG"����"NOR) {
                if (who->query("parrot/��̫ƽ��") && who->query_temp("parrot/ask_wei")) {
                        message_vision("$N˵����ԭ����������ͷ�����ѣ��ղ�ʧ���ˡ��˴���ǽ�ж����Ҳ��Ҵ��⡣��\n",this_object());
                        message_vision("$N˵���������ȥ��������վ�İ��Ӻ�����˵���ҽ���ȥ�ġ�\n",this_object());
                        who->set("parrot/Τ����",1);
                        return 1;
                }                 
                command("say ��λ"+RANK_D->query_respect(who)+"�����������͸������ǰɡ�");
                return 0;
        }        
        return 0;
}   
int show_me()   {
        
        if (this_player()->query("parrot/Τ����"))
                command("say ���ޣ����Ӻ����Ҷ���׷��̫ƽ����ʧ���鱦�����䡣");
        else {
                command("ack "+this_player()->get_id());
                this_object()->set("name","Τ����");
                this_player()->set_temp("parrot/ask_wei",1);
                message_vision("$N˵�����㾹Ȼ֪���ҵ���������������ǰ���ڽ��������꣬��̫���ˡ���\n",this_object());
                message_vision("$N˵����������ֻ������¥һ��Ӧ�ŵ�Ѿͷ����\n",this_object());
        }
        return 1;
}  
int ask_tie()  {
        
        object who;
        who=this_player();
        if (who->query("parrot/Τ����"))
                command("say ���ޣ����Ӻ����Ҷ���׷��̫ƽ����ʧ���鱦�����䡣");
                else
                command("say ���ޣ��ǲ���������������Ҵ仨����λ��ү��");
        return 1;
}          

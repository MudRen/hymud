#include <ansi.h>
inherit NPC; 
int ask_tie();
int paper(); 
void create()
{ 
        set_name("����ͷ",({"gan laotou","gan"}));
        set("long", "
�������������߹Ǹ������������������Ǹ�ʬһ�����Ұ׵��뷢���������Ҳ��
֪��������ˣ�������Ϊ�������°��Ż�¯����������������\n");
        set("title", "ǧ������");
        set("age",70); 
        set("combat_exp", 9000000);
        set("class","swordsman");               
        set("attitude","friendly");
                
        set("fle",200);
        
        set("resistance/gin",30);
        set("resistance/kee",50);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "Τ����" :      (: ask_tie :),
                "wei qiniang" : (: ask_tie :),
                "tie hen" :     (: ask_tie :),
                "����" :        (: ask_tie :),
                "�ϻ׳�" :      (: ask_tie :),
                "̷���ֵ�" :    (: ask_tie :),
                "�δ���" :      (: ask_tie :),
                "���ƹ�":       (: ask_tie :),
                "Ѫū" :        (: ask_tie :),
                "��Ц":         (: ask_tie :),
                "paper":        (: paper :),    
                "ֽ":   (: paper :),  
        ])); 
        
        set("death_msg",CYN"\n$N���һ���������İ��������� \n"NOR);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ͷ�ƺ�û��ע�⵽����������������ϼ������˼��£�����ͷ����һ�ۣ�ת��
ȥ���־����������¡�\n",
        }) );
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        

        
        set("no_busy",10);      

        
        add_temp("apply/damage",110);
        setup();
        carry_object(__DIR__"obj/hammer")->wield();
        carry_object(__DIR__"obj/towel")->wear();
        carry_object("/clone/misc/cloth")->wear();
}  
int ask_tie()  {
        
        message_vision("$Ņ��ͷ�����˿��㣬ָ��ָ�Լ��Ķ��䣬ҡҡͷ�ּ��������ˡ�\n",this_object());
        return 1;
}        
int paper() { 
        if (!this_player()->query("parrot/����ͷ����")) {
                message_vision("$Ņ��ͷ�����˿��㣬ָ��ָ�Լ��Ķ��䣬ҡҡͷ�ּ��������ˡ�\n",this_object());
                return 1;
        }
        message_vision("$N��������ֻ֪�������˽��ҽ�ֽ��ȥ�����ͣ�����һ������"+this_player()->query("name")+"���ˡ���\n",this_object());
        message_vision("$N˵�����Ҳ�ʶ�֣�ֽ��д��ʲô��Ҳ��֪������\n",this_object());
        return 1;
}       

#include <ansi.h>
#include <command.h>

inherit NPC; 
void create()
{ 
        set_name("�ֶ�",({"lin er","lin"}));
        set("title",RED"����ӧñ�Ĺٲ�"NOR);
        set("long", "
��Ц����ʮ���ٲ��������еĸ��֣�����������ʲô��ֻҪ�������й��ģ�������
�����ֻҪ�������ˣ�������ʲô������ʲô��������������������\n");
        
        set("age",37);
        set("combat_exp", 6000000);
        set("attitude", "friendly");     
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30); 
        set("inquiry", ([
                 "����": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
                 "tie hen": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
                 "tiehen": "����ͷ�ͳ���ү�������������Ĵ�����֮һ��",
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
        


        
        setup();
        carry_object(__DIR__"obj/o_cloth3")->wear();
        carry_object(__DIR__"obj/redhat")->wear();
} 
int accept_object(object who, object ob)
{
        if( ob->name()=="̷������ʬ��" || ob->name()=="̷�컢��ʬ��"
                || ob->name()=="̷�챪��ʬ��") {
                command("hmm");
                who->set("parrot/ʬ�������",1);                                 
                call_out("event1",1,who,0);
                return 1;
        }        
        return 0;
}  
string *event1_msg=     ({
        
        CYN"\n  �ֶ�˵�����������ڰ�������\n",
        
        CYN"  �ֶ���ʬ��������ϣ�Ѹ�ٵؿ�ʼ���ʡ������µĲҰ׵�Ƥ���ⷭ��Ѫ�ཬһ
���Ƕ��Ƕ�ӿ�������඼��ȡ��������һ�ԡ�\n"NOR,
        
        CYN"  ��������ľ�������֮�ڣ���������ͷ�����ϸ�ĸ�����Ƕ���İ�֮�ϡ�����
���඼��ɺ�ɫ��������ī֭����������\n"NOR,
        
        CYN"  �ֶ������Ӽ����������һ��˵�������������þ��ƣ��������ǣ��������
�ֶ��룬��ʵ����"NOR+HIM"���Ǿ�����"NOR+CYN"�����Ǿ�����ԭ��������Ī�����ֵܵĶ��Ű�����
Ī�����ֵܵ�����Ϊ��������ħŮ�����ӿ�һս֮�����Ǿ�ֻʣһ�ǣ��༴��
Ī�塣��\n"NOR,
        });  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) 
           || this_object()->is_fighting())        return;
        message_vision(event1_msg[count]+"\n",me);
        if(++count==sizeof(event1_msg))
        {
                message_vision(CYN"  ��������Ҳ������һս֮��û�䣬Ī�������±���һ�����о޵���ȴ������
��ǰΪ"NOR+WHT"����"+CYN"���ܣ������ڴ��Ρ���\n\n"NOR,this_object(),me);
                return;
        }
        else call_out("event1",2,me,count);
        return ;
} 
/*
void init() {
        
        object ob;
        ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() || ob->is_fighting()) return;
        call_out("ask_question_1",1,ob); 
}
*/   
#include <ansi.h>
#include <command.h>

inherit NPC; 
void create()
{ 
        set_name("�ƴ�",({"tang da","tang"}));
        set("title",RED"����ӧñ�Ĺٲ�"NOR);
        set("long", "�ƴ�������ţ��ǳ�Ц���¾���ҩ���������֮һ������ʲô����ֻҪ����������
�����֣������ܹ��ֱ�ó���\n");
        set("age",47);
        set("combat_exp", 6000000);
        set("attitude", "friendly");     
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30); 
        set("inquiry", ([
                "������" : "������ԭ������˫���콶���䣬����ѪҺ����������������һ����ҩ��
ȴ���Բ��Ƕ�ҩ��",
                "red bat" : "������ԭ������˫���콶���䣬����ѪҺ����������������һ����ҩ��
ȴ���Բ��Ƕ�ҩ��",
                "bat" : "������ԭ������˫���콶���䣬����ѪҺ����������������һ����ҩ��
ȴ���Բ��Ƕ�ҩ��",
                 "�۵���" : "�۵������������־��ǲɻ���ඣ������ֻ֣������©���������ˡ�",
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
        

        
        set_skill("iron-cloth",150);

                
        setup();
        carry_object(__DIR__"obj/o_cloth3")->wear();
        carry_object(__DIR__"obj/redhat")->wear();
} 
int accept_object(object who, object ob)
{
        if( ob->name()==HIR"��ʯ"NOR) {
                command("hmm");
                who->set("parrot/��ʯ������",1);                 
                call_out("event1",1,who,0);
                return 1;
        }        
        return 0;
}  
string *event1_msg=     ({
        
        CYN"\n  �ƴ�˵����������Ĳ��Ƕ�ҩ������\n",
        
        CYN"  ������ʯ����ͨ��ʯͷ��ֻ��Ϊ��"NOR+HIR"������"NOR+CYN"��ѪҺ�н����൱ʱ�����Բű��
��Ѫ�����ɫ��\n"NOR, 
        CYN"  ��Ҫ��ʯͷ�������ɫ��������Ҫʱ�䣬���������ѪҺ��������ʯͷ��ֱ����
��"+HIR"������"NOR+CYN"�Ľᾧ���ͷ���ˮ��Ƭ�̣�����ˮ���µ������Ů�ˣ���ʹ��������ҵ�
Ů�ˣ�ֻ��Ҳ�����Լ�������˵�����\n"NOR,
        
        CYN"  ��������ҩ�������������֣���Ψһ�ǵþ�ֻ�С�ǧ��̤����"+HIM"�۵���"NOR+CYN"����֮�Ա�
���ϱ���������Ҹ�Ů��������\n"NOR, 
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) 
                || this_object()->is_fighting())        return;
        message_vision(event1_msg[count]+"\n",me);
        if(++count==sizeof(event1_msg))
        {
                message_vision(CYN"  �����ǣ�"+HIM"�۵���"NOR+CYN"���ڶ���ǰ������"+WHT"����"+CYN"���¡���\n"NOR,this_object(),me);
                return;
        }
        else call_out("event1",1,me,count);
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

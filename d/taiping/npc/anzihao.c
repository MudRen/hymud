#include <ansi.h>
inherit NPC;

int show_me();
int ask_tie(); 
void create()
{ 
        set_name("���Ӻ�",({"an zihao","an"}));
        set("long", "̫ƽ����վ����ة�����Զ���˰�������ϡ�٣������վ���˵�����ߵĹټ�������
��ة���ǰ�ʮ�������յĸ�ĸ�١�\n");
        set("title", "̫ƽ����ة");
        set("nickname", "����ͨ");
        set("age",40);
        
        set("combat_exp", 8000000);
        set("gender","����");   
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("reward_npc", 1);
        set("difficulty", 10); 
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "Τ����" :      (: show_me :),
                "wei qiniang" : (: show_me :),
                "tie hen" :     (: ask_tie :),
                "����" :        (: ask_tie :),
        ]));
                
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n���Ӻ��ȵ������˷��ˣ���Ȼ��ɱ�ٲ����\n",
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "���Ӻ�˵�������հ������Ӻ���ƽ���İ���������ӣ����ܵĺ�����\n",
        }) );  
         

        set_skill("changquan",220);
        setup();
        carry_object(__DIR__"obj/o_cloth")->wear();
        carry_object(__DIR__"obj/sspear")->wield();
}  
int show_me()   {
        if (this_player()->query("parrot/Τ����")) {
                command("say ԭ��������������ģ�������������������ȸ������һ�����������ɡ�");
                call_out("event1",1,this_player(),0);
        }
        else {
                command("consider");
                message_vision("$N˵����Τ�����ֽ�����Τ����ڽ����ϴ��������רɱ��Щ���׼���֮�ˡ���\n",this_object());
                message_vision("$N˵�����������⼸�����������伣����˵�Ѿ������ˣ�����\n",this_object());
        }
        return 1;
}  
int ask_tie()  {
        
        object who;
        who=this_player();
        if (who->query("parrot/Τ����"))
                command("say ���ޣ�Τ������Ҷ���׷��̫ƽ����ʧ���鱦�����䡣");
                else
                command("say �����������������Ĵ�����֮�������顣");
        return 1;
}          
string *event1_msg=     ({
        
        GRN"\n  ���Ӻ���������Բ�˰��̫ƽ����Ψһ�����̵ĵط����ط���Ȼ��С�����Ǹ�
������������֣�ɽ����˵�����ͻ�����������������ĵط������ࡣ�������ϴ�
���飬����һ��ֻ�а�ʮ�����˼ҡ���\n"NOR,
   
        GRN"  ����߻ʵ�Զ������վ��Ψһ�ټҵ���������Ҳ��������ĸ�ĸ�١������Ӻ�Ц
Ц˵������������Ҳֻ������ү�����µ�ʱ�򡣡���ү���䣬������䣬��"+HIG"����ɽ"NOR+GRN"��
��ط���һ�������ġ���\n"NOR,
        
        GRN"  �����û��"+HIG"�����"NOR+GRN"����Ҳ����Ͱ���һ��Ҳ����������û����֪������������ʲ
ô��Ҳû��֪������������ֻ֪��������ǰ��������������ׯ԰����\n"NOR, 
        GRN"  ��һɽ�ݲ��ö�����"+HIG"�����"NOR+GRN"��"+HIG"����ү"NOR+GRN"һֱ������������������Ϊֹ���ƺ�˭��û
��ռ�Ϸ硣��\n"NOR, 
        GRN"  ������ǰ����ͷ������һЩ�������ʱ������������������һ��̫ƽ����ʧ�Ե�
�鱦������Щ�鱦����Դ����ᵽ���С����Χ��Τ��������ڴ����鰵�ã�����
һ������ֱ������ǰ������ס����ɣ������������ǰ��������һ���鱦���ڴ�
�����֣������������������Э����ԭ�򡣡�\n"NOR,
        
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) 
                || this_object()->is_fighting())        return;
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                tell_object(me,GRN"  ��������ү��������⣬�����ϻ���"+HIG"�ϻ׳棬̷���ֵܣ������裬���ƹ�"NOR+GRN"����ֵ
��һ�顣ǰ���վ����Ĵ�����֮һ�Ķ���"+HIG"��Ц"NOR+GRN"ҲͻȻ������������ĺ���������
��С�ġ����пգ�Ҳ��ȥ����¥תת��˵�������ܼ���"+HIG"Ѫū"NOR+GRN"���\n\n"NOR);
                me->set("parrot/���Ӻ�����",1);
                command("addoil "+me->get_id());
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}    

#include <ansi.h>
inherit NPC;

int birdcase(); 
void create()
{
        set_name("���ƹ�",({"old owner","owner"}));
        set("long","ƽ����ջ�����ƹ��������ؿ��Ŵ�����������۾���ı����ȻҲ��ú���֡�\n");
        set("gender","����");
        set("age",62);
    
        set("combat_exp", 1500000);
        set("attitude","friendly");
        
        
        set("death_msg",CYN"\n$N�����������ڣ����ڡ��� \n"NOR);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                }) );
        set("inquiry", ([
                "����" :        "����¥�����һ�����ϣ���һ���Ӷ������˰���\n",
                "����" :  (: birdcase() :),
        ]));
        set("chat_chance",1);
        set("chat_msg",({
                "���ƹ��Ŵ�����������۾���ı����ȻҲ��ú���֡�\n",
                "���ƹ���������Źؿ��ˣ�ԩ��Ұ�������ˣ������˼䡭����\n",           
                "���ƹ�Ŀ��ң���Ŵ��⣬���˺ܾã��Ż�������������һ���ӣ������ڹ��
�ؾص����ˣ�������Ҳ�����ƹ�һ�Ρ���\n",                
        }) );
        
       
        set_skill("iron-cloth",150);
        setup();
        carry_object(__DIR__"obj/yandou");
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", random(20));
}  
int birdcase() {
   object ob,me;
        ob=this_object();
        me=this_player(); 
        message_vision(CYN"     
���ƹ��Ŵ�����������۾���ı����ȻҲ��ú���֣����˺ܾã���
̾�˿������������Ǳ�����ֻ���ģ��ֻ��ã��ֿɰ���ֻҪ�����������ˣ�
���벻������Ȼ��������
���ƹ�������������ϣ��ұ�����˯�ˣ���Ȼ�������ڽУ��ͺ��񡭡���
����һ�����ں���ʱ���������־���һ������������Ҳ����־��Ť����
���ȵ��Ҹϳ���ʱ�����Ѿ����ˣ����úòҡ���\n\n"NOR,ob);
        me->set("parrot/����",1);
        return 1;
}  
        
         

#include <ansi.h>
inherit NPC;

void create()
{
    set_name("����ͷ",({"barber sun","barber","sun"}));
    set("title","ն�ݳ���");
    set("long","
����ͷԭ���︣���Ը�����Ϊ�����дκ���ưѹ˿͵�üë��������
�����⡣�Ӵ˾͵��˸�ն�ݳ����Ĵºš�\n");
        set("gender","����");
        set("age",52);
        
        set("combat_exp",1200000);  
        set("attitude", "friendly");
                
        set("inquiry", ([
                "��ͷ" :        "�͹��������������°ɣ������������\n",
                "haircut" :     "�͹��������������°ɣ������������\n",
        ]));
                
  
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n����ͷ˵�����Ⱳ��û�˹�һ���˰���Ϊʲô����\n",
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "����ͷЦ���е�˵���͹�Ҫ��ͷô��\n",
        }) );                   
 
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object(__DIR__"obj/blade")->wield();  
    
}  
void    init(){
        ::init();
        add_action("do_haircut","sitdown");
}  
int     do_haircut(){
        object sun,me;
        me=this_player();
        
        if (me->is_fighting() || me->is_busy()) 
                return notify_fail("��������æ��\n");
        if (is_busy())
                return notify_fail("����ͷ��æ���ء�\n");
        
        message_vision(CYN"����ͷ����$n������Ҵ�����̾�˿���˵���������ͷ���������ģ�û����ѽ����\n"NOR,this_object(),me);
        return 1;
}  
        
          

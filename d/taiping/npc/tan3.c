#include <ansi.h>
#include <command.h>
inherit NPC; 
void create()
{ 
        set_name("̷�챪",({"tan tianbao","tan"}));
        set("title",YEL"̷�������� ����"NOR);
        set("long", "
̷�������쵱Ȼ��̷��Ҳ�����ǲ����Ǳ���̷�ȵĵ�ϵ�����������Լ�Ҫ��ô˵��
��û���˸һ��ɣ�Ҳû���˷��ϡ�ƴ��ʮ�������������˴�С���ٶ��ԡѪ��ս��
��̷�������족ȷʵ���ڽ���������վס�˽ţ����Ƶ����ǵ��ˣ�������ѱ���
��һ����������\n"); 
        set("age",40);
        set("combat_exp", 7500000);
        set("class","swordsman");               
        set("attitude","friendly");
        set("group","tan");
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N˵���ϴ��Ϊ�ұ���ġ������������� \n"NOR);                
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "̷�챪˵�����㻹�ǿ���ɣ��ϴ������޶��������ˡ���\n",
        ]) );           

        setup();
        carry_object(__DIR__"obj/hat")->wear();
        carry_object(__DIR__"obj/lan_cloth3")->wear();
        if (!random(20)) carry_object(__DIR__"obj/redstone");
}   
        
             

inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ��һƬ���̣����������ߣ�Ҳ��̫Զ���¶���һ����أ���ͷ������һ���
�߸ߵ���ʯ�������ϲ�ɫ�Ѳԣ����ð�������վ�������ɽ��ǰһƬ���ԭ��
�����ű��졣�紵���ݣ����纣���еĲ��ˡ�
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"grassland6",
        ]));
        set("objects", ([
                __DIR__"obj/tomb" : 1,
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1090);
        set("coor/y",290);
        set("coor/z",10);
        set("discussion_shen",1);
        setup();
        //eplace_program(ROOM);
}      
void init()
{
        object xing;
        mixed *current_time;
        
        //current_time=NATURE_D->get_current_time();
        if(xing=present("shen sanniang",this_object()))
        {
                if(random(3)==0)
                {
                   message_vision("�������Ĭ�˺þúþã����˲���ͷ����ת���뿪�ˡ�\n",this_player());
  
                        destruct(xing);
                }
                else if(random(3)==0)
                {
                        message_vision("���������εض�$NЦ��Ц��������һ�����ѣ�ת��Ͳ����ˡ���\n",this_player());
                      
                        destruct(xing);
                }
        }
        else
                if(random(10)==0)
                {
                        xing=new(__DIR__"npc/sanniang");
                        xing->move(this_object());
                        message_vision("�����ﻺ�����˹�����̧ͷ������һ�ۡ���\n",this_player());
                }
                

        
} 
 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ص���");
        set("long", @LONG
����ǰ���߲���Զ�����Ǽ�����Ĺص����������𲢲��������ص���ү��
���ϵĽ��ᶼ�Ѱ��䡣����Ҳ�����ˣ�������񰸵����������ģ����и���˯��ȥ��
��֤�����������Ժ�������ʮ���߹ײģ�Ժ�Ӳ��������Թײ�ֻ�ܵ������š�
�ײı�����ȫ�µģ���ú���������ȴ�ѱ������˺ܶ�ط�����Щ�����Ѿ����ս���
LONG
        );
        set("exits", ([ 
        "southeast": __DIR__"road6",
        "west":         __DIR__"cemetery0",
        ]));
        set("objects", ([
                __DIR__"obj/coffin":    1,
        ]) );
        set("coor/x",-1160);
        set("coor/y",190);
        set("coor/z",0);
        set("tuozi_out",0); 
        setup();
        
}  
void reset(){
        
        object coffin,tuozi;
        
        ::reset();
        
        set("tuozi_out",0);
        
        tuozi=present("ding qiu",this_object());
        
        if (!tuozi) 
        if (coffin=present("coffin",this_object())){
                coffin->set("burnt",0);
                coffin->set("closed",1);
//         coffin->set("long", "�ײı�����ȫ�µģ���ú���������ȴ�ѱ������˺ܶ�ط���\n");
        }
}  
                

 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
������һƬ��ڣ�������Ҷ������������Ҳ������ҹ�����ְ�����������⡣
�ߴ���Ѿ�������衣��ή���ӵİ������ֱ�϶����ɪɪ�����������Ұ���ں���
�������Ƶ������ζ�����ç������չ����������˳��ۣ���צ���ˡ�
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"forest2",
                "southeast":    __DIR__"village",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1050);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "southeast"){
                if (present("bandit", this_object()))
                {
                        another = present("bandit", this_object());
                        return notify_fail(another->name()+"����ס�����·��\n");
                } else if (random(10)>5) {
                        another = new(__DIR__"npc/bandit");
                        another->move(environment(obj));
                        message_vision(HIB"��Ҷ������һ�����죬����һ��������\n"NOR, obj);      
                        return notify_fail(another->name()+"�ȵ���ʲô�˸�˽��������կ����������\n");
                }
        }       
        return 1;
}    

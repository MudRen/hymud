inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ƫ��");
        set("long", @LONG
��ƫ����¥�Ͼ������Ⱥ�����ң��������һ��������ʮ���죬һ���ʮ��С
ʱ���˵�ֵ��������������ģ��������Ⱥ�ĵմ����ӣ����Ǹ�����������������
�������������ܹܹ���ϣ�����������������ҲҪͨ���˲�����¥��
LONG
        );
        set("exits", ([ 
                "up": __DIR__"corridor3",
                "east": __DIR__"hall4",
        ]));
        set("objects", ([
                __DIR__"npc/vguard2":   1,
                __DIR__"npc/vguard3":   1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",320);
        set("coor/z",0);
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string arg) {
        object ob;
        
        ob=present("ma shier",this_object());
        
        if (!ob || me->query("wanma/��¥")) 
                return 1;
        
        if (userp(me))
        if (arg== "up" ) {
                message_vision("$N˵����û�������������룬˭����׼���ڡ���\n",ob);
                return notify_fail("");
        }
        
        return 1;
}

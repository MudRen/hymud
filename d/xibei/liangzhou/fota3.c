//fota3.c

inherit ROOM;

void create()
{
        set("short","������");
        set("long", @LONG
�������˷����Ķ��㣬���﹩����һ����������Ľ������񣬹�̳���Ϻ�
��̴���ͳ�Ʈ������������Ѿ��߹������ݵĳǹأ�ƾ��Զ������·��Ѿ�
�ӽ���տ������ա����ơ�
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "down"          :       __DIR__ "fota2",                
                ])
        );
//      replace_program(ROOM);
        setup();
}


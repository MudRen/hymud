//lroad4.c

inherit ROOM;

void create()
{
        set("short","ɳ��·");
        set("long", @LONG
���ݳǵ����Ľֵ������ʷ�ս�ң������ݳ��ڵ���Ȼƽ���������߷�
����������������ֳ�������,ʮ�����֡� ����������Ͻ������������
�������Ӿӣ����Խ��ϲ�ͬ�������װ�������㶼�ܼ����������㷢�ֻ�
���¹ڲ����ĺ��˾ݶ࣬�����������ݳǵ�����,һ���ܴ�ļ��С��ϱ���
һ������˿��������꣬������һ�ҿ�ջ��
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "east"          :       __DIR__ "center",
                "west"          :       __DIR__ "lroad5",
                "south"         :       __DIR__ "yudian",
                "north"         :       __DIR__ "kezhan",
                ])
        );
//      replace_program(ROOM);
        setup();
}


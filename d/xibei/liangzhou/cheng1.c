//cheng1.c

inherit ROOM;

void create()
{
        set("short","����");
        set("long", @LONG
������Χ�ĳ�ǽ֮��,����ǽ���ɴ�����ʯ����,���ؼ��, �Ƕ��
��.��������λ�ں������ȵ��ʺ�֮��,�������뱱�����嶫����ԭ�ıؾ�
֮·,����������������ݳǽ����˲�ͣ�ؼӹ�������,ʹ����������.
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "madao1",            
                ])
        );
//      replace_program(ROOM);
        setup();
}


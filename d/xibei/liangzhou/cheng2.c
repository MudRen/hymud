//cheng2.c

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
                "north"         :       __DIR__ "madao2",            
                ])
        );
//      replace_program(ROOM);
        setup();
}


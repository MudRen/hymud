//fota2.c

inherit ROOM;

void create()
{
        set("short","������");
        set("long", @LONG
����������խխ��ľ¥��ʰ���������ϣ�ľ��������·���֨֨ѽѽ
������������򿪵�ľ���ͽ���������磬���Ȼ��һ��Զ�볾��������
֮�С�
LONG
        );
        set("exits", ([ 
                "down"          :       __DIR__ "fota1",                
                "up"            :       __DIR__ "fota3",
                ])
        );
//      replace_program(ROOM);
        setup();
}


//dangpu.c

inherit HOCKSHOP;

void create()
{
        set("short","�ɼǵ���");
        set("long", @LONG
�������еĵ���,�ſڵ��������Ʈ��,�����Ȧ������д�Ŷ����һ
��"��"��.��Ϊ�������ңԶ��ԭ�������г������ֵĻ���,���ּ��Żؼ�
,���Ըɴཫ���������ﵱ��,���Ե�������ʮ����¡.
LONG
        );
        set("exits", ([ 
                "north"         :       __DIR__ "center",
                ])
        );
//      replace_program(ROOM);
        setup();
}


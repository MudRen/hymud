// /d/heifeng/cookrm.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ɽկ�ĳ����������˵ĳԺȶ��������������ͷ����
�ġ����������٣�����ͷ������æ��������������Ե��������
���˺������á�
LONG
        );
        set("exits", ([ 
            "west"   : __DIR__"corr02",
]));
        setup();
        replace_program(ROOM);
}
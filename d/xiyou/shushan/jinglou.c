inherit ROOM;


void create()
{
        set("short", "��¥");
        set("long", @LONG
��������ɽ�ľ�����ɽ�书�����ڶ���
�������Բ�û��ʲô̫��Ĺż���������ͯ��
�еĲ��������
LONG
        );

        set("exits", ([
                "west" : __DIR__"square",
        ]));

        set("objects", ([
                __DIR__"npc/jiantong" : 1,
                __DIR__"obj/yijing" : 1,
        ]));

        setup();
       
/*
        replace_program(ROOM);
               set("outdoors", "xx" ); 
*/
            set("no_clean_up", 0); 
}

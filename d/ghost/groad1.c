 inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
·�����ԣ��и�ʽ��������ľ������Щ��֪���Ļ��ݡ���������
�յ�ʱ����ɽ��һ��������������ɽ�����ǲ���Ҳ���������յ�ʱ
��
LONG
        );
        set("exits", ([
                "west" : __DIR__"ghost",
                "southeast" : __DIR__"groad2",
        ]));
        set("objects", ([
                __DIR__"npc/dog" : 1,
        ]));
        set("coor/x",-1160);
        set("coor/y",-100);
        set("coor/z",-20);
        setup();
replace_program(ROOM); 
}     

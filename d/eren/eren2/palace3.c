 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�ź��棬��һ�������ص�������˻�����������Ȼ���ûʣ��ڵ��¾�
��������ûʵ����ã����Ǽ������벻�����¡�����û�д��ӣ������ֱ
�͵��ϸ����Ļ���ûʲô��������������´󷽣������й�֮��
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"palace4",
                "south" : __DIR__"palace2",
                "west" : __DIR__"sideroom",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   

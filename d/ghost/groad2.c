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
                "northwest" : __DIR__"groad1",
                "northeast" : __DIR__"groad3",
        ]));
        set("coor/x",-1150);
        set("coor/y",-110);
        set("coor/z",-20);
        setup();
replace_program(ROOM); 
}      

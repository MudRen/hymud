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
                "southwest" : __DIR__"groad5",
                "north" : __DIR__"house3",
        ]));
        set("coor/x",-1100);
        set("coor/y",-100);
        set("coor/z",-20);
        setup();
replace_program(ROOM); 
}  

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
                "southwest" : __DIR__"groad2",
                "east" : __DIR__"dating",
        ]));
        set("coor/x",-1140);
        set("coor/y",-100);
        set("coor/z",-20);
        setup();
replace_program(ROOM); 
}   

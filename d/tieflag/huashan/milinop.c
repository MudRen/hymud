 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��ľԽ��Խ�࣬��ľ��û���������ȴҲ����������ת����ͷ���ֲ��嶫����
���ˣ������ܿ�ֻ������ǰ��ɫ����һ�����Ѳ�������ʱ��·��ԭ���ö���������
����Ҳ����е����겻����
LONG
        );
    set("exits", ([ 
                "south" : __DIR__"milin1",
            "north" : __DIR__"duanshan",
            "west" : __DIR__"milin",
            "east" : __DIR__"milin1",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-570);
    set("coor/y",-90);
    set("coor/z",-67);
        setup();
    replace_program(ROOM);
}    

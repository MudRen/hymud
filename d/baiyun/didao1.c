 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "�ص�");
        set("long", @LONG
�ص�����ȻҲ����ɭ�����������ͬ�������ˮ�����ԣ�ȴ�����쵽�����á�
�ص��ľ�ͷ���ǵ����š����Ͼ�Ȼû�������ƺ��ƿ��Ϳ��Խ�ȥ��
LONG
           );
        set("exits", 
           ([ 
       "out" : __DIR__"shuidao2",
       "south" : __DIR__"shishi",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}   

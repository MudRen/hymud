 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "�̺�����");
        set("long", @LONG
������ȥ��������ӣ�һƬ���ɣ���������ѷֲ��������˼䡣ɳ̲�����
ϸ����ˮտ����̣����δ������������İ�ĭ�����ź��������ǳ���ʱ����Ȼ����
Щ��������Ʈ������Բ�����ƺ����̽��ޣ�������һ��ƬƽҰ������ͷ��ȴ����
�����Ƶ�Ⱥɽ��ˮ��һ����ª��С���ں�����ҡҡ�λΡ�
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"xiaowu",
       "west" : __DIR__"shatan",
       "east" : __DIR__"shatan",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("outdoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}    

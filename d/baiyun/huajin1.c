 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "�ʻ�С��");
        set("long", @LONG
�̲������ɽ���£������ʻ�С���������Ų�֪�����滨��ݣ��ƺ���������
���ߣ�ʱ���м�ֻ�ɰ���С���ú���ؿ����㣬�߳��������ǻ������������Ի���
���ԣ�����ɽ��δ䣬���һ����ϴ��ǰ���������ϵľ�����ͷ���и���������
��ˮ��
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"shuige",
       "southwest" : __DIR__"tengluoxi",
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

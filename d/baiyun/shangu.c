 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
������ɽ��ɽ���йȣ������ɽȴҲ���ߣ���Ŀ�Ĺˣ�ֻ��������ݣ�����ͬ
һ������Ļ�԰����Ӱҡҷ���Ĺ����ˣ���ľ�ƺ��ļ�������������Σ��ʻ�����
���ţ������ɾ�����ǰǰ�����ȥ�ƺ�������䣬һʱ�䣬���ȵ�·����ʧ�����С�
ɽ���г���ż��������౵����⣬��ֻ���������޵���ˮ֮��������
LONG
           );
        set("exits", 
           ([ 
       "northeast" : __DIR__"longqiu",
       "south" : __DIR__"xiaowu",
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

 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "����Ϫ");
        set("long", @LONG
�������ܣ����澹������϶������һ���˲���������������ߣ��ͽ������ˡ�
ɽ϶��·��й⣬���Ѽ�������������ˮ�����ֱ�ú�������һ�����峺��Ȫˮ��
����ǰ��������Ȫ�����ߣ���Ȼ���֡���������Ȫˮ������������ȴֻ������һ��
�ѿ�ή�˵��������Կɿ���Ҷ�����о������޼��ĺۼ���
LONG
           );
        set("exits", 
           ([ 
       "northwest" : __DIR__"tengluoxi",
       "south" : __DIR__"qingbi",
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

 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "����Ϫ");
        set("long", @LONG
�������������ܰ���һ�����峺��Ȫˮ����������������Ȫ�����ߣ���Ȼ����
һ��������Ȫˮ������������ȴֻ������һ���ѿ�ή�˵��������Կɿ���Ҷ������
�������޼��ĺۼ�������������ǰ���˰��ʱ����ɽ�ƾ���Ļ�Ȼ���ʣ�ɽ�����
�����̣������Ǹ��ô�ô�Ļ�԰����仹��׺��һƬ̨ͤ¥��
LONG
           );
        set("exits", 
           ([ 
       "northeast" : __DIR__"huajin1",
       "southeast" : __DIR__"tengluoxi2",
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

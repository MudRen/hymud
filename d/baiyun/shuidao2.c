 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
���ö��У�������һ�������ĵ���ˮ�������涼��ˮ�������������Σ�������
�̾�ײ��ʯ�ڣ��������ĵط���û�У���ֻ�о�����Ϣ���̣������ƺ�Ҫը������
ʹ���쳣�������ε���ͷ���Ϸ��и�ʯ�ţ�������������ֱ������ģ�Ҳ�ܲ��ˣ�
һ���Ӵ���ȥ�� ���澹������ʯ�����ɵĵص�����һ��ˮҲû�С�
LONG
           );
        set("exits", 
           ([ 
       "up" : __DIR__"shuidao1",
       "enter" : __DIR__"didao1",
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

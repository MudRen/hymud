 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������У��뾭��һ���������Ƶľ����ţ��������ݷ���һ���չ��У�Ψ��Զ
Զ��ȥ��һյ�ƻ��������֣���������ԶԶ�������߸ߵ͵Ͷ���������ɫһ������
���ģ�է����һ������һ���ƺ�����������һ�㣬��翲������߹������ţ���Զ
������һ���ݷ��ڳ����ϵ��������ߵ�ˮ��
LONG
           );
        set("exits", 
           ([ 
       "down" : __DIR__"hetang",
       "southeast" : __DIR__"shuige",
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

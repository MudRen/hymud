 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
ˮ��ʵ�ʲ�������������ȥȴ�ܿտ�����Ȼһ������ʮ���ˣ���վ��������
�ϻ��ף��еĴ���ׯ�ϻ������Ϲ��¹ڣ��е�ȴֻ�������������ż����ۣ����
��̬�ȶ������ɣ����������죬�쳾�е����з��գ��ƺ���������ˮ��֮�⡣
LONG
           );
        set("exits", 
           ([ 
       "northwest" : __DIR__"9bridge",
       "south" : __DIR__"huajin1",
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
